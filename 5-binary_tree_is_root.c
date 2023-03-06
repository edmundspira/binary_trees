#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node in a binary tree is the root node
 * @node: A pointer to the node to check
 *
 * Return: 1 if it a the root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);

	return (1);
}
