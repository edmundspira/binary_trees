#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle node of a given node in a binary tree
 * @node: Node for which to find the uncle
 *
 * Return: A pointer to the uncle node, or NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent = NULL, *potential_uncle = NULL, *uncle = NULL;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	grandparent     = node->parent->parent;
	potential_uncle = grandparent->left;

	if (potential_uncle != node->parent)
		uncle = potential_uncle;
	else
		uncle = grandparent->right;

	return (uncle);
}
