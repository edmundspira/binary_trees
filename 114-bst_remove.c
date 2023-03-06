#include "binary_trees.h"

/**
 * _equal - Performs the removal when we find a value equal to the node
 * @root: Pointer to the node in question
 *
 * Return: The root node, a replacement node, or NULL
 */
static bst_t *_equal(bst_t *root)
{
	bst_t *replacement = NULL, *successor = NULL;

	if (!root->left && !root->right)
	{ /* Case 1: No children */
		free(root), root = NULL;
		return (NULL);
	}

	if (!root->left || !root->right)
	{ /* Case 2: One child */
		replacement = root->right ? root->right : root->left;
		free(root), root = NULL;
		return (replacement);
	}

	/* Case 3: Two children */
	successor = root->right;
	while (successor->left)
		successor = successor->left;
	root->n     = successor->n;
	root->right = bst_remove(root->right, successor->n);
	if (root->right)
		root->right->parent = root;

	return (root);
}

/**
 * bst_remove - Deletes a node from a binary search tree
 * @root: A pointer to the root node of the tree
 * @value: The value of the node to delete
 *
 * Description: If the node to delete has two children, it is replaced with its
 *		first in-order successor.
 *
 * Return: A pointer to the new root node of the new after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		root = _equal(root);
	}

	return (root);
}
