#include"FileHelper.h"

bool FileHelper::CopyTo(char* src, char* to) {
	SysFile rf;
	
	char* file = rf.Open(src, rf.Read_Binary).ReadFile();
	size_t size = rf.Len();
	rf.Close();
	
	if (file == NULL)
		return false;

	SysFile wf;
	wf.Open(to, wf.Write_Binary).WriteFile(file);
	wf.Close();

	return true;
}