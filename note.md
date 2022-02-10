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
