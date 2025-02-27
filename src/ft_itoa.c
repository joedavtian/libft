/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joedavtian <joedavtian@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:56:28 by jdavtian          #+#    #+#             */
/*   Updated: 2025/02/27 11:53:16 by joedavtian       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*itoazero(void)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*populate_string(char *str, unsigned int num, int len, int n)
{
	str[len--] = '\0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[len] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				len;
	int				temp;
	char			*str;

	if (n == 0)
		return (itoazero());
	temp = n;
	len = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	if (n < 0)
	{
		len++;
		num = -(unsigned int)n;
	}
	else
		num = (unsigned int)n;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	return (populate_string(str, num, len, n));
}
