#ifndef	CMD_NOTIFY_DEFINE_H
#define	CMD_NOTIFY_DEFINE_H


//网络检测通知
static const char ccNd_CheckSocketResult[]      = "ccNd_CheckSocketResult";
static const char ccNd_CheckVersionResult[]     = "ccNd_CheckVersionResult";
static const char ccNd_CheckVersionUpdate[]     = "ccNd_CheckVersionUpdate";


//新添加socket recv通知
static const char ccNd_Socket_RecvPacketNotify[]   = "ccNd_Socket_RecvPacketNotify";          //socket recv 通知


/****************************************************************************************************/
//已使用

//MARK:平台登陆通知
static const char ccNd_Platform_LogonResult[]       = "ccNd_Platform_LogonResult";  // 平台登陆响应通知

//MARK:大厅登陆
static const char ccNd_Hall_Sub_MB_LogonResult[]    = "ccNd_Hall_Sub_MB_LogonResult";           //登陆通知
static const char ccNd_Hall_Sub_GR_ConfigList[]     = "ccNd_Hall_Sub_GR_ConfigList";            //列表配置

//MARK:房间登陆
static const char ccNd_Hall_Sub_GR_LogonResult[]    = "ccNd_Hall_Sub_GR_LogonResult";           //登陆结果
static const char ccNd_Hall_Sub_GR_ConfigRoom[]     = "ccNd_Hall_Sub_GR_ConfigRoom";            //房间配置

//用户处理
static const char ccNd_Hall_Sub_GR_UserEnter[]      = "ccNd_Hall_Sub_GR_UserEnter";				//用户进入
static const char ccNd_Hall_Sub_GR_UserStatus[]     = "ccNd_Hall_Sub_GR_UserStatus";            //用户状态
static const char ccNd_Hall_Sub_GR_UserScore[]     = "ccNd_Hall_Sub_GR_UserScore";            //用户分数

//MARK:用户道具
static const char ccNd_Hall_Sub_GR_UserProps[]      = "ccNd_Hall_Sub_GR_UserProps";             //用户道具
static const char ccNd_GP_QueryIndividual[]         = "ccNd_GP_QueryIndividual";                //个人资料
static const char ccNd_GP_WrapIndividual[]          = "ccNd_GP_WrapIndividual";                 //包裹资料

//游戏消息
static const char ccNd_GAME_Sub_CM_Message[]		= "ccNd_GAME_Sub_CM_Message";				//游戏消息
static const char ccNd_BANK_Sub_CM_Message[]		= "ccNd_BANK_Sub_CM_Message";				//银行消息
static const char ccNd_GAME_Sub_CM_SceneMessage[]	= "ccNd_GAME_Sub_CM_SceneMessage";			//游戏场景消息

//聊天消息
static const char ccNd_Chat_Sub_GR_ChatWord[]			= "ccNd_Chat_Sub_GR_ChatWord";            //聊天
static const char ccNd_Chat_Sub_GR_ChatExpression[]     = "ccNd_Chat_Sub_GR_ChatExpression";            //表情


//下面未修改
//MARK:系统公告
static const char ccNd_Main_Sub_CM_System[]       = "ccNd_Main_Sub_CM_System";                  //系统公告
static const char ccNd_Main_Sub_CM_CloseGame[]    = "ccNd_Main_Sub_CM_CloseGame";               //关闭游戏
static const char ccNd_Main_Sub_CM_CloseRoom[]    = "ccNd_Main_Sub_CM_CloseRoom";               //关闭房间
static const char ccNd_Main_Sub_CM_CloseLink[]    = "ccNd_Main_Sub_CM_CloseLink";               //关闭连接

//MARK:道具通知
static const char ccNd_Main_Sub_GR_PropertySuccess[] = "ccNd_Main_Sub_GR_PropertySuccess";      //道具成功
static const char ccNd_Main_Sub_GR_PropertyFailure[] = "ccNd_Main_Sub_GR_PropertyFailure";      //道具失败
static const char ccNd_Main_Sub_GR_PropertyBuy[]     = "ccNd_Main_Sub_GR_PropertyBuy";          //道具购买
static const char ccNd_Room_Sub_GR_PropertyTrumpet[] = "ccNd_Room_Sub_GR_PropertyTrumpet";      //喇叭消息

