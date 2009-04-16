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


/* 
 * Priority Queue Stuff
 */

/*
 * Check to see if a node is already contained in the queue
 */
int contained(struct priority_queue *queue, char letter)
{
	struct node current_node = queue->queue;
	int i;
	for (i = 0; i <= count; ++i)
	{
		if (current_node.data == letter)
			return 1;
		else
			current_node = current_node->next;
	}
	return 0;
}


/*
 * Function to generate the environment from the text file
 */
char** build_environment(int size)
{
	int i;
	char **space = (char **)malloc(size * sizeof(char *));

	for(i = 0; i < size; i++)
		space[i] = (char *)malloc(size * sizeof(char));

	return space;
}

//E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2])
float euclidean_distance()
{
	return sqrt( (float)(current_x - goal_x)*(float)(current_x - goal_x) +
			(float)(current_y - goal_y)*(float)(current_y - goal_y) );
}

//M((i,j),(i',j')) = |i-i'| + |j-j'|)
int manhattan_distance()
{
	return abs(current_x - goal_x) + abs(current_y - goal_y);
}

void find_next(char** space, struct priority_queue *queue)
{
	if (contains(*queue, space[current_x][current_y]))
	{
		return;
	}
	else
	{
		add(*queue, space[current_x][current_y]);
		
	}
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
		{
			++j;
			i = 0;
			printf("\n");
		}

		else
		{
			if(letter == 'i')
			{
				current_x = i;
				current_y = j;
			}

			if(letter == 'g')
			{
				goal_x = i;
				goal_y = j;
			}

			space[i][j] = letter;
			printf("%c", space[i][j]);
			++i;
		}
	}

	printf("current_x = %d", current_x);
	printf("current_y = %d", current_y);

        struct priority_queue q, *queue;
	q.count = 0;

	queue = &q;

	while (current_x != goal_x && current_y != goal_y)
	{
                find_next(space, queue);
	}

	fclose(fp);

	return 0;
}
