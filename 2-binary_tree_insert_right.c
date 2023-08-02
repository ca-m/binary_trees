#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node as right-child of
 *                            another in a binary tree
 * @parent: pointer to node to insert right-child in
 * @value: value to store in the new node
 * Return: if parent is NULL or an error occurs - NULL
 *         otherwise - a pointer to the new node
 * Description: if parent already has a right-child, new node
 *              takes its place and old right-child is set as
 *              the right-child of new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
 }
