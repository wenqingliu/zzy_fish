#include "CustomFile.h"
#include <stdio.h> 

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif
bool CustomFile::writeFile(string& content,const std::string& fullPath,const string& fileName)
{
	//createDirectory(fullPath.c_str());//检查路径,没有则创建
	FILE* file = fopen((fullPath + fileName).c_str(),"w");
	if(file){
		fprintf(file,"%s",content.c_str());
		fclose(file);
		return true;
	}
	return false;
}

bool CustomFile::createDirectory(const string& dirname)
{
	#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	DIR *pDir = NULL;
	pDir = opendir(dirname.c_str());
	if (!pDir)
	{
		return mkdir(dirname.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
	}
	#else
		if ((GetFileAttributesA(dirname.c_str())) == INVALID_FILE_ATTRIBUTES)
		{
			return CreateDirectoryA(dirname.c_str(), 0);
		}
	#endif
	return false;
}