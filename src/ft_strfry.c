/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:20:04 by pibouill          #+#    #+#             */
/*   Updated: 2025/01/29 19:25:55 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// The strfry() function randomizes the contents of string
// by randomly swapping characters in the string.
// The result is an anagram of string.

char	*ft_strfry(char *str)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] != '\0')
		{
			new_str[j] = str[i];
			str[i] = '\0';
			j++;
		}
		i++;
	}
	return (new_str);
}
