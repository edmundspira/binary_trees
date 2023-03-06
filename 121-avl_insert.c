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

/**
 * _avl_insert - Performs the insertion of a node in an AVL tree
 * @tree: Address of the pointer to the root of the tree
 * @parent: Parent of the current node under evaluation
 * @new_node: Address of the pointer to the new node to insert
 * @value: Value of the new node to insert
 *
 * Return: Pointer to the new root of the AVL tree, or NULL if failed
 */
static avl_t *_avl_insert(avl_t **tree, avl_t *parent, avl_t **new_node,
			  int value)
{
	int balance_factor;

	if (!*tree || (*tree)->n == value)
		return (*tree ? *tree : (*new_node = binary_tree_node(parent, value)));

	if ((*tree)->n > value)
	{
		(*tree)->left = _avl_insert(&(*tree)->left, *tree, new_node, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else
	{
		(*tree)->right = _avl_insert(&(*tree)->right, *tree, new_node, value);
		if (!(*tree)->right)
			return (NULL);
	}

	balance_factor = binary_tree_balance(*tree);
	if (balance_factor > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree         = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree          = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a new node into the AVL tree
 * @tree: Address of the pointer to the root of the AVL tree
 * @value: Value of the new node
 *
 * Return: A pointer to the newly inserted node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	if (!binary_tree_is_avl(*tree))
		return (NULL);

	if (!_avl_insert(tree, *tree, &new_node, value))
		return (NULL);

	return (new_node);
}
