#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node at as the left child
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to be stored in the new node
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	if (value < parent->n && parent->left == NULL)
		return (insert_node_left(parent, value, LEAF));

	return (insert_node_left(parent, value, REPLACE));
}

/**
 * insert_node_left - Adds a new node with the given value
 * @parent: Address of the pointer to the new node
 * @value: Value to store in the new node
 * @state: Where to place child node
 *
 * Return: Pointer to the new node, or NULL if failed
 */
binary_tree_t *insert_node_left(binary_tree_t *parent, int value, int state)
{
	binary_tree_t *new_node = NULL, *old_left = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		perror("Failed to create new node");
		return (NULL);
	}

	new_node->n = value;

	if (state == LEAF)
	{
		parent->left     = new_node;
		new_node->parent = parent;
		new_node->left   = NULL;
		new_node->right  = NULL;

		return (new_node);
	}

	old_left = parent->left;

	parent->left     = new_node;
	new_node->parent = parent;
	new_node->left   = old_left;
	old_left->parent = new_node;
	new_node->right  = NULL;

	return (new_node);
}
