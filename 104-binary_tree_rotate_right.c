#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a node
 * @tree: A pointer to the node to perform a right operation on
 *
 * Return: A pointer to the new root of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (!tree)
		return (new_root);

	new_root = tree->left;
	if (!new_root)
		return (tree);

	tree->left = new_root->right;
	if (new_root->right)
		tree->left->parent = tree;

	new_root->right  = tree;
	new_root->parent = tree->parent;

	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}

	tree->parent = new_root;

	return (new_root);
}
