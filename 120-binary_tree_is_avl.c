#include "binary_trees.h"
#include <limits.h>

/**
 * _height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree pointed by `tree`. If `tree` is NULL, 0 is
 * returned.
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height  = _height(tree->left);
	right_height = _height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * _validator - Checks if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value allowed in the subtree rooted at `tree` (inclusive).
 * @max: The maximum value allowed in the subtree rooted at `tree` (inclusive).
 *
 * Return: 1 if @tree is a valid BST, 0 otherwise.
 */
static int _validator(const binary_tree_t *tree, int min, int max)
{
	int left_bf, right_bf;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_bf  = _height(tree->left);
	right_bf = _height(tree->right);

	if (abs(left_bf - right_bf) > 1)
		return (0);

	return (_validator(tree->left, min, tree->n - 1)
		&& _validator(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if `tree` is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	return (_validator(tree, INT_MIN, INT_MAX));
}
