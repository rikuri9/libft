/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:28:09 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/20 16:01:51 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*getword(char const *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**allfree(char **dest, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(dest[i]);
		dest[i] = NULL;
		i++;
	}
	free(dest);
	dest = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	index;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!dest)
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			dest[index] = getword(s, c);
			if (!dest)
				return (allfree(dest, index));
			index++;
		}
		while (*s && *s != c)
			s++;
	}
	dest[index] = NULL;
	return (dest);
}
