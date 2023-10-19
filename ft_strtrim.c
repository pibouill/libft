/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:19:53 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/19 17:18:44 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*trimmed;

	len = ft_strlen(s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	trimmed = ft_substr(s1, 0, len + 1);
	return (trimmed);
}

int	main()
{
	char	s1[] = "+--str-ing+--";
	char	set[] = "+-";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
