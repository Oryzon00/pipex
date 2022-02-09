

//#include "../includes/pipex.h"
# include "libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
char	*PATH_envp;
char	**cmd_paths;
int		i;

i = 0;
while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
	i++;
PATH_envp = ft_strdup(envp[i]);
if (PATH_envp == NULL)
	printf("Error1");
cmd_paths = ft_split(PATH_envp + 5, ':');
if (cmd_paths == NULL)
	printf("Error2");
free(PATH_envp);
i = 0;
while (cmd_paths[i])
	printf("%s\n", cmd_paths[i++]);
}
