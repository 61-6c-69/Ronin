#pragma once
#include<vector>

std::vector<char*> commands_array = {
	"/listen  - [ -p(listen on port: 8081) ]",
	"/client  - [ -c(client id), -a(list all clients) ]",
	"/build   - [ -p(platform: win32), -h(connection host: 127.0.0.1:8081), -a(show all platforms) ]",
	"/status",
	"/info",
	"/help",
	"/exit",
};