/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:43:46 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/22 11:42:29 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	size_t			s_len;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		new = malloc(sizeof(char));
		if (new == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (len > s_len - start)
		len = s_len - start;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

// int	main()
// {
// 	char	str[] = "hola";

// 	printf("%s\n", ft_substr(str, 2, 535));
// 	return (0);
// }
