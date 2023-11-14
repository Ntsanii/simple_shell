#include "shell.h"

/**
 * is_executable - determines if a file is an executable command
 * @shell_info: the shell_info struct
 * @file_path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_executable(shell_info_t *shell_info, char *file_path)
{
    struct stat file_stat;

    (void)shell_info;
    if (!file_path || stat(file_path, &file_stat))
        return (0);

    if (file_stat.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/**
 * duplicate_chars - duplicates characters
 * @path_string: the PATH string
 * @start_index: starting index
 * @stop_index: stopping index
 *
 * Return: pointer to a new buffer
 */
char *duplicate_chars(char *path_string, int start_index, int stop_index)
{
    static char buffer[1024];
    int i = 0, k = 0;

    for (k = 0, i = start_index; i < stop_index; i++)
        if (path_string[i] != ':')
            buffer[k++] = path_string[i];
    buffer[k] = 0;
    return (buffer);
}

/**
 * find_command_path - finds the command in the PATH string
 * @shell_info: the shell_info struct
 * @path_string: the PATH string
 * @command: the command to find
 *
 * Return: full path of the command if found or NULL
 */
char *find_command_path(shell_info_t *shell_info, char *path_string, char *command)
{
    int i = 0, current_pos = 0;
    char *path;

    if (!path_string)
        return (NULL);
    if ((_strlen(command) > 2) && starts_with(command, "./"))
    {
        if (is_executable(shell_info, command))
            return (command);
    }
    while (1)
    {
        if (!path_string[i] || path_string[i] == ':')
        {
            path = duplicate_chars(path_string, current_pos, i);
            if (!*path)
                _strcat(path, command);
            else
            {
                _strcat(path, "/");
                _strcat(path, command);
            }
            if (is_executable(shell_info, path))
                return (path);
            if (!path_string[i])
                break;
            current_pos = i;
        }
        i++;
    }
    return (NULL);
}
