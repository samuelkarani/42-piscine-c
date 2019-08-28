/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 00:03:37 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/26 15:29:10 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_list.h"

void print(t_list *lst)
{
	while (lst)
	{
		printf("%s->", lst->data);
		lst = lst->next;
	}
	printf("%s\n", NULL);
}

void	ft_swap(void **a, void **b)
{
	void *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *list_i;
	t_list *list_j;

	if (*begin_list)
	{
		list_i = *begin_list;
		while (list_i->next)
		{
			list_j = *begin_list;
			while (list_j->next)
			{
				if ((*cmp)(list_j->data, list_j->next->data) > 0)
					ft_swap(&(list_j->data), &(list_j->next->data));
				list_j = list_j->next;
			}
			list_i = list_i->next;
		}
	}
}

int		ft_list_size(t_list *begin_list)
{
	int		i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

void	ft_list_sort_bubble(t_list **begin_list, int (*cmp)())
{
	int i, n;
	t_list *next, *prev, *j;

	n = ft_list_size(*begin_list);
	i = 0;
	while (i < n - 1)
	{
		prev = 0;
		j = *begin_list;
		while (j->next)
		{
			if ((*cmp)(j->data, j->next->data) > 0)
			{
				 if (!prev)
					prev = *begin_list = j->next;
				else
					prev = prev->next = j->next;
				next = j->next->next;
				j->next->next = j;
				j->next = next;
			}
			else
			{
				prev = j;
				j = j->next;
			}
		}
		i++;
	}
}

void divide(t_list *list, t_list **a, t_list **b)
{
	t_list *fast, *slow, *prev;

	*a = slow = list;
	fast = list->next;
	while (fast)
	{
        fast = fast->next;
        if (fast)
		{
            slow = slow->next;
            fast = fast->next;
        }
    }
	*b = slow->next;
	slow->next = 0;
}

t_list *merge(t_list *a, t_list *b, int (*cmp)())
{
	t_list *res;

	if (!a)
		return b;
	if (!b)
		return a;
	if ((*cmp)(a->data, b->data) < 0)
	{
		res = a;
		res->next = merge(a->next, b, cmp);
	}
	else
	{
		res = b;
		res->next = merge(a, b->next, cmp);
	}
	return res;
}

void	ft_list_sort_merge(t_list **begin_list, int (*cmp)())
{
	t_list *a, *b;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	divide(*begin_list, &a, &b);
	ft_list_sort_merge(&a, cmp);
	ft_list_sort_merge(&b, cmp);
	*begin_list = merge(a, b, cmp);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*p;

	list = ft_create_elem(av[--ac]);
	p = list;
	while (--ac >= 0)
		list = list->next = ft_create_elem(av[ac]);
	return (p);
}

t_list		*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

int main(int ac, char *av[])
{
	t_list *lst = ft_list_push_params(ac - 1, av + 1);
	// ft_list_sort(&lst, &strcmp);
	// ft_list_sort_bubble(&lst, &strcmp);
	ft_list_sort_merge(&lst, &strcmp);
	print(lst);
	return 0;
}
