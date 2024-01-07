#include <stdio.h>

// File to generate junk text files

int main()
{
	FILE * textFile;

	textFile = fopen("test_text.txt", "w");

	fclose(textFile);
}
