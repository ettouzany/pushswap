/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:11:09 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/14 16:23:12 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	new = malloc(size);
	if (new == NULL)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size);
		free(ptr);
	}
	return (new);
}
