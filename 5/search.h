#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEFT	[(current_x - 1)][current_y]
#define RIGHT	[(current_x + 1)][current_y]
#define UP	[current_x][( current_y - 1) ]
#define DOWN	[current_x][( current_y + 1)]

int goal_x, goal_y;

struct node 
{
	int x_location;
	int y_location;

	// The actual character
	char data;
	// The Euclidean priority
	float eu_priority;
	// Manhattan priority
	int man_priority;
	// The next node in the queue
	struct node* next;
	// The parent node in the search tree
	struct node* parent;
};

struct priority_queue 
{
	struct node* queue;
	int count;
};

char** build_environment(int size);
float euclidean_distance();
int manhattan_distance();
int contained(struct priority_queue *queue, char letter);
void add(struct priority_queue *queue, char letter, int x_pos, int y_pos);


