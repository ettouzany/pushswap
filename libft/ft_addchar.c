/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:41:40 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/14 22:49:05 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchar(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	new = malloc(sizeof(char) * (i + 2));
	i = 0;
	if (str)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return (new);
}
