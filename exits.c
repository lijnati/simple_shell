/**
 * _strncpy - Copy a string
 * @dest: Destination string to copy to
 * @src: Source string to copy from
 * @n: Number of characters to copy
 *
 * Return: A pointer to the concatenated string
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
    char *dest_start = dest;

    while (*src && n--)
    {
        *dest++ = *src++;
    }

    while (n--)
    {
        *dest++ = '\0';
    }

    return dest_start;
}

/**
 * _strncat - Concatenate two strings
 * @dest: First string
 * @src: Second string
 * @n: Maximum number of bytes to use
 *
 * Return: A pointer to the concatenated string
 */
char *_strncat(char *dest, const char *src, size_t n)
{
    char *dest_start = dest;

    while (*dest)
    {
        dest++;
    }

    while (*src && n--)
    {
        *dest++ = *src++;
    }

    *dest = '\0';

    return dest_start;
}

/**
 * _strchr - Locate a character in a string
 * @s: String to search in
 * @c: Character to look for
 *
 * Return: A pointer to the first occurrence of the character, or NULL if not found
 */
char *_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == c)
        {
            return (char *)s;
        }

        s++;
    }

    if (*s == c)
    {
        return (char *)s;
    }

    return NULL;
}

