/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:28:58 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/20 16:01:03 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_count(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count += 1;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*result;
	long	nb;

	nb = (long)n;
	count = get_count(nb);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	result[count--] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		result[count--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
