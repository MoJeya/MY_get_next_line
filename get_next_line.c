/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:53 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/08/17 19:03:40 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_string(int ret, char **str, int i)
{
	char	*line;
	char	*tmp;
	int		nli;
	//printf("line 21 of get_string works");
	i = 0;
	if (ret < 0 || *str == NULL)
		return (NULL);
	//printf("line 25 of get_string works\n");
	nli = (int)(ft_strchr(*str,'\n'));
	if (nli > 0)
	{
		line = ft_subchar(i, nli, *str);
		//printf("%d is ret\n", ret);
	}
	//printf("%d is a new line\n",nli);
	//printf("%s >> line", line);
	i = nli;
	return (line);
}

static int	set_line(int fd, char **buff, char **str)
{
	int	ret;
	char	*tmp;
	//printf("set line starts\n");
	ret = read(fd,*buff,BUFFER_SIZE);
	while (ret)
	{

		if (*str == NULL)
		{
			//printf("%s is saved in the buffer\n", *buff);
			*str = ft_strdup(*buff);
		}
		else
		{
			tmp = ft_strjoin(*str, *buff);
			free(*str);
			*str = tmp;
			//printf("%s\n",*str);
		}
		ret = read(fd,*buff, BUFFER_SIZE);
	}
	return (ret);
}

char *get_next_line(int fd)
{
	static char		*str;
	static int		i;
	char			*buff;
	int				ret;

	i = 0;
	if (fd < 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff || fd < 0)
		return (NULL);

	ret = set_line(fd, &buff, &str);
	return (ft_get_string(ret,&str, i));
}

