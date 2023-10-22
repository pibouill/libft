/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:23:51 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/22 13:38:22 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static	void	ft_test(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = toupper(*c);
// }
// int	main(void)
// {
// 	char	str[] = "This is a string.";
// 	printf("%s\n", str);
// 	ft_striteri(str, ft_test);
// 	printf("%s\n", str);
// 	return (0);
// }
