/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:36:49 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/09/07 19:09:55 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_subchar(int start, int end, char *s);
char	*ft_strjoin(char *dst, char *src);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *s1);

#endif
