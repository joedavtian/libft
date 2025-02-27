/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joedavtian <joedavtian@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:21:37 by jdavtian          #+#    #+#             */
/*   Updated: 2025/02/27 13:03:17 by joedavtian       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*first;
	char	*last;
	int		s_len;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	first = (char *)s1;
	while (*first && ft_strchr(set, *first))
		first++;
	if (*first == '\0')
		return (ft_strdup(""));
	last = (char *)s1 + ft_strlen(s1) - 1;
	while (last > first && ft_strchr(set, *last))
		last--;
	s_len = last - first + 1;
	s = malloc(s_len + 1);
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, first, s_len + 1);
	return (s);
}
