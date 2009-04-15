#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char** build_environment(int size);
float euclidean_distance(int current_x, int current_y, int goal_x, int goal_y);
int manhattan_distance(int current_x, int current_y, int goal_x, int goal_y);
