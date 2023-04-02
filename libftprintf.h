/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:45:15 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/26 18:45:15 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define FT_INT_MIN -2147483648
# define FT_INT_MAX 2147483647

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>

int		ft_itoa(int n);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putpointer(unsigned long dir);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_putx(char *s);
int		ft_printf(char const *, ...);

#endif
