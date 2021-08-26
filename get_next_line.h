# ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

//#ifndef BUFFER_SIZE
//# define BUFFER_SIZE 5
//#endif

#include <stdio.h> //take this out
#include <stdlib.h>
#include <sys/types.h> //take this out
#include <sys/stat.h> //take this out
#include <fcntl.h> //take this out
#include <unistd.h>
#include <string.h> //take this out


char	*get_next_line(int fd);
int		ft_strlen(char *str);
char 	*ft_subchar(int start,int end, char *s);
char	*ft_strjoin(char *dst, char *src);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *s1);

#endif
