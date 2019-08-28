/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:53:39 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/27 12:40:50 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_btree.h"

typedef struct s_node
{
	t_btree *node;
	struct s_node *next;
} t_node;

typedef struct s_queue
{
	t_node *first;
	t_node *last;
} t_queue;

t_queue *queueInit(void)
{
	t_queue *queue = malloc(sizeof(t_queue));
	queue->first = queue->last = NULL;
	return queue;
}

void enqueue(t_queue *queue, t_btree *node)
{
	t_node *new, *oldLast;

	new = malloc(sizeof(t_node));
	new->node = node;
	new->next = NULL;
	oldLast = queue->last;
	queue->last = new;
	if (!queue->first)
		queue->first = new;
	else
		oldLast->next = new;
}

t_btree *dequeue(t_queue *queue)
{
	t_btree *res;

	if (!queue->first)
		return NULL;
	res = queue->first->node;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	return res;
}

int isEmpty(t_queue *queue)
{
	return !queue->first;
}

int btree_level_count(t_btree *root)
{
	t_queue *queue;
	int d, c, mx;

	queue = queueInit();
	enqueue(queue, root);
	mx = c = 0, d = 1;
	while (!isEmpty(queue))
	{
		root = dequeue(queue);
		if (root->left)
		{
			enqueue(queue, root->left);
			c++;
		}
		if (root->right)
		{
			enqueue(queue, root->right);
			c++;
		}
		d--;
		if (d == 0)
		{
			if (c > mx)
				mx = c;
			d = c;
			c = 0;
		}
	}
	return mx;
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
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if ((*cmpf)(item, (*root)->item) < 0)
	{
		if ((*root)->left)
			btree_insert_data(&(*root)->left, item, cmpf);
		else
			(*root)->left = btree_create_node(item);
	}
	else
	{
		if ((*root)->right)
			btree_insert_data(&(*root)->right, item, cmpf);
		else
			(*root)->right = btree_create_node(item);
	}
}

char *getNum(int n)
{
	char *str;
	asprintf(&str, "%d", n);
	return str;
}

int cmp(char *a, char *b)
{
	int x = atoi(a), y = atoi(b);
	if (x > y)
		return 1;
	if (x == y)
		return 0;
	return -1;
}

int main(void)
{
	t_btree *root = NULL;
	btree_insert_data(&root, getNum(7), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(4), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(9), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(3), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(5), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(8), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(10), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(2), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(6), (int (*)(void *, void *))&cmp);
	btree_insert_data(&root, getNum(11), (int (*)(void *, void *))&cmp);
	printf("%d\n", btree_level_count(root));
	return 0;
}
