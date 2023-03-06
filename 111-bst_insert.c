#include "binary_trees.h"

/**
 * insert - Inserts the new node in its place in a binary search tree
 * @parent: Parent of the new node to insert
 * @new_node: New node to insert
 *
 * Return: A pointer to the newly inserted node, or NULL if failed
 */
static bst_t *insert(bst_t *parent, bst_t *new_node)
{
	if (!parent || new_node->n == parent->n)
		return (NULL);

	if (!parent->left && new_node->n < parent->n)
	{
		parent->left     = new_node;
		new_node->parent = parent;
		return (new_node);
	}

	if (!parent->right && new_node->n > parent->n)
	{
		parent->right    = new_node;
		new_node->parent = parent;
		return (new_node);
	}

	return (new_node->n < parent->n ? insert(parent->left, new_node)
					: insert(parent->right, new_node));
}

/**
 * bst_insert - Inserts a new node in a Binary Search Tree recursively
 * @tree: The address to the pointer to the root node of the BST
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *inserted;

	if (!tree)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}

	inserted = insert(*tree, new_node);
	if (!inserted)
		free(new_node);

	return (inserted);
}
