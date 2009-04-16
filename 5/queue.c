#include "search.h"

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
