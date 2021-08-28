/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:01:31 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/08/28 13:37:13 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_subchar(int start, int len, char *s)
{
	char	*tmp;

	tmp = (char *)ft_calloc((len), sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	if (len == 0 && start == 0)
	{
		tmp[0] = s[0];
		return (tmp);
	}
	while (start < len)
	{
		tmp[start] = s[start];
		start++;
	}
	return (tmp);
}

char	*ft_strdup(char *s1)
{
	char				*newStr;
	const char			*cpy_s1;
	unsigned long		l_str;

	l_str = ft_strlen(s1);
	newStr = (char *)ft_calloc((l_str + 1), sizeof(char));
	if (newStr == NULL)
		return (newStr);
	cpy_s1 = (const char *)s1;
	newStr[l_str] = '\0';
	while (l_str)
	{
		newStr[l_str - 1] = cpy_s1[l_str - 1];
		--l_str;
	}
	return (newStr);
}

char	*ft_strchr(char *s, char c)
{
	char			*newS;

	if (!s)
		return (NULL);
	newS = s;
	while (*newS != '\0')
	{
		if (*newS == c)
			break ;
		newS++;
	}
	if (*newS == '\0')
		return (0);
	return (newS);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*new;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if ((!dst || !src) || (!dst && !src))
		return (NULL);
	size = ft_strlen(dst) + ft_strlen(src);
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (dst[i] != '\0')
	{
		new[i] = dst[i];
		i++;
	}
	while (src[j] != '\0')
		new[i++] = src[j++];
	new[i] = '\0';
	free(dst);
	return (new);
}
