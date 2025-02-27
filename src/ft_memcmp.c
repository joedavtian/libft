/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joedavtian <joedavtian@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:11 by jdavtian          #+#    #+#             */
/*   Updated: 2025/02/27 12:00:56 by joedavtian       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*so;
	unsigned char	*st;

	if (n == 0)
		return (0);
	so = (unsigned char *)s1;
	st = (unsigned char *)s2;
	while (n--)
	{
		if (*so != *st)
			return (*so - *st);
		st++;
		so++;
	}
	return (0);
}
