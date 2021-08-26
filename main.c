/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:05:07 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/08/26 14:16:33 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//how to write to files

#include "get_next_line.h"

int main()
{
	int fd;
	char	*str;
	fd = open("test.txt",O_RDONLY);
	if(fd == -1)
	{
		write(3,"ERROR",5);
	}

	while ((str = get_next_line(fd)))
	{
		printf("%s\n",str);
		free(str);
	}
	system("leaks a.out");
	return (0);
}



/**
 *
 *
	#include <stdio.h>
	#include <stdlib.h>
	#include <fcntl.h>
	#ifdef __unix__
      #include <unistd.h>
      #include <sys/stat.h>
      #include <sys/types.h>
	#elif __MSDOS__ || __WIN32__ || _MSC_VER
      #include <io.h>
      #include <sys\stat.h>
	#endif
	#define MAXBYTES 1024

	int main(int argc, char *argv[]) {
   		int in,out,count;
   		char buffer[MAXBYTES];

   		if(argc < 3) {
      		printf("Aufruf: programmname quelldatei zieldatei\n");
      		return EXIT_FAILURE;
   		}
   		if( (in=open(*++argv ,O_RDONLY)) == -1)
      		printf("Fehler open %s\n", (char *)argv);
   		if( (out=open(*++argv, O_WRONLY | O_TRUNC | O_CREAT)) == -1)
      		printf("Fehler open %s\n", (char *)argv);
   		while( (count = read(in, buffer, MAXBYTES)) )
      		write(out,buffer,count);
   		close(in);
   		close(out);
   		return EXIT_SUCCESS;
	}
 *
 *
 *
*/

