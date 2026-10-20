/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:26:41 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/19 13:04:56 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	memory = (void *)malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, nmemb * size);
	return (memory);
}
