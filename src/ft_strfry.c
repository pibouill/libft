/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:20:04 by pibouill          #+#    #+#             */
/*   Updated: 2025/01/29 19:53:36 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// The strfry() function randomizes the contents of string
// by randomly swapping characters in the string.
// The result is an anagram of string.

char	*ft_strfry(char *string)
{
    size_t	len;
	size_t	i;
	size_t	j;
	char	t;

	len = ft_strlen(string);
	i = 0;
    if (len > 1)
	{
		while (i < len - 1)
		{
            j = i + rand() / (RAND_MAX / (len - i) + 1);
            t = string[j];
            string[j] = string[i];
            string[i] = t;
			i++;
        }
    }
    return string;
}

int	main()
{
	char	*str;

	str = ft_strdup("Hello, World!");
	ft_putstr("Original string: ");
	ft_putstr(str);
	ft_putstr("\n");
	ft_strfry(str);
	ft_putstr("Shuffled string: ");
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	return (0);
}
