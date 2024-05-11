#include"FileHelper.h"

bool FileHelper::CopyTo(char* src, char* to) {
	//read
	SysFile rf;
	char* file = rf.Open(src, rf.Read_Binary).ReadFile();
	size_t size = rf.Len();
	rf.Close();
	
	//file not found
	if (file == NULL)
		return false;
	
	//make folder
	if (Helper::FileExists(to)) {
		CreateDir(Helper::strTochr(Helper::BasePath(to)));
	}

	//write
	SysFile wf;
	wf.Open(to, wf.Write_Binary);
	wf.WriteFile(file, size);
	wf.Close();

	return true;
}

void FileHelper::CreateDir(char* src) {
	_mkdir(src);
}