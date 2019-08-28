/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 02:56:12 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/27 11:43:26 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
	void *))
{
	if (!root)
		return NULL;
	if ((*cmpf)(root->item, data_ref) > 0)
		return btree_search_item(root->left, data_ref, cmpf);
	else if (root && (*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	else if ((*cmpf)(root->item, data_ref) < 0)
		return btree_search_item(root->right, data_ref, cmpf);
	else
		return (NULL);
}

t_btree		*btree_create_node(void *item)
{
	t_btree	*elem;

	elem = malloc(sizeof(t_btree));
	if (elem)
	{
		elem->left = NULL;
		elem->right = NULL;
		elem->item = item;
	}
	return (elem);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
	void *))
{
	t_btree	*node;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	node = *root;
	if ((*cmpf)(item, node->item) < 0)
	{
		if (node->left)
			btree_insert_data(&node->left, item, cmpf);
		else
			node->left = btree_create_node(item);
	}
	else
	{
		if (node->right)
			btree_insert_data(&node->right, item, cmpf);
		else
			node->right = btree_create_node(item);
	}
}

void print_tree(t_btree *root)
{
	if (!root)
		return ;
	printf("%s ", root->item);
	print_tree(root->left);
	print_tree(root->right);
}

char *getNum(int n)
{
	char *str;
	asprintf(&str, "%d", n);
	return str;
}

int main(void)
{
	t_btree *root = NULL;
	for (size_t i = 0; i < 5; i++)
		btree_insert_data(&root, getNum(i), (int (*)(void *, void *))&strcmp);
	print_tree(root);
	printf("%s\n", btree_search_item(root, "2", (int (*)(void *, void *))&strcmp));
	return 0;
}
