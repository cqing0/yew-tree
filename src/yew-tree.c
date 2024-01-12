#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
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

	TCHAR buffer[MAX_PATH];
	DWORD length = GetCurrentDirectory(MAX_PATH, buffer);
	
	//printf("Trying to generate many text files...\n");
	//createManyFiles();
	
	// Join the paths together
	TCHAR * workingDir = buffer;
	char testDataDir[] = "test_data";
	//TODO Make this take in the relative path
	char pathJoined[] = "C:\\work\\yew-tree\\test_data\\*.txt";

	listFilesInDir(pathJoined);

	return 0;
}
