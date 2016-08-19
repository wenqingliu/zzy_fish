#include "CommonFiles/WGPlatform.h"
#include "CommonFiles/WGPlatformObserver.h"
#include <string>
#include <android/log.h>

static jclass s_WGPlatformClass;
static jclass s_LoginRetClass;

WGPlatform::WGPlatform() :
		m_pObserver(NULL),
		needDelayLoginNotify(false),
		needDelayWakeupNotify(false),
		m_nPermissions(0){
		m_pVM = NULL;
}
WGPlatform::~WGPlatform() {
}
//-----------------------------------------------------------------------------
void WGPlatform::init(JavaVM* pVM) {
	m_pVM = pVM;
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jclass cls = env->FindClass("com/tencent/msdk/api/WGPlatform");
	s_WGPlatformClass = (jclass) env->NewGlobalRef(cls);
	env->DeleteLocalRef(cls);
	cls = env->FindClass("com/tencent/msdk/api/LoginRet");
	s_LoginRetClass = (jclass) env->NewGlobalRef(cls);
	env->DeleteLocalRef(cls);
}
void WGPlatform::setVM(JavaVM* pVM) {
}

JavaVM* WGPlatform::getVm() {
	return m_pVM;
}

void WGPlatform::WGSetObserver(WGPlatformObserver* pNotify) {
	LOGD("WGPlatform::WGSetObserver needDelayWakeupNotify %d",
			needDelayWakeupNotify);
	LOGD("WGPlatform::WGSetObserver needDelayLoginNotify %d",
			needDelayLoginNotify);

	if (pNotify == NULL) {
		LOGI("pNotify is NULL%s", "");
		return;
	}
	m_pObserver = pNotify;

	//上次没有回调到的m_lastWakeup延迟回调一下
	if (needDelayWakeupNotify) {
		LOGD("WGPlatform::WGSetObserver wakeup delay notify openid:%s",
				m_lastWakeup.open_id.c_str());
		m_pObserver->OnWakeupNotify(m_lastWakeup);
		needDelayWakeupNotify = false;
	} else if (needDelayLoginNotify) {
		for (int i = 0; i < m_lastLoginRet.token.size(); i++) {
			LOGD(
					"WGPlatform::WGSetObserver login delay notify type:%d; value:%s",
					m_lastLoginRet.token.at(i).type, m_lastLoginRet.token.at(i).value.c_str());
		}
		m_pObserver->OnLoginNotify(m_lastLoginRet);
		needDelayLoginNotify = false;
	}
}

WGPlatform * WGPlatform::m_pInst;
WGPlatform* WGPlatform::GetInstance() {
	if (m_pInst == NULL) {
		m_pInst = new WGPlatform();
	}
	return m_pInst;
}

void WGPlatform::WGLogin(ePlatform platform) {
	LOGD("WGPlatform::WGLogin platform:%d", (int)platform);

	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);

	jclass jCommonClass = env->FindClass("com/tencent/msdk/consts/EPlatform");
	jmethodID jGetEnumMethod = env->GetStaticMethodID(jCommonClass, "getEnum",
			"(I)Lcom/tencent/msdk/consts/EPlatform;");
	jobject jEnumObj = env->CallStaticObjectMethod(jCommonClass, jGetEnumMethod,
			(int) platform);

	jmethodID WGLogin = env->GetStaticMethodID(s_WGPlatformClass, "WGLogin",
			"(Lcom/tencent/msdk/consts/EPlatform;)V");
	env->CallStaticVoidMethod(s_WGPlatformClass, WGLogin, jEnumObj);

	env->DeleteLocalRef(jCommonClass);
	env->DeleteLocalRef(jEnumObj);
}

bool WGPlatform::WGSwitchUser(bool switchToLaunchUser) {
	LOGD("WGPlatform::WGLogin platform:%d", switchToLaunchUser);
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method = env->GetStaticMethodID(s_WGPlatformClass,
				"WGSwitchUser", "(Z)Z");
	return env->CallStaticBooleanMethod(s_WGPlatformClass, method, switchToLaunchUser);
}

//-----------------------------------------------------------------------------
bool WGPlatform::WGLogout() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID WGLogout = env->GetStaticMethodID(s_WGPlatformClass, "WGLogout",
			"()Z");
	return env->CallStaticBooleanMethod(s_WGPlatformClass, WGLogout);
}

