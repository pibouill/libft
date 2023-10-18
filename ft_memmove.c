/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:27:32 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/18 14:03:56 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*r_dest;
// 	unsigned char	*r_src;

// 	r_dest = (unsigned char *)dest;
// 	r_src = (unsigned char *)src;
// 	if (r_src < r_dest)
// 	{
// 		while (n-- > 0)
// 			r_dest[n] = r_src[n];
// 	}
// 	else
// 		ft_memcpy(r_dest, r_src, n);
// 	return (r_dest);
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *) dst;
	from = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (to > from)
	{
		while (len-- > 0)
			to[len] = from[len];
	}
	else
		ft_memcpy(to, from, len);
	return (to);
}

int main()
{
    char str[100] = "Learningisfun";
    char *first, *second;
    first = str;
    second = str;
    printf("Original string :%s\n ", str);

    // when overlap happens then it just ignore it
    ft_memcpy(first + 8, first, 10);
    printf("memcpy overlap : %s\n ", str);

    // when overlap it start from first position
    ft_memmove(second + 8, first, 10);
    printf("memmove overlap : %s\n ", str);

    return 0;
}
