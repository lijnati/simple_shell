#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i = 0, j = 0, k = 0, m = 0, numwords = 0;
	char **s = NULL;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	d = (d == NULL) ? " " : d;

	while (str[i] != '\0')
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;
		i++;
	}

	if (numwords == 0)
		return (NULL);

	s = malloc((numwords + 1) * sizeof(char *));
	if (s == NULL)
		return (NULL);

	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k] != '\0')
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (s[j] == NULL)
		{
			for (m = 0; m < j; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = '\0';
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimiter character
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
    int i, j, k, m, numwords = 0;
    char **s;

    if (str == NULL || str[0] == 0)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            numwords++;
    if (numwords == 0)
        return (NULL);
    s = malloc((1 + numwords) * sizeof(char *));
    if (!s)
        return (NULL);
    for (i = 0, j = 0; j < numwords; j++)
    {
        while (str[i] == d && str[i] != d)
            i++;
        k = 0;
        while (str[i + k] != d && str[i + k] && str[i + k] != d)
            k++;
        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return (NULL);
        }
        for (m = 0; m < k; m++)
            s[j][m] = str[i++];
        s[j][m] = 0;
    }
    s[j] = NULL;
    return (s);
}

/**
 * **free_grid - frees a 2 dimensional grid previously created
 * @grid: pointer to the grid to be freed
 * @height: height of the grid
 * Return: void
 */
void free_grid(char **grid, int height)
{
    int i;

    for (i = 0; i < height; i++)
        free(grid[i]);
    free(grid);
}
