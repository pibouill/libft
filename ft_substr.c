/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:43:46 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/20 18:04:51 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	size_t			sub_start;

	i = 0;
	sub_start = (size_t) start;
	if (sub_start > ft_strlen(s))
		return (ft_strdup(""));
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < len && s[sub_start + i])
	{
		new[i] = s[sub_start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// int	main()
// {
// 	char	str[] = "hola";

// 	printf("%s\n", ft_substr(str, 2, 535));
// 	return (0);
// }
