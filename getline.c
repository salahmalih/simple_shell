#include "shell.h"

/**
 * _getline - reads a line from a file
 * @buffer: pointer to the buffer to read the line into
 * @len: pointer to a variable to store the length of the line
 * @stream: file stream to read from
 *
 * Return: length of the line read, or -1 on failure
 */
ssize_t _getline(char **buffer, size_t *len, FILE *stream)
{
	static char internal_buffer[BUFFER_SIZE];
	static char *ptr = internal_buffer;
	static int bytes_left = 0;
	int i;

	if (bytes_left <= 0)
	{
		bytes_left = read(fileno(stream), internal_buffer, sizeof(internal_buffer));
		if (bytes_left <= 0)
		{
            return (-1);
		}
		ptr = internal_buffer;
	}

	for (i = 0; i < bytes_left; i++)
	{
		if (ptr[i] == '\n')
		{
			 ptr[i] = '\0';
			*len = i + 1;
			*buffer = malloc(*len);
			if (*buffer == NULL)
			{
				return (-1);
			}
			*buffer = memcpy(*buffer, ptr, *len);
			bytes_left -= *len;
			ptr += *len;
			return (*len);
		}
	}

    return (-1);
}
