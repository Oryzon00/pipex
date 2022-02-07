/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:43:31 by ajung             #+#    #+#             */
/*   Updated: 2022/02/07 21:31:36 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2)
{
	int 	pont[2];
	pid_t	parent;

	pipe(pont);
	parent = fork();
	if (parent < 0)
	{
		perror("Fork: ");
		return ;
	}
	if (parent == 0)
	{
        //child_process(f1, cmd1);
		//pont[1] is child process
		// For the child process, we want infile to be our stdin (we want it as input), 
		// and end[1] to be our stdout (we want to write to end[1] the output of cmd1, 
		// so that the parent will be able to read it).

		//child writes, parent reads
	
	}
	else
	{
		//child_process(f1, cmd1);
		//pont[0] is the parent process;
		// In the parent process, we want end[0] to be our stdin (end[0] at this point has already read 
		// from end[1] the output of cmd1), and outfile to be our stdout (we want to write to it the output 
		// of cmd2).

		//child writes, parent reads


	}
		
}


# child_process(f1, cmd1);
// add protection if dup2() < 0
// dup2 close stdin, f1 becomes the new stdin
dup2(f1, STDIN_FILENO); // we want f1 to be execve() input
dup2(end[1], STDOUT_FILENO); // we want end[1] to be execve() stdout
close(end[0]) # --> always close the end of the pipe you don't use,
                    as long as the pipe is open, the other end will 
                    be waiting for some kind of input and will not
                    be able to finish its process
close(f1)
// execve function for each possible path (see below)
exit(EXIT_FAILURE);



//FIRST write, then read!
//--> child first, then parent

//     infile                                             outfile
// as stdin for cmd1                                 as stdout for cmd2            
//        |                        PIPE                        ↑
//        |           |---------------------------|            |
//        ↓             |                       |              |
//       cmd1   -->    end[1]       ↔       end[0]   -->     cmd2           
//                      |                       |
//             cmd1   |---------------------------|  end[0]
//            output                             reads end[1]
//          is written                          and sends cmd1
//           to end[1]                          output to cmd2
//        (end[1] becomes                      (end[0] becomes 
//         cmd1 stdout)                           cmd2 stdin)
