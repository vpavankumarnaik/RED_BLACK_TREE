#include "header.h"

int main()
{
	node_t *head = NULL;

	printf("1. Insert a tree\n2. Display RBT\n3. Search a node\n4. Find Min\n5. Find Max\n6. Delete a node\n7. Delete Min\n8. Delete Max\n9. EXIT\n");

	int data, ret, option;
	node_t *ret_node;

	while(1)
	{
		printf("\nEnter choice: ");
		scanf("%d", &option);

		switch(option)
		{
			case 1: printf("Enter data : ");
				scanf("%d", &data);
				ret = insert_RBT(&head, data);

				if(ret == FAILURE)
				{
					printf("ERROR: Insert RBT Failed\n");
				}
				else if(ret == DUPLICATE)
				{
					printf("INFO: Duplicate Element\n");
				}
				else
				{
					printf("INFO: RBT inserted Successfully\n");
				}
				break;

			case 2: if(head == NULL)
				{
					printf("INFO: List Empty\n");
				}
				else
				{
					printf("Inorder:\n	");
					inorder(head);
					printf("\nLevel Order:\n	");
					level_order(head);
				}
				break;

			case 3: printf("Enter data: ");
				scanf("%d", &data);

				ret = search(head, data);
				if(ret == FAILURE)
				{
					printf("INFO: Node is Not Found\n");
				}
				else
				{
					printf("INFO: Node is Found %d\n", data);
				}
				break;

			case 4: if(head == NULL)
				{
					printf("INFO: List Empty\n");
				}
				else
				{
					ret_node = find_min(head);
					printf("Min Node: %d\n", ret_node->data);
				}
				break;
			
			case 5: if(head == NULL)
				{
					printf("INFO: List Empty\n");
				}
				else
                                {
                                        ret_node = find_max(head);
                                        printf("Max Node: %d\n", ret_node->data);
                                }
                                break;

			case 6: printf("Enter data: ");
				scanf("%d", &data);
				ret = delete_node(&head, data);

				if(ret == SUCCESS)
				{
					printf("INFO: Node Deleted Successfully\n");
				}
				else
				{
					printf("INFO: Node Not Found\n");
				}
				break;

			case 7: ret = delete_min(&head);
				if(ret == FAILURE)
				{
					printf("INFO: List Empty\n");
				}
				else
				{
					printf("INFO: Min Node deleted Successfully\n");
				}
				break;

			case 8: ret = delete_max(&head);
				if(ret == FAILURE)
				{
					printf("INFO: List Empty\n");
				}
				else
				{
					printf("INFO: Max Node deleted Successfully\n");
				}
				break;

			case 9: while(delete_min(&head) != FAILURE);
				printf("Exit Successfully\n");
				return 0;

			default : printf("Invaid Choice!!\n");
		}
	}
}
