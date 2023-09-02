#include "binary_trees.h"

avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);

/**
 * aux_sort - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: position where the array starts
 * @last: position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *tree_base;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		tree_base = (avl_t *)aux;
		tree_base->left = aux_sort(tree_base, array, begin, mid - 1);
		tree_base->right = aux_sort(tree_base, array, mid + 1, last);
		return (tree_base);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
