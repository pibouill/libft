/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 08:24:33 by pibouill          #+#    #+#             */
/*   Updated: 2025/04/25 08:44:47 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	new = malloc(size);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
