#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEFT	[(current_x - 1)][current_y]
#define RIGHT	[(current_x + 1)][current_y]
#define UP	[current_x][( current_y - 1) ]
#define DOWN	[current_x][( current_y + 1)]

int current_x, current_y, goal_x, goal_y;

char** build_environment(int size);
float euclidean_distance();
int manhattan_distance();

struct node 
{
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



