
#include <wtypes.h>
#include <winbase.h>
//#include "Server.h"
#include "ServerMain.h"
int main (int argc, char *argv[]) {
	HMODULE hDll = LoadLibrary("videoserver_dll.dll");
	if (hDll == NULL){
		std::wcout<<L"could not load server.dll\n";
	}
	else {
		StartServerFuncType startServer;
		startServer = (StartServerFuncType) GetProcAddress(hDll, "startServer");
		if (startServer == NULL) {
			std::wcout<<L"Could not start server"<<" error code= "<<GetLastError()<<"\n";
		}
		else {
			startServer();
			for (;;)
			{
			}
		}
	}
	return 0;
}
