/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joedavtian <joedavtian@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:24:17 by jdavtian          #+#    #+#             */
/*   Updated: 2025/02/27 13:05:50 by joedavtian       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0 || big == NULL)
		return (NULL);
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] && (i + little_len) <= len)
	{
		if (ft_memcmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
