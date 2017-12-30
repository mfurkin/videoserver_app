
#include <wtypes.h>
#include <winbase.h>

#include "ServerMain.h"
int main (int argc, char *argv[]) {
	HMODULE hDll = LoadLibrary("videoserver_dll.dll");
	if (hDll == NULL){
		std::wcout<<L"could not load server.dll\n";
	}
	else {
		StartServerFuncType startServer;
		StopServerFuncType stopServer;
		startServer = (StartServerFuncType) GetProcAddress(hDll, "startServer");
		stopServer = (StopServerFuncType)GetProcAddress(hDll,"stopServer");
		if (startServer == NULL) {
			std::wcout<<L"Could not start server"<<" error code= "<<GetLastError()<<"\n";
		}
		else {
//			startServer();
			for (;;)
			{
			}
			stopServer();
		}
	}
	return 0;
}
