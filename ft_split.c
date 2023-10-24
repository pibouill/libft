/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:27:12 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/24 19:09:13 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns an array of strings
** from the split of a string by char c
*/

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*alloc_word(char const *s, char c)
{
	char	*new_word;
	int		i;
	int		len;

	i = 0;
	len = word_len(s, c);
	new_word = malloc(sizeof(char) * len + 1);
	if (new_word == NULL)
		return (NULL);
	while (i < len)
	{
		new_word[i] = s[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	char	**new_arr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	new_arr = malloc(sizeof(char *) * word_count(s, c) + 1);
	if (new_arr == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			new_arr[i++] = alloc_word(s, c);
		while (*s && *s != c)
			s++;
	}
	new_arr[i] = 0;
	return (new_arr);
}

// int	main()
// {
// 	char str[] = "^^^^^^^^^2^^^^1^^2a,^^^^";
// 	char	**ret;
// 	int		i;
// 	char	sep = '^';

// 	ret = ft_split(str, sep);
// 	i = -1;
// 	printf("word count: %i\n", word_count(str, sep));
// 	while (ret[i++])
// 	{
// 		// printf("word len = %i\n", word_len(ret[i], sep));
// 		printf("%s\n", ret[i]);
// 	}
// 	return (0);
// }
