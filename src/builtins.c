#include "../shell.h"

int signal_z;

char *builtin_str[] = {
    "cd", "exit", "pwd",
    "echo", "quit", "ls",
    "fg", "bg"};
int (*builtin_func[])(char **) = {
    &builtin_cd, &builtin_exit, &builtin_pwd,
    &builtin_echo, &builtin_quit, &builtin_ls,
    &builtin_fg, &builtin_bg};
int builtins = 8;

int execute_builtins(char **args, int input, int output)
{
    int i = -1, ret = 0;
    while (++i < builtins)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            //we pass the whole command into builtin functions list
            ret = (*builtin_func[i])(args);
            break;
        }
    }
    return ret;
}

int builtin_exit(char **args)
{
    exit(EXIT_SUCCESS);
}

int builtin_quit(char **args)
{
    exit(EXIT_SUCCESS);
}

int builtin_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "mysh: expected argument to \"cd\"\n");
        fprintf(stderr, "mysh: type \"cd\" --help for learn proper usage\n");
    }
    else
    {
        if (strcmp(args[1], "--help") == 0)
        {
            printf("Usage: cd <path to directory>\n");
        }
        else
        {
            char *temp = get_absolute_path(args[1]);
            if (chdir(temp) != 0)
            {
                perror("mysh");
            }
        }
    }
    return 1;
}

int builtin_pwd(char **args)
{
    char *pwd = (char *)malloc(1024);
    getcwd(pwd, (size_t)1024);
    printf("%s\n", pwd);
    return 1;
}

int builtin_echo(char **args)
{
    int i = 0;
    while (args[++i] != NULL)
    {
        char *words = args[i];
        if (words[0] == '$')
        {
            char *var = words + 1;
            char *value = getenv(var);
            if (!value)
                printf("%s ", words);
            else
                printf("%s ", value);
        }
        else
            printf("%s ", words);
    }
    printf("\n");
    return 1;
}

