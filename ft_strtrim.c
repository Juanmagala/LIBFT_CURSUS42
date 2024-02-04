/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalarce <jgalarce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:57:35 by jgalarce          #+#    #+#             */
/*   Updated: 2024/01/23 20:57:35 by jgalarce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_searchleft(char const *s1, char const *set, size_t *start);
static void	ft_searchright(char const *s1, char const *set, size_t *end);

static void	ft_searchleft(char const *s1, char const *set, size_t *start)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0' && s1[*start] != '\0')
	{
		if (s1[*start] != set[i])
			i++;
		if (s1[*start] == set[i])
		{
			(*start)++;
			i = 0;
		}
	}
}

static void	ft_searchright(char const *s1, char const *set, size_t *end)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0' && *end > 0)
	{
		if (s1[*end] != set[i])
			i++;
		else if (s1[*end] == set[i])
		{
			(*end)--;
			i = 0;
		}
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	ft_searchleft(s1, set, &start);
	ft_searchright(s1, set, &end);
	if (s1[start] == '\0')
		len = 0;
	else
		len = (end - start) + 1;
	return (ft_substr(s1, start, len));
}
