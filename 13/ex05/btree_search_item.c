/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 02:56:12 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/07 23:39:22 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
	void *))
{
	if ((*cmpf)(root->item, data_ref) > 0)
		btree_search_item(root->left, data_ref, cmpf);
	else if (root && (*cmpf)(root->item, data_ref) == 0)
		return (root);
	else if ((*cmpf)(root->item, data_ref) < 0)
		btree_search_item(root->right, data_ref, cmpf);
	else
		return (NULL);
}
