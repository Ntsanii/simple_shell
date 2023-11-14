#include "shell.h"

/**
 * list_length - determines length of linked list
 * @current_node: pointer to first node
 *
 * Return: size of list
 */
size_t list_length(const list_t *current_node)
{
    size_t count = 0;

    while (current_node)
    {
        current_node = current_node->next;
        count++;
    }
    return (count);
}

/**
 * list_to_strings - returns an array of strings of the node->str
 * @list_head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *list_head)
{
    list_t *current_node = list_head;
    size_t list_size = list_length(list_head), index;
    char **string_array;
    char *string_value;

    if (!list_head || !list_size)
        return (NULL);

    string_array = malloc(sizeof(char *) * (list_size + 1));

    if (!string_array)
        return (NULL);

    for (index = 0; current_node; current_node = current_node->next, index++)
    {
        string_value = malloc(_strlen(current_node->str) + 1);

        if (!string_value)
        {
            for (size_t j = 0; j < index; j++)
                free(string_array[j]);
            free(string_array);
            return (NULL);
        }

        string_value = _strcpy(string_value, current_node->str);
        string_array[index] = string_value;
    }

    string_array[index] = NULL;
    return (string_array);
}

/**
 * print_list - prints all elements of a list_t linked list
 * @current_node: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *current_node)
{
    size_t count = 0;

    while (current_node)
    {
        _puts(convert_number(current_node->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(current_node->str ? current_node->str : "(nil)");
        _puts("\n");
        current_node = current_node->next;
        count++;
    }
    return (count);
}

/**
 * find_node_starts_with - returns node whose string starts with prefix
 * @list_head: pointer to list head
 * @prefix: string to match
 * @next_char: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *find_node_starts_with(list_t *list_head, char *prefix, char next_char)
{
    char *matching_prefix = NULL;

    while (list_head)
    {
        matching_prefix = starts_with(list_head->str, prefix);
        if (matching_prefix && ((next_char == -1) || (*matching_prefix == next_char)))
            return list_head;
        list_head = list_head->next;
    }
    return NULL;
}

/**
 * get_node_index - gets the index of a node
 * @head_node: pointer to list head
 * @target_node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head_node, list_t *target_node)
{
    size_t index = 0;

    while (head_node)
    {
        if (head_node == target_node)
            return index;
        head_node = head_node->next;
        index++;
    }
    return -1;
}



