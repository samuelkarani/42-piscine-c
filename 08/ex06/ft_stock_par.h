/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:30:58 by smbaabu           #+#    #+#             */
/*   Updated: 2019/08/25 20:31:30 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_stock_par
{
	int size_param;
	char *str;
	char *copy;
	char **tab;
} t_stock_par;

char	**ft_split_whitespaces(char *str);
t_stock_par	*ft_param_to_tab(int ac, char **av);