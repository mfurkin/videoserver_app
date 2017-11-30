
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
		DestroyServerFuncType destroyServer;
		startServer = (StartServerFuncType) GetProcAddress(hDll, "startServer");
		destroyServer = (DestroyServerFuncType)GetProcAddress(hDll,"destroyyServer");
		if (startServer == NULL) {
			std::wcout<<L"Could not start server"<<" error code= "<<GetLastError()<<"\n";
		}
		else {
			startServer();
			for (;;)
			{
			}
			destroyServer();
		}
	}
	return 0;
}