bool WGPlatform::WGQueryQQMyInfo() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);

	jmethodID WGQueryQQMyInfo = env->GetStaticMethodID(s_WGPlatformClass,
			"WGQueryQQMyInfo", "()Z");
	bool ret = env->CallStaticBooleanMethod(s_WGPlatformClass,
			WGQueryQQMyInfo);
	return ret;
}

bool WGPlatform::WGQueryWXMyInfo() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);

	jmethodID WGQueryWXMyInfo = env->GetStaticMethodID(s_WGPlatformClass,
			"WGQueryWXMyInfo", "()Z");
	bool ret = env->CallStaticBooleanMethod(s_WGPlatformClass,
			WGQueryWXMyInfo);

	return ret;
}

int WGPlatform::WGGetLoginRecord(LoginRet& lr) {
	JNIEnv* env;
	m_pVM->AttachCurrentThread(&env, NULL);

	jboolean isCopy;
	jmethodID WGGetLoginRecord = env->GetStaticMethodID(s_WGPlatformClass,
			"WGGetLoginRecord", "(Lcom/tencent/msdk/api/LoginRet;)I");
	jmethodID lrConstruct = env->GetMethodID(s_LoginRetClass, "<init>", "()V");
	jobject jLoginRet = env->NewObject(s_LoginRetClass, lrConstruct);
	env->CallStaticIntMethod(s_WGPlatformClass, WGGetLoginRecord, jLoginRet);

	JniGetAndSetStringField(pf, "pf", s_LoginRetClass, jLoginRet, lr);
	JniGetAndSetStringField(pf_key, "pf_key", s_LoginRetClass, jLoginRet, lr);
	JniGetAndSetIntField(flag, "flag", s_LoginRetClass, jLoginRet, lr);
	JniGetAndSetStringField(desc, "desc", s_LoginRetClass, jLoginRet, lr);
	JniGetAndSetIntField(platform, "platform", s_LoginRetClass, jLoginRet, lr);
	JniGetAndSetStringField(open_id, "open_id", s_LoginRetClass, jLoginRet, lr);

	// Vector
	jfieldID jVectorFieldId = env->GetFieldID(s_LoginRetClass, "token",
			"Ljava/util/Vector;");
	jobject jTokenVectorObject = env->GetObjectField(jLoginRet, jVectorFieldId);
	jclass jVectorClass = env->GetObjectClass(jTokenVectorObject);

	jmethodID jVectorSizeMethod = env->GetMethodID(jVectorClass, "size", "()I");
	jmethodID jVectorGetMethod = env->GetMethodID(jVectorClass, "get",
			"(I)Ljava/lang/Object;");
	jint jLength = env->CallIntMethod(jTokenVectorObject, jVectorSizeMethod);

	for (int i = 0; i < jLength; i++) {
		TokenRet cTokenRet;
		jobject jTokenRetObject = env->CallObjectMethod(jTokenVectorObject,
				jVectorGetMethod, i);
		jclass jTokenRetClass = env->GetObjectClass(jTokenRetObject);

		JniGetAndSetIntField(type, "type", jTokenRetClass, jTokenRetObject,
				cTokenRet);
		JniGetAndSetStringField(value, "value", jTokenRetClass, jTokenRetObject,
				cTokenRet);
		JniGetAndSetLongField(expiration, "expiration", jTokenRetClass,
				jTokenRetObject, cTokenRet)

		lr.token.push_back(cTokenRet);

		env->DeleteLocalRef(jTokenRetObject);
		env->DeleteLocalRef(jTokenRetClass);
	}
	JniGetAndSetStringField(user_id, "user_id", s_LoginRetClass, jLoginRet, lr);

	env->DeleteLocalRef(jLoginRet);
	env->DeleteLocalRef(jTokenVectorObject);
	env->DeleteLocalRef(jVectorClass);
	return lr.platform;
}

WGPlatformObserver* WGPlatform::GetObserver() const {
	return m_pObserver;
}

void WGPlatform::WGSetPermission(int permissions) {
	JNIEnv * env;
	m_pVM->AttachCurrentThread(&env, NULL);

	jmethodID WGSetPermission = env->GetStaticMethodID(s_WGPlatformClass,
			"WGSetPermission", "(I)V");
	env->CallStaticVoidMethod(s_WGPlatformClass, WGSetPermission, permissions);
}


