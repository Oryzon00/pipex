A lire:
- tuto pipex (medium)
- code vault youtube fork pipe
- exec ve

Format execution:
./pipex infile cmd1 cmd2 outfile
Doit reproduire le comportement de:
< infile cmd1 | cmd2 > outfile


// each cmd needs a stdin (input) and returns an output (to stdout)
   

CHILD PROCESS												 PARENT PROCESS
    infile                                            			 outfile
as stdin for cmd1                                 			as stdout for cmd2            
       |                        PIPE                        		↑
       |           |---------------------------|            		|
       ↓             |                       |              		|
      cmd1   -->    pont/end[1]       ↔       pont/end[0]   -->     cmd2           
                     |                       |
            cmd1   |---------------------------|  end[0]
           output                             reads end[1]
         is written                          and sends cmd1
          to end[1]                          output to cmd2
       (end[1] becomes                      (end[0] becomes 
        cmd1 stdout)                           cmd2 stdin)





static char *ft_get_path(char **env)
{
    char    *res;
    int        i;

    i = 0;
    while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
        i++;
    if (env[i] == NULL)
        return (NULL);
    res = ft_strdup(env[i]);
    if (res == NULL)
        return (NULL);
    return (res);
}

static int ft_check_path(char *path)
{
    char    **splitted;
    char    **start;
    int        i;

    i = 0;
    if (ft_strchr(path, ':') == NULL)
    {
        if (access(path + 5, F_OK) != 0)
            return (0);
        return (1);
    }
    splitted = ft_split(path, ':');
    if (splitted == NULL)
        return (0);
    start = splitted;
    splitted = splitted + 5;
    while (splitted[i] != NULL)
    {
        if (access(splitted[i], F_OK) != 0)
        {
            ft_free_split(start);
            return (0);
        }
        i++;
    }
    ft_free_split(start);
    return (1);
}
















Liste des fd opens pour linux:
ls -la /proc/$$/fd

fonctions autorises:
-access
-open
-unlink
-close
-read
-write
-malloc
-waitpid
-wait
-free
-pipe
-dup
-dup2
-execve
-fork
-perror
-strerror
-exit





Bonus:
- plusieurs pipes
- gerer "et" lorsque 1er param = here_doc ?
