/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joedavtian <joedavtian@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:49:17 by jdavtian          #+#    #+#             */
/*   Updated: 2025/02/27 12:21:41 by joedavtian       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static const char	*skip(const char *s, int c, int check)
{
	if (check)
	{
		while (*s == c && *s != '\0')
		{
			s++;
		}
		return (s);
	}
	while (*s != c && *s != '\0')
	{
		s++;
	}
	return (s);
}

static int	counter(const char *s, int c)
{
	int			counter;

	counter = 0;
	while (*s)
	{
		s = skip(s, c, 1);
		if (*s)
		{
			counter++;
			s = skip(s, c, 0);
		}
	}
	return (counter);
}

static void	*free_array(int index, char **array)
{
	while (index > 0)
	{
		free(array[--index]);
	}
	free(array);
	return (NULL);
}

static char	**populate_array(char **array, const char *s, int c, int n)
{
	const char	*temp;
	int			nc;
	int			index;

	index = 0;
	temp = s;
	while (*s && index < n)
	{
		temp = skip(temp, c, 1);
		s = skip(s, c, 1);
		temp = skip(temp, c, 0);
		nc = temp - s;
		array[index] = malloc(nc + 1);
		if (array[index] == NULL)
			return (free_array(index, array));
		ft_strlcpy(array[index], s, nc + 1);
		s += nc;
		index++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char		**array;
	int			n;

	if (s == NULL)
		return (NULL);
	n = counter(s, c);
	array = (char **) malloc((n + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = populate_array(array, s, c, n);
	return (array);
}