const std::string WGPlatform::WGGetVersion() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID jWGGetVersionMethod = env->GetStaticMethodID(s_WGPlatformClass,
			"WGGetVersion", "()Ljava/lang/String;");
	jstring jVersion = (jstring) env->CallStaticObjectMethod(s_WGPlatformClass,
			jWGGetVersionMethod);

	jboolean isCopy;
	const char* cVersion = env->GetStringUTFChars(jVersion, &isCopy);
	std::string cVersionStr = cVersion;
	env->ReleaseStringUTFChars(jVersion, cVersion);
	env->DeleteLocalRef(jVersion);
	return cVersionStr;
}

void WGPlatform::setWakeup(WakeupRet& wakeup) {

	this->m_lastWakeup = wakeup;

	needDelayWakeupNotify = true;
	LOGD("WGPlatform::setWakeup %d", needDelayWakeupNotify);
}

void WGPlatform::setLoginRet(LoginRet& lr) {
	this->m_lastLoginRet = lr;
	needDelayLoginNotify = true;
	LOGD("WGPlatform::setLoginRet %d", needDelayLoginNotify);
}

LoginRet& WGPlatform::getLoginRet() {
	return this->m_lastLoginRet;
}

WakeupRet& WGPlatform::getWakeup() {
	return m_lastWakeup;
}

void WGPlatform::WGEnableCrashReport(bool isRdmEnable, bool isMtaEnable) {
	LOGD("WGPlatform::WGEnableCrashReport bEnable rdm: %d; mta: %d;",
			isRdmEnable, isMtaEnable);

	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method = env->GetStaticMethodID(s_WGPlatformClass,
			"WGEnableCrashReport", "(ZZ)V");

	env->CallStaticVoidMethod(s_WGPlatformClass, method, isRdmEnable,
			isMtaEnable);
}

const std::string WGPlatform::WGGetChannelId() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method = env->GetStaticMethodID(s_WGPlatformClass,
			"WGGetChannelId", "()Ljava/lang/String;");

	jstring jChannelId = (jstring) env->CallStaticObjectMethod(
			s_WGPlatformClass, method);

	jboolean isCopy;
	const char* cChannel = env->GetStringUTFChars(jChannelId, &isCopy);
	std::string cChannelStr = cChannel;
	env->ReleaseStringUTFChars(jChannelId, cChannel);
	env->DeleteLocalRef(jChannelId);

	return cChannelStr;
}

const std::string WGPlatform::WGGetPlatformAPPVersion(ePlatform platform) {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jclass WGCommonClass = env->FindClass("com/tencent/msdk/consts/EPlatform");
	jmethodID getEnum = env->GetStaticMethodID(WGCommonClass, "getEnum",
					"(I)Lcom/tencent/msdk/consts/EPlatform;");
	jobject enumObj = env->CallStaticObjectMethod(WGCommonClass, getEnum,
					(int) platform);
	jmethodID method = env->GetStaticMethodID(s_WGPlatformClass,
			"WGGetPlatformAPPVersion", "(Lcom/tencent/msdk/consts/EPlatform;)Ljava/lang/String;");

	jstring jAPPVersion = (jstring) env->CallStaticObjectMethod(
			s_WGPlatformClass, method,enumObj);

	jboolean isCopy;
	const char* cAPPVersion = env->GetStringUTFChars(jAPPVersion, &isCopy);
	std::string cAPPVersionStr = cAPPVersion;
	env->ReleaseStringUTFChars(jAPPVersion, cAPPVersion);
	env->DeleteLocalRef(jAPPVersion);

	return cAPPVersionStr;
}

bool WGPlatform::WGIsPlatformInstalled(ePlatform platform) {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);

	jclass WGCommonClass = env->FindClass("com/tencent/msdk/consts/EPlatform");
	jmethodID getEnum = env->GetStaticMethodID(WGCommonClass, "getEnum",
			"(I)Lcom/tencent/msdk/consts/EPlatform;");
	jobject enumObj = env->CallStaticObjectMethod(WGCommonClass, getEnum,
			(int) platform);

	jboolean result;
	jmethodID isInstalled;
	isInstalled = env->GetStaticMethodID(s_WGPlatformClass,
			"WGIsPlatformInstalled", "(Lcom/tencent/msdk/consts/EPlatform;)Z");

	result = env->CallStaticBooleanMethod(s_WGPlatformClass, isInstalled,
			enumObj);
	return result;
}

