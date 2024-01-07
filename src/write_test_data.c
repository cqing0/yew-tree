#include <stdio.h>

// File to generate junk text files

void createManyFiles()
{
	for (int i = 0; i < 1000; i++)
	{
		char fileName[30];
		sprintf(fileName, "test_data/test_text%d.txt", i);

		FILE * textFile = fopen(fileName, "w");

		if (textFile == NULL)
		{
				printf("Error in creating test text file: %s - at integer %d\n", fileName, i);
		}
		else
		{
			fprintf(textFile, "This is text file %d", i);
			fclose(textFile);
		}
	}
}
