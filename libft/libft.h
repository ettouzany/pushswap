/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:43:13 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/16 08:16:46 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_addchar(char *str, char c);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_realloc(void *ptr, size_t size);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
char	**ft_strsplit(char const *s, char c);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
#endif