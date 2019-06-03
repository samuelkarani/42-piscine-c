#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_btree.h"

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
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


t_btree		**btree_insert_helper(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree *elem;
	elem = NULL;
	if (*root == NULL)
	{
		elem = btree_create_node(item);
		return (&elem);
	}
	else if ((*cmpf)((*root)->item, item) > 0)
		(*root)->left =  *btree_insert_helper(&(*root)->left, item, cmpf);
	else if ((*cmpf)((*root)->item, item) < 0)
		(*root)->right = *btree_insert_helper(&(*root)->right, item, cmpf);
	return root;
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	btree_insert_helper(root, item, cmpf);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	(*applyf)(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	(*applyf)(root);
	btree_apply_infix(root->right, applyf);
}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	(*applyf)(root);
}


int     main(int argc, char **argv)
{	
	t_btree *list;
	int i;

	i = 1;
    while (i < argc)
	{
		btree_insert_data(&list, argv[i], (int (*)(void *, void *))strcmp);	
		i++;
	}
	btree_apply_infix(list, (void (*)(void *))ft_putstr);
}