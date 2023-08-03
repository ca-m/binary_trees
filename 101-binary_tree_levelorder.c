#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - creates new levelorder_queue_t node
 * @node: binary tree node for new node to contain
 * Return: if an error occurs, NULL
 *         otherwise, a pointer to new node
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - frees a levelorder_queue_t queue
 * @head: pointer to head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - runs function on given binary tree node and
 *             pushes its children into levelorder_queue_t queue
 * @node: binary tree node to print and push
 * @head: double pointer to head of queue
 * @tail: double pointer to tail of queue
 * @func: pointer to function to call on @node
 * Description: upon malloc failure, exits with a status code of 1
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
				levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - pops the head of levelorder_queue_t queue
 * @head: double pointer to head of queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - traverses binary tree using
 *                          level-order traversal
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
