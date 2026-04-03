#include "header.h"

Status search(node_t *head, int data)
{
	while(head != NULL)
	{
		if(data < head->data)
		{
			head = head->left;
		}
		else if(data > head->data)
		{
			head = head->right;
		}
		else
		{
			return SUCCESS;
		}
	}
	return FAILURE;
}

node_t *find_min(node_t *head)
{
    while(head->left != NULL)
        head = head->left;

    return head;
}

node_t *find_max(node_t *head)
{
    while(head->right != NULL)
        head = head->right;

    return head;
}

