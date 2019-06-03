/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:05:11 by smbaabu           #+#    #+#             */
/*   Updated: 2018/09/06 23:05:15 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
#define HELPERS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 8192
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define DEFAULT_LINES 10

int		ft_atoi_wacky(char *str);

void	ft_putstr(int fd, char *str);

void	ft_putchar(int fd, char c);

void	print_file_name(char *filename);

#endif