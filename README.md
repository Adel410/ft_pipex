# Pipex

## Overview

**Pipex** is a project that aims to replicate the behavior of pipes in shell command lines. This implementation allows you to connect multiple commands together seamlessly, functioning much like the `|` operator in a typical Unix shell.

## How to Use

### Mandatory Part

To launch the program for the mandatory part, use the following command:

./pipex infile "ls -l" "wc -l" outfile

- **infile:** The input file that you want to read from.
- **"ls -l":** The first command to be executed, which lists files in long format.
- **"wc -l":** The second command that counts the number of lines from the output of the first command.
- **outfile:** The output file where the results will be written.

It will have the same behavior as :

< infile cmd1 | cmd2 > outfile

### Bonus Features

For the bonus part, you can execute multiple commands using the following syntax:

This behaves the same as:

< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

Additionally, the bonus includes implementing a heredoc functionality, executed like so:

./pipex here_doc LIMITER cmd cmd1 file

This behaves the same as:

cmd << LIMITER | cmd1 >> file

## Project Details

- **Functionality:** Recreates the pipe behavior, enabling data to flow between commands as if in a shell.
- **Score:** Achieved a score of **[your score here]**, reflecting successful implementation and functionality.

## Key Concepts

The **Pipex** project is a great exercise for anyone looking to deepen their knowledge of how command-line operations work under the hood.

