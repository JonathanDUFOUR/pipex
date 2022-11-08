# pipex
![Project illustration](./illustration.png "Does anyone need a plumber ?")<br>
This project is the 5th of the 42 School cursus.

# Description
In this project, we must reimplement the shell pipes behavior, in C.<br>
The program must take at least 4 arguments:<br>
- The first argument is the name of the file to read from as stdin.<br>
- The last argument is the name of the file to write to as stdout.<br>
- The other arguments are the commands of the pipeline to run successively,
redirecting the stdout of each to the stdin of the next.<br>
