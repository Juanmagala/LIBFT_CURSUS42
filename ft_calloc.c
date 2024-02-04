/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalarce <jgalarce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:58:50 by jgalarce          #+#    #+#             */
/*   Updated: 2024/02/02 17:58:50 by jgalarce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory_block;

	memory_block = malloc(count * size);
	if (memory_block == NULL)
		return (NULL);
	ft_bzero(memory_block, count * size);
	return (memory_block);
}
