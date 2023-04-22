#include "shell.h"

/**
 * Copies a string.
 * 
 * @param dest The destination.
 * @param src The source.
 * @return Pointer to destination.
 */
char *_strcpy(char *dest, char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

/**
 * Duplicates a string.
 *
 * @param str The string to duplicate.
 * @return Pointer to the duplicated string.
 */
char *_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    size_t len = strlen(str) + 1;
    char *ret = malloc(len);
    if (ret == NULL) {
        return NULL;
    }
    memcpy(ret, str, len);
    return ret;
}

/**
 * Prints an input string.
 *
 * @param str The string to be printed.
 */
void _puts(char *str) {
    if (str == NULL) {
        return;
    }
    for (size_t i = 0; str[i] != '\0'; ++i) {
        _putchar(str[i]);
    }
}

/**
 * Writes the character c to stdout.
 *
 * @param c The character to print.
 * @return On success 1. On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c) {
    static int i;
    static char buf[WRITE_BUF_SIZE];
    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
        write(1, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH) {
        buf[i++] = c;
    }
    return 1;
}
