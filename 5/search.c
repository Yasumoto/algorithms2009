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
 ********************************
 * Priority Queue Stuff
 ********************************
 */

/*
 * Check to see if a node is already contained in the queue
 */
int contained(struct priority_queue *queue, char letter, int current_x, int current_y)
{
	struct node *current_node = queue->queue;
	int i;
	for (i = 1; i <= queue->count; ++i)
	{
		if (current_node->x_location == current_x)
			return 1;
		else
			current_node = current_node->next;
	}
	return 0;
}

/*
 * Add a new node to the queue
 */
void add(struct priority_queue *queue, char letter, int x_pos, int y_pos)
{

}


/*
 ********************************
 * Search Space functions
 ********************************
 */

/*
 * Function to generate the environment from the text file
 */
char** build_environment(int size)
{
	printf("\nSize is: %d\n", size);
	int i;
	char **space = (char **)malloc(size * sizeof(char *));

	for(i = 0; i < size; ++i)
	{
		printf("Row number: %d\n", i);
		space[i] = (char *)malloc(size * sizeof(char));
	}

	return space;
}

//E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2])
float euclidean_distance(int current_x, int current_y)
{
	return sqrt( (float)(current_x - goal_x)*(float)(current_x - goal_x) +
			(float)(current_y - goal_y)*(float)(current_y - goal_y) );
}

//M((i,j),(i',j')) = |i-i'| + |j-j'|)
int manhattan_distance(int current_x, int current_y)
{
	return abs(current_x - goal_x) + abs(current_y - goal_y);
}

void find_next(char** space, struct priority_queue *queue, int current_x, int current_y)
{
	if (contained(queue, space[current_x][current_y], current_x, current_y))
	{
		return;
	}
	else
	{
		add(queue, space[current_x][current_y], current_x, current_y);
	}
}
	
int main(int argc, char** argv)
{
	FILE *fp;
	char letter;
	int current_x, current_y;


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
	
	size = (int) (fgetc(fp) - '0');
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

	printf("Initial X = %d\n", current_x);
	printf("Initial Y = %d\n", current_y);

        struct priority_queue q, *queue;
	struct node init, *initial;


	init.data = space[current_x][current_y];

	q.count = 1;

	queue = &q;

	//find_next(space, queue, current_x, current_y);

	fclose(fp);

	return 0;
}
