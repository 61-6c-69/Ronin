#include"Process.h"

bool Process::Open(char* path, Process::OpenMode open_mode){
	this->pipe = _popen(path, open_mode == Process::OpenMode::READ ? "r" : "w");
	if (this->pipe == NULL) {
		return false;
	}
	return false;
}

void Process::Write(char* command) {
	fputs(command, this->pipe);
}

bool Process::Close() {
	return _pclose(this->pipe);
}

void Process::Recv(void(*callback)(char*)) {
	char buf[PROCESS_OUTPUT_BUFF_SIZE];

	while (fgets(buf, PROCESS_OUTPUT_BUFF_SIZE, this->pipe) != NULL) {
		callback(buf);
	}
}