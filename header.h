#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

//status
typedef enum
{
	SUCCESS,
	FAILURE,
	DUPLICATE
}Status;

//color
typedef enum
{
	RED,
	BLACK
}color_t;

//node
typedef struct node
{
	int data;
	color_t color;
	struct node *left;
	struct node *right;
	struct node *parent;
}node_t;	

//insert RBT
Status insert_RBT(node_t **head, int data);
void left_rotate(node_t **head, node_t *x);
void right_rotate(node_t **head, node_t *y);
void fix_insert(node_t **head, node_t *node);

//search RBT
Status search(node_t *head, int data);
node_t *find_min(node_t *head);
node_t *find_max(node_t *head);

//delete RBT
Status delete_node(node_t **root, int key);
Status delete_min(node_t **head);
Status delete_max(node_t **head);
void fix_delete(node_t **root, node_t *x, node_t *parent);
void rb_transplant(node_t **root, node_t *u, node_t *v);

//print RBT
void inorder(node_t *head);
void level_order(node_t *head);

#endif
