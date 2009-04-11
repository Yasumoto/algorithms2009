/*
 * CPSC 406 Algorithm Analysis
 * Chapman University
 * Joe Smith
 * 0949140
 * 04/10/09
 *
 * Assignment 5
 * Best-First Robot Navigation
 *
 */

#include "search.h"

int main(int argc, char** argv)
{
	FILE *fp;
	char letter;

	if (argc == 1)
	{
		printf("Please enter a name as an argument.\n");
		exit(1);
	}
	
	if ((fp=fopen(argv[1], "r"))==NULL)
	{
		printf("Error, no file found.\n");
		exit(1);
	}

        while( (letter = fgetc(fp) ) != EOF)
		printf("%c", letter);
	
	fclose(fp);

	return 0;
}
