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

//E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2])
float euclidean_distance(int current_x, int current_y)
{
	return sqrt( abs((float)(current_x - goal_x)*(float)(current_x - goal_x) +
			(float)(current_y - goal_y)*(float)(current_y - goal_y)) );
}

//M((i,j),(i',j')) = |i-i'| + |j-j'|)
int manhattan_distance(int current_x, int current_y)
{
	return abs(current_x - goal_x) + abs(current_y - goal_y);
}

/* 
 ********************************
 * Priority Queue Stuff
 ********************************
 */

/*
 * Check to see if a node is already contained in the queue
 */
int contained(struct priority_queue *queue, int current_x, int current_y)
{
	
	struct node *current_node = queue->queue;
	int i;
	for (i = 1; i <= queue->count; ++i)
	{
		if (current_node->x_location == current_x && current_node->y_location == current_y)
		{
			printf("It was contained.");
			return 1;
		}
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
	struct node first, *new, *current;
	int i;

	new = &first;

        printf("here's the x_pos! %d\n", x_pos);

	new->x_location = x_pos;
	new->y_location = y_pos;
	new->data = letter;
	new->parent = queue->queue;

	new->eu_priority  = euclidean_distance(x_pos, y_pos);

	current = queue->queue;

        for (i = 0; i <= queue->count; ++i)
	{
		if ( current->next->eu_priority >= new->eu_priority )
		{
			new->next = current->next;
			current->next = new;
			queue->count = queue->count + 1;
		}
	}

	printf("The data is: %c\n", new->data);

	queue->count = queue->count + 1;


}

void dequeue(struct priority_queue *queue)
{
	queue->queue =  queue->queue->next;
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


void find_next(char** space, struct priority_queue *queue, int orig_x, int orig_y)
{
	int current_x = orig_x;
	int current_y = orig_y;

	printf("***\n");
	printf("Current X: %d\n", current_x);
	printf("Current Y: %d\n", current_y);
	printf("***\n");

	if (queue->count != 1 && contained(queue, current_x, current_y))
	{
		return;
	}
	else
	{
		current_x = orig_x - 1;
		current_y = orig_y - 1;
		if (current_x >= 0 && current_y >= 0)
		{
			if (space[current_x][current_y] != '+' && !contained(queue, current_x, current_y))
			{
				add(queue, space[current_x][current_y], current_x, current_y);
			}
		}

		current_x = orig_x - 1;
		current_y = orig_y + 1;
		if (current_x >= 0 && current_y >= 0)
		{
			if (space[current_x][current_y] != '+' && !contained(queue, current_x, current_y))
			{
				add(queue, space[current_x][current_y], current_x, current_y);
			}
		}


		current_x = orig_x + 1;
		current_y = orig_y - 1;
		if (current_x >= 0 && current_y >= 0)
		{
			if (space[current_x][current_y] != '+' && !contained(queue, current_x, current_y))
			{
				add(queue, space[current_x][current_y], current_x, current_y);
			}
		}

		current_x = orig_x + 1;
		current_y = orig_y + 1;
		if (current_x >= 0 && current_y >= 0)
		{
			if (space[current_x][current_y] != '+' && !contained(queue, current_x, current_y))
			{
				add(queue, space[current_x][current_y], current_x, current_y);
			}
		}
	}

	dequeue(queue);                                    
	printf("Here's the y-location! %d\n", queue->queue->y_location);
	find_next(space, queue, queue->queue->x_location, queue->queue->y_location);
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

        struct priority_queue q, *queue;
	struct node initial;


	initial.data = space[current_x][current_y];
	initial.x_location = current_x;
	initial.y_location = current_y;

	printf("***\n");
	printf("Initial X: %d\n", current_x);
	printf("Initial Y: %d\n", current_y);
	printf("***\n");

	q.queue = &initial;
	q.count = 1;

	queue = &q;

	find_next(space, queue, current_x, current_y);

	fclose(fp);

	return 0;
}
