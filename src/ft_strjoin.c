/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:59:22 by pibouill          #+#    #+#             */
/*   Updated: 2024/10/10 21:16:05 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Creates new string (s1 + s2)
*/

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new;
// 	int		i;
// 	int		j;
//
// 	if (s1 == NULL)
// 		s1 = ft_strdup("");
// 	if (s1 == NULL || s2 == NULL)
// 		return (free((char *)s1), NULL);
// 	i = 0;
// 	j = 0;
// 	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (new == NULL)
// 	{
// 		free((char *)s1);
// 		return (NULL);
// 	}
// 	while (s1[i])
// 		new[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		new[j++] = s2[i++];
// 	new[j] = '\0';
// 	free((char *)s1);
// 	return (new);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (free((char *)s1), NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (free((char *)s1), NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	free((char *)s1);
	return (new);
}

// int	main()
// {
// 	char	s1[] = "prefix->";
// 	char	s2[] = "suffix";

// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
