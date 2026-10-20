/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:31:39 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/19 17:12:56 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d_cpy;
	const unsigned char	*s_cpy;

	d_cpy = (unsigned char *)dest;
	s_cpy = (const unsigned char *)src;
	while (n--)
		*(d_cpy++) = *(s_cpy++);
	return (dest);
}
