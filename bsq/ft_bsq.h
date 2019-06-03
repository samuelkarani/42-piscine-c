/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:11:43 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/12 20:25:19 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# define BUFSIZE 1048576

typedef	struct		s_square_pos
{
	int				h_offset;
	int				w_offset;
}					t_square_pos;

typedef	struct		s_square
{
	t_square_pos	top_left;
	t_square_pos	bot_right;
}					t_square;

void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
int					ft_atoi(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strcat(char *s1, char *s2);

char				**solve(char **map);
char				**read_map(char *str);
void				print_map(char **map);
void				free_map(char **map);

int					read_first_line(char *str);
void				initialize(char **str, char **temp, int *i);
int					get_height(char *str);
int					get_width(char *str);
int					validate_chars(char *str);
int					is_valid(char *buf);
void				print_sq_coordinates(t_square *sq);
int					mark_spot(char *c);
int					is_square_invalid(char *c);
void				update_largest_square(t_square *largest_square,
					t_square *sq);
void				*free_and_null(char **str);

char				g_obstacle;
char				g_full;
char				g_empty;
int					g_width;
int					g_height;
int					g_prev;

#endif
