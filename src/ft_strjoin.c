/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joedavtian <joedavtian@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:34:26 by jdavtian          #+#    #+#             */
/*   Updated: 2025/02/27 12:25:59 by joedavtian       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		size_s1;
	int		size_s2;
	char	*str;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	len = size_s1 + size_s2;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size_s1 + 1);
	temp = str + size_s1;
	ft_strlcpy(temp, s2, size_s2 + 1);
	return (str);
}
