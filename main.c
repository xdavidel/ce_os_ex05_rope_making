#include <stdio.h>
#include <Windows.h>

#define PROCESS_APP_NAME "Ex04_Cotton_Strings.exe"
#define GENERAL_MUTEX_NAME "gMutex"

HANDLE generalMutex;

STARTUPINFO CreateStartup()
{
	STARTUPINFO startInfo;
	startInfo.cb = 0;
	startInfo.lpReserved = NULL;
	startInfo.lpDesktop = NULL;
	startInfo.lpTitle = NULL;
	startInfo.dwX = 0;
	startInfo.dwY = 0;
	startInfo.dwXSize = 100;
	startInfo.dwYSize = 100;
	startInfo.dwXCountChars = 0;
	startInfo.dwYCountChars = 0;
	startInfo.dwFillAttribute = 0;
	startInfo.dwFlags = 0;
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
	if(3 == argc)
	{

		size_t n = atoi(argv[1]); // Total Thread Count
		size_t m = atoi(argv[2]); // Max Thread Count

		size_t numOfProcesses = n / m;

		PROCESS_INFORMATION *processesInfo = malloc(numOfProcesses * sizeof(PROCESS_INFORMATION));

		generalMutex = CreateMutex(NULL, FALSE, GENERAL_MUTEX_NAME);


		for(size_t i = 0; i < numOfProcesses; i++)
		{
			STARTUPINFO startInfo = CreateStartup();

			char params[200] = {PROCESS_APP_NAME};
			size_t length = strlen(params);

			sprintf_s(params + length, 12, " %d %d %d", n, n * i * numOfProcesses, 0);

			CreateProcess(
				NULL,							// app name 
				params,							// command parameters
				NULL,							// process attr
				NULL,							// thread attr
				TRUE,							// inheritHand
				NORMAL_PRIORITY_CLASS,			// crtFlags
				NULL,							// crtFlags
				NULL,							// currentDir
				&startInfo,						// startInfo
				&processesInfo[i]						// procInfo 
			);
		}

		getchar();
		for(size_t i = 0; i < numOfProcesses; i++)
		{
			TerminateProcess(processesInfo[i].hProcess, 0);
		}

	}
	else
	{
		printf("use as <Program> <N> <M> (N - Total Thread Count, M - Max Thread Count)\n");
		getchar();
	}

	return 0;
}