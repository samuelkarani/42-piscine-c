/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:20:03 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/04 01:34:15 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# ifndef NULL
#  define NULL (0)
# endif

# define N 6

int					ft_putchar(char c);
void				ft_putnbr(int nb);
int					ft_putstr(char *str);
int					ft_atoi(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_add(int a, int b);
int					ft_sub(int a, int b);
int					ft_div(int a, int b);
int					ft_mod(int a, int b);
int					ft_mul(int a, int b);
int					ft_usage(int a, int b);

typedef struct		s_opp
{
	char	*sign;
	int		(*op)(int, int);
}					t_opp;

#endif
