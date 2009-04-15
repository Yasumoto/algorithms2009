#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int current_x, current_y, goal_x, goal_y;

char** build_environment(int size);
float euclidean_distance();
int manhattan_distance();

void find_next(char** space);

struct {
	char data;
	node next;
} node;

struct {
	node* queue;
	void (*push)(node) = NULL;
	node (*pop)() = NULL;
} queue
