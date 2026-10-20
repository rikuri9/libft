/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:30:54 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/20 15:55:56 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newdata;

	newdata = (t_list *)malloc(sizeof(t_list));
	if (!newdata)
		return (NULL);
	newdata->content = content;
	newdata->next = NULL;
	return (newdata);
}
