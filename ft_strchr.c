/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:54:38 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/23 12:24:26 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns pointer to first c in *s
*/

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	if ((char) c == '\0')
		return (str);
	return (NULL);
}

// int	main()
// {
// 	char	str[] = "teste";
// 	printf("%s\n", ft_strchr(str, '\0'));
// 	printf("%s\n", strchr(str, '\0'));
// 	return (0);
// }
