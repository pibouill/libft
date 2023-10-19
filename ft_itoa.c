/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:37:23 by pibouill          #+#    #+#             */
/*   Updated: 2023/10/19 14:46:02 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	long		tmp;

	len = nb_len(n);
	tmp = n;
	if (n < 0)
		tmp *= -1;
	res = malloc(sizeof(char) * (len + 1));
	res[len] = 0;
	if (tmp == 0)
		res[0] = '0';
	else
	{
		while (len-- && tmp != 0)
		{
			res[len] = (tmp % 10) + '0';
			tmp /= 10;
		}
		if (n < 0)
			res[len] = '-';
	}
	return (res);
}

// int	main()
// {
// 	printf("%s\n", ft_itoa(-5435));
// 	return (0);
// }
