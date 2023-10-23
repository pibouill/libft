/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:27:12 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/23 11:00:35 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns an array of strings
** from the split of a string by char c
*/

static int	ft_word_count(char const *s, char c)
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

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_alloc_word(char const *s, char c)
{
	char	*new_word;
	int		i;
	int		len;

	i = 0;
	len = ft_word_len(s, c);
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
	new_arr = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (new_arr == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			new_arr[i++] = ft_alloc_word(s, c);
		while (*s && *s != c)
			s++;
	}
	new_arr[i] = 0;
	return (new_arr);
}

// int	main()
// {
// 	char str[] = "    im  a string    df fdsf fd sfdsf f dsfds fdsf";
// 	char	**ret;
// 	int		i;

// 	ret = ft_split(str, ' ');
// 	i = -1;
// 	while (ret[i++])
// 		printf("%s\n", ret[i]);
// 	return (0);
// }
