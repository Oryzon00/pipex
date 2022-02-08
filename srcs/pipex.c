/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:43:31 by ajung             #+#    #+#             */
/*   Updated: 2022/02/08 21:12:15 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"





int	left_side(int infile, int *pont, char *cmd1, char **envp)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		return (EXIT_FAILURE);	
	if (dup2(pont[1], STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pont[0]); //on ferme autre cote du pont;
	close(infile); //il faut fermer ce qu'on ouvre

	//execve des paths

	//Si on arrive la, c'est que execve n'a pas marche et donc c'est un failure;
	return(EXIT_FAILURE);
}

int	right_side(int outfile, int *pont, char *cmd2, char **envp)
{
	int	status;

	if (dup2(outfile, STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	if (dup2(pont[0], STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(pont[1]); //on ferme autre cote du pont
	close(outfile);
	
	//execve fuction for paths

	//Si on arrive la c'est que execve a pas bien marche;
	return (EXIT_FAILURE);
}

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int 	pont[2];
	int		status;
	pid_t	child_left;
	pid_t	child_right;

	pipe(pont);
	child_left = fork();
	if (child_left < 0)
		return (perror("Fork: "));
	if (child_left == 0)
		left_side(infile, pont, argv[1], envp);
		//if LEFT_SIde == EXIT FAILURE --> lancer clean + fermeture programme	}
	waitpid(child_left, &status, 0); //on attends que left soit fini pour recuperer
									// l'output dans pont[0]
	child_right = fork();
	if (child_right < 0)
		return (perror("Fork: "));
	if (child_right == 0)
		right_side(outfile, pont, argv[4], envp);
		//if RIGHT_SIDE == EXIT FAILURE --> lancer clean + fermeture programme
	close(pont[0]); //on ferme le pont --> parent ne fait rien
	close(pont[1]);
	waitpid(child_left, &status, 0); //on attends que les enfants est fini leurs taches
	waitpid(child_right, &status, 0);
}
