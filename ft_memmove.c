/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:26:07 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/20 15:51:30 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;

	d_cpy = (unsigned char *)dest;
	s_cpy = (unsigned char *)src;
	if ((uintptr_t)d_cpy < (uintptr_t)s_cpy)
		while (n--)
			*(d_cpy++) = *(s_cpy++);
	else
		while (n--)
			d_cpy[n] = s_cpy[n];
	return (dest);
}
