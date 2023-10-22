/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:59 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/22 16:39:47 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatenates src to dst
** Ends dst with \0
** Returns length of the result string whether it was possible or not
** If src was completely concatenated, return value will be smaller than size
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] && (dest_len + i) < (size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int	main()
// {
// 	char	src[] = "im the source";
// 	char	dst[] = "im the dest";

// 	printf("ft_strlcat returns %zu\n", ft_strlcat(dst, src, 10));
// 	printf("strlcat returns %zu\n", strlcat(dst, src, 10));
// 	return (0);
// }
