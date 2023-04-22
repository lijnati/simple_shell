#include "shell.h"

/**
 * Determines if a given file path corresponds to an executable command.
 *
 * @param info The info struct.
 * @param path The path to check.
 * @return 1 if the path corresponds to an executable command, 0 otherwise.
 */
int is_cmd(info_t *info, char *path) {
    struct stat st;
    (void)info;

    if (!path || stat(path, &st) != 0)
        return 0;

    return st.st_mode & S_IFREG;
}

/**
 * Duplicates a substring of a given string.
 *
 * @param pathstr The string to copy from.
 * @param start The index of the first character to copy.
 * @param stop The index of the last character to copy (excluded).
 * @return A newly allocated string that contains the specified substring.
 */
char *dup_chars(char *pathstr, int start, int stop) {
    static char buf[1024];
    int i, k;

    for (i = start, k = 0; i < stop && pathstr[i] != '\0'; i++)
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];

    buf[k] = '\0';
    return buf;
}

/**
 * Searches for the full path of a command by looking into the directories
 * listed in the PATH environment variable.
 *
 * @param info The info struct.
 * @param pathstr The value of the PATH environment variable.
 * @param cmd The command to look for.
 * @return The full path of the command, or NULL if not found.
 */
char *find_path(info_t *info, char *pathstr, char *cmd) {
    int i, curr_pos;
    char *path;

    if (!pathstr)
        return NULL;

    if (_strlen(cmd) > 2 && starts_with(cmd, "./")) {
        if (is_cmd(info, cmd))
            return cmd;
    }

    for (i = 0, curr_pos = 0; pathstr[i] != '\0'; i++) {
        if (pathstr[i] == ':') {
            path = dup_chars(pathstr, curr_pos, i);
            if (*path == '\0')
                _strcat(path, cmd);
            else
                _strcat(path, "/");
            _strcat(path, cmd);

            if (is_cmd(info, path))
                return path;

            curr_pos = i + 1;
        }
    }

    return NULL;
}
