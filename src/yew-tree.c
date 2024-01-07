#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include "write_test_data.h"

void listFilesInDir(const char * path)
{
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile(path, &findFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Error in finding files\n");
		return;
	}

	do
	{
		printf("File: %s\n", findFileData.cFileName);
	}
	while (FindNextFile(hFind, &findFileData) != 0);

	FindClose(hFind);
}

int main()
{
	printf("Trying to generate many text files...\n");

	TCHAR buffer[MAX_PATH];
	DWORD length = GetCurrentDirectory(MAX_PATH, buffer);
	
	createManyFiles();
	const char * dirPathToFiles = buffer;
	_tprintf(_T("Curr dir is %s\n"), dirPathToFiles);

	//listFilesInDir(dirPathToFiles);

	return 0;
}
