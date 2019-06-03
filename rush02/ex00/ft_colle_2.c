#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_colle_2.h"
#define BUFF_SIZE 4096
// REMOVE
#include <stdio.h>

static char	g_buf[BUFF_SIZE + 1];
static int 	g_ret;
static char	*g_temp;
static int 	g_height;
static int 	g_width;
static int	g_ok;
static int	g_counter;

static void	ft_get_dimensions(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			g_width++;
		else
			break ;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			g_height++;
		i++;
	}
}

static void loop_two(char *str)
{
	int i;
	
	i = 0;
	g_ok = g_counter;
	g_counter = 0;
	g_temp = NULL;
	char	*(*fun_ptr_arr[])(int, int) = { rush00, rush01, rush02, rush03, rush04 };
	while (i < N)
	{
		g_temp = (*fun_ptr_arr[i])(g_width, g_height);
		if (ft_strcmp(str, g_temp) == 0)
		{
			if (g_ok > 1)
			{
				ft_putstr("] || [");
				g_ok--;
			}
			if (g_ok > 1 || g_counter > 0)
				ft_putstr("[colle-0");
			else
				ft_putstr("[rush-0");
			ft_putnbr(i);
			ft_putstr("] [");
			ft_putnbr(g_width);
			ft_putstr("] [");
			ft_putnbr(g_height);
			ft_putstr("]");
			g_counter++;
		}
		i++;
	}
}

static void	loop_one(char *str)
{
	int i;
	
	i = 0;
	g_counter = 0;
	char	*(*fun_ptr_arr[])(int, int) = { rush00, rush01, rush02, rush03, rush04 };
	g_temp = NULL;
	while (i < N)
	{
		g_temp = (*fun_ptr_arr[i])(g_width, g_height);
		if (ft_strcmp(str, g_temp) == 0)
			g_counter++;
		i++;
	}
}

static char 	*ft_read(char *str)
{
	int	i;

	g_temp = NULL;
	i = 0;
	while ((g_ret = read(0, g_buf, BUFF_SIZE)))
	{
		g_buf[g_ret] = 0;
		if (str)
		{
			g_temp = str;
			str = malloc(sizeof(char) * (i + g_ret + 1));
			ft_strcpy(str, g_temp);
		}
		else
			str = malloc(sizeof(char) * g_ret + 1);
		ft_strncat(str, g_buf, g_ret);
		i += g_ret;
	}
	str[i] = 0;
	return str;
}

int     main(void)
{
	char 	*str;

	str = NULL;
	g_height = 0;
	g_width = 0;
	str = ft_read(str);
	ft_get_dimensions(str);
	loop_one(str);
	if (g_counter)
		loop_two(str);
	else
		ft_putstr("aucune");
	ft_putchar('\n');
}