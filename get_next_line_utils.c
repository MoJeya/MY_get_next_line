/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:01:31 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/08/17 18:40:45 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char *ft_subchar(int start,int end, char *s)
{
	char *tmp;
	int i;
	int len;

	len = end - start;
	i = 0;
	tmp = (char *)calloc((end  - start + 1), sizeof(char));
	while (i < len && start < end)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	return (tmp);

}

char	*ft_strdup(char *s1)
{
	char			*newStr;
	unsigned long	l_str;
	int i;

	i = 0;
	l_str = ft_strlen(s1);
	newStr = (char *)malloc(l_str + 1 * sizeof(char));
	if (newStr == NULL)
		return (newStr);
	while(l_str)
	{
		newStr[i] = s1[i];
		i++;
		--l_str;
	}
	return (newStr);
}


int		ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			break;
		i++;
	}
	return (i);
}



char	*ft_strjoin(char *dst, char *src)
{
	char	*new;
	int		i;
	int		j;
	int		size;
	//printf("This worked");
	i = 0;
	j = 0;

	if (!dst || !src)
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
	new [i] = '\0';
	return (new);
}
