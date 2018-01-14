#include <stdio.h>
#include <Windows.h>

STARTUPINFO CreateStartup()
{
	STARTUPINFO startInfo;
	startInfo.cb = 0;
	startInfo.lpReserved = NULL;
	startInfo.lpDesktop = NULL;
	startInfo.lpTitle = "Running";
	startInfo.dwX = 0;
	startInfo.dwY = 0;
	startInfo.dwXSize = 100;
	startInfo.dwYSize = 100;
	startInfo.dwXCountChars = 0;
	startInfo.dwYCountChars = 0;
	startInfo.dwFillAttribute = 0;
	startInfo.dwFlags = STARTF_USESTDHANDLES;
	startInfo.wShowWindow = 0;
	startInfo.cbReserved2 = 0;
	startInfo.lpReserved2 = NULL;
	startInfo.hStdInput = NULL;
	startInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	startInfo.hStdError = NULL;	
	return startInfo;
}

int main(int argc, char **argv)
{
	if (3 == argc) {

		size_t n = atoi(argv[1]); // Total Thread Count
		size_t m = atoi(argv[2]); // Max Thread Count

		size_t numOfProcesses = n / m;

		HANDLE *processesArray = malloc(numOfProcesses * sizeof(HANDLE));


		for (size_t i = 0; i < numOfProcesses; i++)
		{
			STARTUPINFO startInfo = CreateStartup();
			PROCESS_INFORMATION ourProcInfo;

			char buffer[4];


			sprintf()

			processesArray[i] = CreateProcess(
				"Ex04_Cotton_Strings.exe",		// app name 
				
				" 2 4",	// command parameters
				NULL,							// process attr
				NULL,							// thread attr
				TRUE,							// inheritHand
				NORMAL_PRIORITY_CLASS,			// crtFlags
				NULL,							// crtFlags
				NULL,							// currentDir
				&startInfo,						// startInfo
				&ourProcInfo						// procInfo 
			);
		}
		
	}
	else {
		printf("use as <Program> <N> <M> (N - Total Thread Count, M - Max Thread Count)\n");
	}

	getchar();

	return 0;
}