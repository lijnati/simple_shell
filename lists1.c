#include "shell.h"

/**
 * count_nodes - counts the number of nodes in a linked list
 * @head: pointer to the first node
 * Return: number of nodes in the list
 */
size_t count_nodes(const list_t *head)
{
    size_t count = 0;
    for (const list_t *node = head; node != NULL; node = node->next) {
        count++;
    }
    return count;
}

/**
 * list_to_array - converts a linked list of strings to an array of strings
 * @head: pointer to the first node
 * Return: array of strings
 */
char **list_to_array(list_t *head)
{
    size_t len = count_nodes(head);
    if (len == 0) {
        return NULL;
    }

    char **strings = malloc(sizeof(char *) * (len + 1));
    if (strings == NULL) {
        return NULL;
    }

    size_t i = 0;
    for (list_t *node = head; node != NULL; node = node->next) {
        size_t str_len = _strlen(node->str);
        char *str = malloc(str_len + 1);
        if (str == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            return NULL;
        }

        _strcpy(str, node->str);
        strings[i] = str;
        i++;
    }

    strings[i] = NULL;
    return strings;
}

/**
 * print_list - prints all elements of a linked list
 * @head: pointer to the first node
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *head)
{
    size_t count = 0;
    for (const list_t *node = head; node != NULL; node = node->next) {
        _puts(convert_number(node->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(node->str ? node->str : "(nil)");
        _puts("\n");
        count++;
    }
    return count;
}

/**
 * find_node - finds the first node in the list whose string starts with the given prefix
 * @head: pointer to the first node
 * @prefix: prefix to match
 * @next_char: character to match after the prefix
 * Return: pointer to the matching node or NULL if no match found
 */
list_t *find_node(list_t *head, char *prefix, char next_char)
{
    for (list_t *node = head; node != NULL; node = node->next) {
        char *match = starts_with(node->str, prefix);
        if (match != NULL && (next_char == -1 || *match == next_char)) {
            return node;
        }
    }
    return NULL;
}

/**
 * get_node_index - gets the index of a node in the list
 * @head: pointer to the first node
 * @node: pointer to the node to find the index of
 * Return: index of the node or -1 if the node is not found in the list
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
    ssize_t index = 0;
    for (list_t *n = head; n != NULL; n = n->next) {
        if (n == node) {
            return index;
        }
        index++;
    }
    return -1;
}
