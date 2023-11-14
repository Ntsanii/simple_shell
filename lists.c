#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @list_head: address of pointer to head node
 * @str_val: str field of node
 * @node_num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **list_head, const char *str_val, int node_num)
{
    list_t *new_head;

    if (!list_head)
        return (NULL);
    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return (NULL);
    _memset((void *)new_head, 0, sizeof(list_t));
    new_head->num = node_num;
    if (str_val)
    {
        new_head->str = _strdup(str_val);
        if (!new_head->str)
        {
            free(new_head);
            return (NULL);
        }
    }
    new_head->next = *list_head;
    *list_head = new_head;
    return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @list_head: address of pointer to head node
 * @str_val: str field of node
 * @node_num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **list_head, const char *str_val, int node_num)
{
    list_t *new_node, *node;

    if (!list_head)
        return (NULL);

    node = *list_head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);
    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = node_num;
    if (str_val)
    {
        new_node->str = _strdup(str_val);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }
    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = new_node;
    }
    else
        *list_head = new_node;
    return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @node_ptr: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *node_ptr)
{
    size_t i = 0;

    while (node_ptr)
    {
        _puts(node_ptr->str ? node_ptr->str : "(nil)");
        _puts("\n");
        node_ptr = node_ptr->next;
        i++;
    }
    return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @list_head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **list_head, unsigned int index)
{
    list_t *node, *prev_node;
    unsigned int i = 0;

    if (!list_head || !*list_head)
        return (0);

    if (!index)
    {
        node = *list_head;
        *list_head = (*list_head)->next;
        free(node->str);
        free(node);
        return (1);
    }
    node = *list_head;
    while (node)
    {
        if (i == index)
        {
            prev_node->next = node->next;
            free(node->str);
            free(node);
            return (1);
        }
        i++;
        prev_node = node;
        node = node->next;
    }
    return (0);
}

/**
 * free_list - frees all nodes of a list
 * @list_head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **list_head_ptr)
{
    list_t *node, *next_node, *head;

    if (!list_head_ptr || !*list_head_ptr)
        return;
    head = *list_head_ptr;
    node = head;
    while (node)
    {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }
    *list_head_ptr = NULL;
}
