/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:27:12 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/20 20:46:34 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, int c, int len)
{
	int	i;

	i = 0;
	while (s[len] && s[len] != c)
	{
		i++;
		len++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**new;
	size_t			len;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	new = malloc(sizeof(char *) * ft_word_count(s, c) + 1);
	if (new == NULL)
		return (NULL);
	while (i < len && j < ft_word_count(s, c))
	{
		while (s[i] == c)
			i++;
		new[j] = ft_substr(s, i, ft_word_len(s, c, i));
		j++;
		i += ft_word_len(s, c, i);
	}
	new[j] = 0;
	return (new);
}

// int	main()
// {
// 	char	str[] = "    im  a string        test ";
// 	printf("%d\n", ft_word_len(str, ' '));
// 	return (0);
// }
