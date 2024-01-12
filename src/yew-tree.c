#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include "write_test_data.h"

// Temp max path length
#define MAX_PATH_LENGTH 128

void listFilesInDir(TCHAR * path)
{
	printf("The path is %s\n", path);
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile(path, &findFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Error in finding files\n");
		return;
	}

	while (FindNextFile(hFind, &findFileData))
	{
		printf("File: %s\n", findFileData.cFileName);
	}

	FindClose(hFind);
}

int main()
{

	TCHAR runningFromPath[MAX_PATH];
	DWORD length = GetCurrentDirectory(MAX_PATH, runningFromPath);
	TCHAR relativePath[] = "\\test_data\\*.txt";

	size_t totalSizeOfPath = strlen(runningFromPath) + strlen(relativePath) + 1;
	
	TCHAR pathJoined[totalSizeOfPath];

	// Join the paths together
	strcpy(pathJoined, runningFromPath);
	strcat(pathJoined, relativePath);
	
	//printf("Trying to generate many text files...\n");
	//createManyFiles();
	
	listFilesInDir(pathJoined);

	return 0;
}
