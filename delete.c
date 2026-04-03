#include "header.h"

Status delete_node(node_t **root, int key)
{
    node_t *z = *root;

    while(z != NULL)
    {
        if(key == z->data)
            break;
        else if(key < z->data)
            z = z->left;
        else
            z = z->right;
    }

    if(z == NULL)
        return FAILURE;

    node_t *y = z;
    node_t *x;
    node_t *x_parent;
    color_t y_original = y->color;

    if(z->left == NULL)
    {
        x = z->right;
        x_parent = z->parent;
        rb_transplant(root, z, z->right);
    }
    else if(z->right == NULL)
    {
        x = z->left;
        x_parent = z->parent;
        rb_transplant(root, z, z->left);
    }
    else
    {
        y = find_min(z->right);
        y_original = y->color;
        x = y->right;

        if(y->parent == z)
        {
            x_parent = y;
            if(x)
                x->parent = y;
        }
        else
        {
            x_parent = y->parent;
            rb_transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rb_transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    free(z);

    if(y_original == BLACK)
        fix_delete(root, x, x_parent);

    return SUCCESS;
}

Status delete_min(node_t **head)
{
    if(*head == NULL)
        return FAILURE;

    node_t *min = find_min(*head);
    return delete_node(head, min->data);
}

Status delete_max(node_t **head)
{
    if(*head == NULL)
        return FAILURE;

    node_t *max = find_max(*head);
    return delete_node(head, max->data);
}

void rb_transplant(node_t **root, node_t *u, node_t *v)
{
    if(u->parent == NULL)
        *root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if(v != NULL)
        v->parent = u->parent;
}

void fix_delete(node_t **root, node_t *x, node_t *parent)
{
    while((x != *root) && (x == NULL || x->color == BLACK))
    {
        if(parent == NULL)
            break;

        if(x == parent->left)
        {
            node_t *w = parent->right;

            if(w && w->color == RED)
            {
                w->color = BLACK;
                parent->color = RED;
                left_rotate(root, parent);
                w = parent->right;
            }

            if((w == NULL) ||
               ((w->left == NULL || w->left->color == BLACK) &&
                (w->right == NULL || w->right->color == BLACK)))
            {
                if(w) w->color = RED;
                x = parent;
                parent = x->parent;
            }
            else
            {
                if(w->right == NULL || w->right->color == BLACK)
                {
                    if(w->left) w->left->color = BLACK;
                    if(w) w->color = RED;
                    right_rotate(root, w);
                    w = parent->right;
                }

                if(w) w->color = parent->color;
                parent->color = BLACK;

                if(w && w->right)
                    w->right->color = BLACK;

                left_rotate(root, parent);
                x = *root;
                break;
            }
        }
        else
        {
            node_t *w = parent->left;

            if(w && w->color == RED)
            {
                w->color = BLACK;
                parent->color = RED;
                right_rotate(root, parent);
                w = parent->left;
            }

            if((w == NULL) ||
               ((w->left == NULL || w->left->color == BLACK) &&
                (w->right == NULL || w->right->color == BLACK)))
            {
                if(w) w->color = RED;
                x = parent;
                parent = x->parent;
            }
            else
            {
                if(w->left == NULL || w->left->color == BLACK)
                {
                    if(w->right) w->right->color = BLACK;
                    if(w) w->color = RED;
                    left_rotate(root, w);
                    w = parent->left;
                }

                if(w) w->color = parent->color;
                parent->color = BLACK;

                if(w && w->left)
                    w->left->color = BLACK;

                right_rotate(root, parent);
                x = *root;
                break;
            }
        }
    }

    if(x)
        x->color = BLACK;
}
