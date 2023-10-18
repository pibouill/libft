/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:23:47 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/18 15:11:18 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i++ < n)
		str[i] = c;
	return (str);
}

// int	main()
// {
// 	char	str[100];
// 	char	str2[100];

// 	ft_memset(str, 'o', 20);
// 	memset(str2, 'o', 20);
// 	printf("%s\n", str);
// 	printf("%s\n", str2);
// 	return (0);
// }
