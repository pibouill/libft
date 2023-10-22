/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:05:43 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/22 13:22:16 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new [i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

static	char	ft_test(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}
int	main(void)
{
	char	str[] = "This is a string.";
	printf("%s\n", str);
	char	*str_new = ft_strmapi(str, ft_test);
	printf("%s\n", str_new);
	return (0);
}
