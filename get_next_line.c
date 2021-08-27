/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:53 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/08/27 18:08:19 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*p;
	size_t		i;

	i = 0;
	p = malloc(count * size);
	while (p && i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

static char	*ft_get_string(int ret, char **str)
{
	char			*line;
	char			*tmp;
	int				nli;

	if (ret < 0)
		return (NULL);
	else if(ret == 0 && *str == NULL)
		return (NULL);
	nli = (int)(ft_strchr(*str,'\n') - *str);
	if ((int)ft_strchr(*str,'\n'))
	{
		line = ft_subchar(0, nli + 1, *str);
		tmp = ft_strdup(&(*str)[nli + 1]);
		free(*str);
		*str = tmp;
		if(*str[0] == '\0')
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (line);
}

static int	set_line(int fd, char **buff, char **str)
{
	int		ret;

	ret = read(fd,*buff,BUFFER_SIZE);
	while (ret > 0)
	{
		(*buff)[ret] = '\0';
		if (*str == NULL)
			*str = ft_strdup(*buff);
		else
			*str = ft_strjoin(*str, *buff);
		if(ft_strchr(*str,'\n'))
			break ;
		ret = read(fd,*buff, BUFFER_SIZE);
	}
	free(*buff);
	return (ret);
}

char *get_next_line(int fd)
{
	static char		*str;
	char			*buff;
	int				ret;

	if (fd < 0)
		return (NULL);
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff || fd < 0)
		return (NULL);
	ret = set_line(fd, &buff, &str);
	return (ft_get_string(ret,&str));
}

