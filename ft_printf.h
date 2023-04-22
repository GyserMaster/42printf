/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrov <gyser.petrov.42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:45:15 by spetrov           #+#    #+#             */
/*   Updated: 2023/02/26 18:45:15 by spetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putpointer(unsigned long dir);
int	ft_putx(unsigned int dir, char c);
int	ft_putdi(int n);
int	ft_putul(unsigned int n);
int	ft_printf(char const *str, ...);
#endif