static const char ccNd_CloseRoom[]                = "ccNd_CloseRoom";                           //关闭房间
static const char ccNd_CloseSocket[]              = "ccNd_CloseSocket";                         //关闭socket

//MARK:socket提示
static const char ccNd_Socket_Success[]         = "ccNd_Socket_Success";                        //连接成功
static const char ccNd_Socket_Failure[]         = "ccNd_Socket_Failure";                        //连接失败
static const char ccNd_Socket_ConnectResult[]   = "ccNd_Socket_ConnectResult";                  //连接结果

static const char ccNd_Socket_CloseLink[]       = "ccNd_Socket_CloseLink";                      //超时关闭
static const char ccNd_Socket_OutTime[]         = "ccNd_socket_OutTime";                        //超时退出
static const char ccNd_Socket_Disconnect[]      = "ccNd_Socket_Disconnect";                     //网络断开

//new
static const char ccNd_FrameSocket_Close[]      = "ccNd_FrameSocket_Close";                     //大厅关闭
static const char ccNd_FrameSocket_SendData[]   = "ccNd_FrameSocket_SendData";                  //消息发送


//-------------------------------------------------------------------------------------------------------------
//请求操作
static const char ccNd_Operate_Result[]         = "ccNd_Operate_Result";                        //操作结果
static const char ccNd_Operate_Result_Click[]   = "ccNd_Operate_Result_Click";                  //结果点击
static const char ccNd_RoomEnterFailure[]       = "ccNd_RoomEnterFailure";                      //进入房间失败
static const char ccNd_RankResult[]             = "ccNd_RankResult";                            //排行榜数据

// AppStore商品结果
static const char ccNd_Shop_AppStore_Get_Info_Result[]   = "ccNd_Shop_AppStore_Get_Info_Result";
static const char ccNd_Shop_AppStore_Buy_Info_Result[]   = "ccNd_Shop_AppStore_Buy_Info_Result";
static const char ccNd_Shop_AppStore_Verify_Result[]     = "ccNd_Shop_AppStore_Verify_Result";

// 银行通知
static const char ccNd_Bank_InsureInfo[] = "ccNd_Bank_InsureInfo"; //银行信息
static const char ccNd_Bank_Result[] = "ccNd_Bank_Result"; //银行存取转账通知

//-------------------------------------------------------------------------------------------------------------
//显示层通知

static const char ccNd_LayerNotify[]   =    "ccNd_LayerNotify";            //页面通知

static const char ccNd_InputLayerComfirm[]   =  "ccNd_InputLayerComfirm";  // 输入框确定
static const char ccNd_InputLayerCancel[] = "ccNd_InputLayerCancel"; // 输入框取消

//MARK:大厅界面刷新
static const char ccNd_Hall_NeedRefreshData[] = "ccNd_Hall_NeedRefreshData"; // 需要刷新
static const char ccNd_Hall_RefreshData[]    = "ccNd_Hall_RefreshData";
static const char ccNd_Hall_LogonSuccess[]    = "ccNd_Hall_LogonSuccess";//这个通知只用于第一次登陆成功后跳转到大厅
static const char ccNd_Hall_RefreshTheViewAfterBack[]    = "ccNd_Hall_RefreshTheViewAfterBack";
static const char ccNd_Hall_EnterRoomFail[]    = "ccNd_Hall_EnterRoomFail";//进入游戏失败

//------------------------------------------------------------------------------------------------------------/

//平台通知
#define ccNd_PlatFormNotify                 "ccNd_PlatFormNotify"













































//操作标识
#define PROCESS_NONE                0       //
#define PROCESS_CHECK_SOCKET        1       //网络检测
#define PROCESS_CHECK_VERSION       2       //版本号检测

#pragma pack()

#endif
















 
 
