/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:06:09 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/17 14:34:49 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	while (--s)
	{
		if (*s == c)
			return ((char *)s);
	}
	return (NULL);
}

// int	main()
// {
// 	char	str[] = "je suis une test fds fsd fd";
// 	printf("%s\n", ft_strrchr(str, 'e'));
// 	return (0);
// }
