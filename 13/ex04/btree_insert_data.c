/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 02:36:08 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/27 11:41:14 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_btree.h"

t_btree		*btree_create_node(void *item);

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

void print_tree(t_btree *root)
{
	if (!root)
		return ;
	printf("%s ", root->item);
	print_tree(root->left);
	print_tree(root->right);
}

int main(int ac, char *av[])
{
	t_btree *root = NULL;
	for (size_t i = 1; i < ac; i++)
		btree_insert_data(&root, av[i], (int (*)(void *, void *))&strcmp);
	print_tree(root);
	return 0;
}