bool WGPlatform::WGIsPlatformSupportApi(ePlatform platform) {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jclass WGCommonClass = env->FindClass("com/tencent/msdk/consts/EPlatform");
	jmethodID getEnum = env->GetStaticMethodID(WGCommonClass, "getEnum",
			"(I)Lcom/tencent/msdk/consts/EPlatform;");
	jobject enumObj = env->CallStaticObjectMethod(WGCommonClass, getEnum,
			(int) platform);

	jboolean result;
	jmethodID isSupportApi;
	isSupportApi = env->GetStaticMethodID(s_WGPlatformClass,
			"WGIsPlatformSupportApi", "(Lcom/tencent/msdk/consts/EPlatform;)Z");
	result = env->CallStaticBooleanMethod(s_WGPlatformClass, isSupportApi,
			enumObj);
	env->DeleteLocalRef(WGCommonClass);
	env->DeleteLocalRef(enumObj);
	return (bool) result;
}

const std::string WGPlatform::WGGetRegisterChannelId() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method = env->GetStaticMethodID(s_WGPlatformClass,
			"WGGetRegisterChannelId", "()Ljava/lang/String;");

	jstring jRegChannelId = (jstring) env->CallStaticObjectMethod(
			s_WGPlatformClass, method);

	jboolean isCopy;
	const char* cRegChannel = env->GetStringUTFChars(jRegChannelId, &isCopy);
	std::string cRegChannelStr = cRegChannel;
	env->ReleaseStringUTFChars(jRegChannelId, cRegChannel);
	env->DeleteLocalRef(jRegChannelId);
	return cRegChannelStr;
}

void WGPlatform::WGRefreshWXToken() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method;
	method = env->GetStaticMethodID(s_WGPlatformClass, "WGRefreshWXToken",
			"()V");
	env->CallStaticVoidMethod(s_WGPlatformClass, method);
}

const std::string WGPlatform::WGGetPf(unsigned char * cGameCustomInfo) {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method= env->GetStaticMethodID(s_WGPlatformClass, "WGGetPf",
			"(Ljava/lang/String;)Ljava/lang/String;");
	jstring jGameCustomInfo = env->NewStringUTF((char const*)cGameCustomInfo);
	jstring jPf = (jstring) env->CallStaticObjectMethod(s_WGPlatformClass,
			method, jGameCustomInfo);

	jboolean isCopy;
	const char* cPf = env->GetStringUTFChars(jPf, &isCopy);
	std::string cPfStr = cPf;
	env->DeleteLocalRef(jGameCustomInfo);
	env->ReleaseStringUTFChars(jPf, cPf);
	env->DeleteLocalRef(jPf);
	return cPfStr;
}

const std::string WGPlatform::WGGetPfKey() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method;
	method = env->GetStaticMethodID(s_WGPlatformClass, "WGGetPfKey",
			"()Ljava/lang/String;");

	jstring jPfKey = (jstring) env->CallStaticObjectMethod(s_WGPlatformClass,
			method);

	jboolean isCopy;
	const char* cPfKey = env->GetStringUTFChars(jPfKey, &isCopy);
	std::string cPfKeyStr = cPfKey;
	env->ReleaseStringUTFChars(jPfKey, cPfKey);
	env->DeleteLocalRef(jPfKey);
	return cPfKeyStr;
}

bool WGPlatform::WGCheckApiSupport(eApiName apiName) {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID WGCheckApiSupport = env->GetStaticMethodID(s_WGPlatformClass,
			"WGCheckApiSupport", "(Lcom/tencent/msdk/qq/ApiName;)Z");

	jclass jApiNameClz = env->FindClass("com/tencent/msdk/qq/ApiName");
	jmethodID jApiNameGetEnumMethod = env->GetStaticMethodID(jApiNameClz,
			"getEnum", "(I)Lcom/tencent/msdk/qq/ApiName;");
	jobject jApiName = env->CallStaticObjectMethod(jApiNameClz,
			jApiNameGetEnumMethod, (int) apiName);
	bool rtn = (bool) env->CallStaticBooleanMethod(s_WGPlatformClass,
			WGCheckApiSupport, jApiName);

	env->DeleteLocalRef(jApiNameClz);
	env->DeleteLocalRef(jApiName);
	return rtn;
}
void WGPlatform::WGLogPlatformSDKVersion() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method = env->GetStaticMethodID(s_WGPlatformClass,
			"WGLogPlatformSDKVersion", "()V");
	env->CallStaticVoidMethod(s_WGPlatformClass, method);
}

void WGPlatform::WGLoginWithLocalInfo() {
	JNIEnv *env;
	m_pVM->AttachCurrentThread(&env, NULL);
	jmethodID method = env->GetStaticMethodID(s_WGPlatformClass, "WGLoginWithLocalInfo", "()V");
	env->CallStaticVoidMethod(s_WGPlatformClass, method);
}

