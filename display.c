#include "header.h"

void inorder(node_t *head)
{
	if(head != NULL)
	{
		inorder(head->left);
		printf("%d(%c) ", head->data, head->color == RED ? 'R' : 'B');
		inorder(head->right);
	}
}

void level_order(node_t *head)
{
	if(head == NULL)
	{
		return;
	}

	node_t *queue[100];
	int front = 0, rear = 0;
	
	queue[rear++] = head;

	while(front < rear)
	{
		node_t *temp = queue[front++];
		printf("%d(%c) ", temp->data, temp->color == RED ? 'R' : 'B');
		if(temp->left)
		{
			queue[rear++] = temp->left;
		}
		if(temp->right)
		{
			queue[rear++] = temp->right;
		}
	}
	printf("\n");
}
