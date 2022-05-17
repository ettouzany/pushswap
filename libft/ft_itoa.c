/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:50:17 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/14 23:14:28 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;
	int		nb;

	i = ((neg = 0, nb = n), 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		neg = ((n = -n), 1);
	while (n > 0)
		n = ((i++), n / 10);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (neg)
		str = ft_addchar(str, '-');
	return (str);
}
