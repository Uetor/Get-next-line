#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	    ft_strlen(char *str);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*get_next_line(int fd);

#endif