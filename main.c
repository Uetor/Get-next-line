#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"



int main(int argc, char **argv)
{
    int fd;
    int fer;
    char *str;

    fd = open (argv[1], O_RDONLY);
    str = get_next_line(fd);
    fer = open (argv[2], O_WRONLY);
    write (fer, str, ft_strlen(str));
    while (str != NULL)
    {
        str = get_next_line(fd);
        if (str != NULL)
            write (fer, str, ft_strlen(str));
    }
    close (fd);
    close (fer);
    return (0);
}