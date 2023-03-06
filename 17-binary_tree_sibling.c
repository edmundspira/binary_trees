#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a tree
 * @node: Node to find the sibling of
 *
 * Return: A pointer to the sibling of the node in question, or NULL on failure
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left != node)
		return (node->parent->left);

	else if (node->parent->right != node)
		return (node->parent->right);

	return (node);
}
