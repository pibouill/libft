/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:14:34 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/17 18:14:45 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_str;
	unsigned char	*src_str;
	size_t			i;

	dest_str = (unsigned char *) dest;
	src_str = (unsigned char *) src;
	i = 0;
	while (src_str[i] && i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	dest_str[i] = '\0';
	return (dest_str);
}
