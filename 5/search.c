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
int contained(priority_queue *queue, int current_x, int current_y)
{
	
	node *current_node = queue->queue;
	int i;
	//printf("Doing contained: Queue count: %d\n", queue->count);
	for (i = 1; i <= queue->count; ++i)
	{
		//printf("This is i: %d\n", i);
		if ((current_node->x_location == current_x) && (current_node->y_location == current_y))
			return 1;

		current_node = current_node->next;
	}
	return 0;
}

/*
 * Add a new node to the queue
 */
void add(priority_queue *queue, char letter, int x_pos, int y_pos)
{
	if (queue->queue->parent != NULL && (queue->queue->parent->x_location == x_pos) && (queue->queue->parent->y_location == y_pos))
	{
		//printf("Whoa there, don't add a parent!\n");
		return;
	}

	node *new, *current;

	new = (node *) malloc (sizeof(node));

	int i;


	new->x_location = x_pos;
	new->y_location = y_pos;
	new->data = letter;
	new->parent = queue->queue;

	new->eu_priority  = 1.0 + euclidean_distance(x_pos, y_pos);
	//printf("And the EU priority is %f\n", new->eu_priority);

	current = queue->queue;

        for (i = 0; i <= queue->count; ++i)
	{
		if ( current->next == NULL || current->next->eu_priority >= new->eu_priority )
		{
			printf("We're adding a new node: (%d, %d)\n", x_pos, y_pos);
			new->next = current->next;
			current->next = new;
			queue->count = queue->count + 1;
			break;
		}
	}

	//printf("The data is: %c\n", new->data);
	printf("X and Y values for next node are: (%d, %d)\n", queue->queue->x_location, queue->queue->y_location);
}

void dequeue(priority_queue *queue)
{
	node * temp;    
	queue->queue->next = temp;
	queue->queue = temp;

	queue->count = queue->count - 1;
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
	//printf("\nSize is: %d\n", size);
	int i;
	char **space = (char **)malloc(size * sizeof(char *));

	for(i = 0; i < size; ++i)
	{
		printf("Row number: %d\n", i);
		space[i] = (char *)malloc(size * sizeof(char));
	}

	return space;
}


void find_next(char** space, priority_queue *queue, int orig_x, int orig_y)
{
	int current_x = orig_x;
	int current_y = orig_y;

	if (current_x == goal_x && current_y == goal_y)
	{
		printf("GG!");
		printf("Final X: %d\n", current_x);
		printf("Final Y: %d\n", current_y);
		return;
	}

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
		//printf("Minus 1 to both\n");
		current_x = orig_x - 1;
		current_y = orig_y - 1;
		if (current_x >= 0 && current_y >= 0)
		{
			if (space[current_x][current_y] != '+' && !contained(queue, current_x, current_y))
			{
				add(queue, space[current_x][current_y], current_x, current_y);
			}
		}

		//printf("Minus 1 to X, Plus 1 to y\n");
		current_x = orig_x - 1;
		current_y = orig_y + 1;
		if (current_x >= 0 && current_y >= 0)
		{
			if (space[current_x][current_y] != '+' && !contained(queue, current_x, current_y))
			{
				add(queue, space[current_x][current_y], current_x, current_y);
			}
		}


		//printf("Plus 1 to X, Minus 1 to y\n");
		current_x = orig_x + 1;
		current_y = orig_y - 1;
		if (current_x >= 0 && current_y >= 0)
		{
			if (space[current_x][current_y] != '+' && !contained(queue, current_x, current_y))
			{
				add(queue, space[current_x][current_y], current_x, current_y);
			}
		}

		//printf("Plus 1 to both\n");
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
	printf("We're done with this iteration, rolling again starting at: (%d, %d)\n", queue->queue->x_location, queue->queue->y_location);
	//printf("We're done with this iteration, here's the x_location! %d\n", queue->queue->x_location);
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

        priority_queue q, *queue;
	node * initial;

	initial = (node *) malloc (sizeof(node));


	initial->data = space[current_x][current_y];
	initial->x_location = current_x;
	initial->y_location = current_y;

	//printf("***\n");
	//printf("Initial X: %d\n", current_x);
	//printf("Initial Y: %d\n", current_y);
	//printf("***\n");

	q.queue = initial;
	q.count = 1;

	queue = &q;

	find_next(space, queue, current_x, current_y);

	fclose(fp);

	return 0;
}
