#include "get_next_line_bonus.h"

static char	*ft_cut(char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	new =(char *)malloc(sizeof(char) * (ft_strlen(buffer) -i) + 1);
	if (new == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		new[j++] = buffer[i++];
	new[j] = '\0';
	free (buffer);
	return (new);
}

static char *ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	line[i + 1] = '\0';
	line[i] = '\n';
	while (i >= 0)
	{
		line[i] = buffer[i];
		i--;
	}
	return (line);
}

static char	*ft_join(char *buffer, char *buf)
{
	char *temp;

	temp = ft_strjoin(buffer, buf);
	free (buffer);
	buffer = temp;
	return (buffer);
}

static char	*ft_read(int fd, char *buffer)
{
	int		nr_bytes;
	char	*buf;

	buf = (char *)malloc(sizeof(char)* BUFFER_SIZE + 1);
	nr_bytes = 1;
	while (nr_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[nr_bytes] = '\0';
		buffer = ft_join(buffer, buf);
		if (buffer[0] == '\0')
		{
			free (buffer);
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	char static	buffer[4096];

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strdup("");
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_cut(buffer[fd]);
	return (line);
}