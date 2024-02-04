/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalarce <jgalarce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:49:44 by jgalarce          #+#    #+#             */
/*   Updated: 2024/01/23 20:49:44 by jgalarce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *str, char c)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != 0 && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static void	ft_freematrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	start = -1;
	matrix = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (matrix == 0 || !s)
		return (free(matrix), NULL);
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && start != -1)
		{
			matrix[j] = ft_substr(s, start, (i - start));
			if (matrix[j++] == 0)
				return (ft_freematrix(matrix), NULL);
			start = -1;
		}
		i++;
	}
	return (matrix[j] = 0, matrix);
}
