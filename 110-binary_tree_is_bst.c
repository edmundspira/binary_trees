#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - Checks if a binary tree is a valid BST recursively
 * @tree: Pointer to the root node of the tree to check
 * @prev_val: Pointer to the value of the previously visited node
 *
 * Return: true if the tree is a valid BST, false otherwise
 */
static bool is_bst(const binary_tree_t *tree, int *prev_val)
{
	if (!tree)
		return (true);

	/* Check the left subtree */
	if (!is_bst(tree->left, prev_val))
		return (false);

	/* Check the current node */
	if (tree->n <= *prev_val)
		return (false);
	*prev_val = tree->n;

	/* Check the right subtree */
	return (is_bst(tree->right, prev_val));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_val = INT_MIN;

	if (!tree)
		return (0);

	return (is_bst(tree, &prev_val));
}
