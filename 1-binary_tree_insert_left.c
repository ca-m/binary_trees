#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts node as a left-child of
 *                           of another in a binary tree
 * @parent: pointer to the node to insert left-child in
 * @value: value to store in new node
 *
 * Return: if parent is NULL or an error occurs - NULL
 *         otherwise - a pointer to the new node
 *
 * Description: if parent already has a left-child, the new node
 *              takes its place and old left-child is set as
 *              the left-child of the new node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
