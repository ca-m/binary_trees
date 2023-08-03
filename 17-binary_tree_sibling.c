#include "binary_trees.h"

/**
 * binary_tree_sibling - finds sibling of a
 *                       node in binary tree
 * @node: pointer to node to find sibling of
 * Return: if node is NULL or there is no sibling - NULL
 *         otherwise - a pointer to sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
