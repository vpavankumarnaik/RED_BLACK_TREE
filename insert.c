#include "header.h"

Status insert_RBT(node_t **head, int data)
{
	node_t *new = malloc(sizeof(node_t));
	if(new == NULL)
	{
		return FAILURE;
	}

	new->data = data;
	new->color = RED;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	if(*head == NULL)
	{
		*head = new;
		(*head)->color = BLACK;
		return SUCCESS;
	}

	node_t *temp = *head;
	node_t *prev = NULL;
	int flag = 0;

	while(temp != NULL)
	{
		prev = temp;
		if(data < temp->data)
		{
			flag = 0;
			temp = temp->left;
		}
		else if(data > temp->data)
		{
			flag = 1;
			temp = temp->right;
		}
		else
		{
			free(new);
			return DUPLICATE;
		}
	}
	
	new->parent = prev;

	if(flag == 0)
	{
		prev->left = new;
	}
	else
	{
		prev->right = new;
	}
		
	fix_insert(head, new);
	return SUCCESS;
}

void fix_insert(node_t **head, node_t *node)
{
	while(node != *head && node->parent->color == RED)
	{
		node_t *parent = node->parent;
		node_t *grand = parent->parent;

		if(grand == NULL)
			break;

		if(parent == grand->left)
		{
			node_t *uncle = grand->right;
			if(uncle && uncle->color == RED)
			{
				parent->color = BLACK;
				uncle->color = BLACK;
				grand->color = RED;
				node = grand;
			}
			else
			{
				if(node == parent->right)
				{
					left_rotate(head, parent);
					node = parent;
					parent = node->parent;
				}

				right_rotate(head, grand);
				parent->color = BLACK;
				grand->color = RED;
			}
		}
		else
		{
		    	node_t *uncle = grand->left;

		    	if (uncle && uncle->color == RED)
		    	{
				parent->color = BLACK;
				uncle->color = BLACK;
				grand->color = RED;
				node = grand;
		    	}
		    	else
		    	{
				if (node == parent->left)
				{
				    right_rotate(head, parent);
				    node = parent;
				    parent = node->parent;
				}

				left_rotate(head, grand);
				parent->color = BLACK;
				grand->color = RED;
		    	}
		}
	}

	(*head)->color = BLACK;
}

void left_rotate(node_t **head, node_t *x)
{
	node_t *y = x->right;
	x->right = y->left;

	if(y->left != NULL)
	{
		y->left->parent = x;
	}

	y->parent = x->parent;
	if(x->parent == NULL)
	{
		*head = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;
}

void right_rotate(node_t **head, node_t *y)
{
	node_t *x = y->left;
	y->left = x->right;

	if(x->right != NULL)
	{
		x->right->parent = y;
	}

	x->parent = y->parent;
	if(y->parent == NULL)
	{
		*head = x;
	}
	else if(y == y->parent->left)
	{
		y->parent->left = x;
	}
	else
	{
		y->parent->right = x;
	}

	x->right = y;
	y->parent = x;
}
