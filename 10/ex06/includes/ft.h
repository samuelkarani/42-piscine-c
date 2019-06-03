/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:20:03 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/03 17:12:51 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# ifndef NULL
#  define NULL (0)
# endif

int		ft_putchar(char c);

void	ft_putnbr(int nb);

int		ft_putstr(char *str);

int		ft_atoi(char *str);

int		ft_add(int a, int b);

int		ft_sub(int a, int b);

int		ft_div(int a, int b);

int		ft_mod(int a, int b);

int		ft_mul(int a, int b);
#endif
