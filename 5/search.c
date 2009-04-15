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


char** build_environment(int size)
{
	int i;
	char **space = (char **)malloc(size * sizeof(char *));

	for(i = 0; i < size; i++)
		space[i] = (char *)malloc(size * sizeof(char));

	return space;
}

//E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2])
float euclidean_distance(int current_x, int current_y, int goal_x, int goal_y)
{
	return sqrt( (float)(current_x - goal_x)*(float)(current_x - goal_x) +
			(float)(current_y - goal_y)*(float)(current_y - goal_y) );
}
	

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
	
	int size = (int) fgetc(fp);
	fgetc(fp);


	char **space = build_environment(size);

	
	int i = 0, j = 0;
        while( (letter = fgetc(fp) ) != EOF)
	{
		if (letter == '\n')
			printf("\n");
		else
		{
			space[i][j] = letter;
			printf("%c", space[i][j]);
			++i; ++j;
		}
	}
	
	fclose(fp);

	return 0;
}
