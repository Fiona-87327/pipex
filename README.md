# 42Core_pipex

A C implementation of the Unix pipe mechanism, created as part of the 42 School curriculum. This project demonstrates process creation, inter-process communication (IPC) using pipes, and command execution.

## Overview

**Pipex** is a program that simulates the behavior of shell pipes (`|`) by taking input from one file, executing two commands in sequence with their output/input connected through a pipe, and writing the final output to another file.

The program mimics the following shell command:
```bash
< infile command1 | command2 > outfile
```

## Features

- **Process Management**: Creates child and parent processes using `fork()`
- **Pipe Communication**: Implements inter-process communication using Unix pipes
- **Command Execution**: Executes shell commands with proper argument parsing
- **File I/O**: Handles input/output file operations with appropriate error handling
- **Environment Variables**: Resolves command paths using the `PATH` environment variable
- **Error Handling**: Comprehensive error checking and reporting

## Project Structure

```
42Core_pipex/
├── src/
│   ├── pipex.c          # Main logic for pipe creation and process management
│   ├── pipex_exec.c     # Command execution functions
│   └── pipex_utils.c    # Utility functions (path resolution, memory management)
├── include/
│   └── pipex.h          # Header file with function prototypes
├── libft/               # Custom C library (libft) with utility functions
├── Makefile             # Build configuration
└── README.md            # This file
```

## Technical Details

### Main Functions

#### `pipex.c`
- **`main()`**: Entry point, validates arguments and calls `pp_pipex()`
- **`pp_pipex()`**: Creates two child processes, sets up pipes, and manages process lifecycle
- **`pp_child()`**: Child process that reads from input file and executes first command
- **`pp_parent()`**: Parent process that reads from pipe and executes second command
- **`p_error()`**: Error handler with `perror()` output

### Process Flow

```
┌─────────────┐
│   START     │
└──────┬──────┘
       │
       ▼
┌──────────────────┐
│ Create Pipe      │
└──────┬───────────┘
       │
       ├─────────────────────────────────────┐
       │                                     │
       ▼                                     ▼
┌──────────────┐                      ┌──────────────┐
│  Child Proc  │                      │ Parent Proc  │
│  (PID = 0)   │                      │  (PID > 0)   │
└──────┬───────┘                      └──────┬───────┘
       │                                     │
       │ Read from INFILE                    │ Read from PIPE
       │ Execute Command 1                   │ Execute Command 2
       │ Write to PIPE                       │ Write to OUTFILE
       │                                     │
       └─────────────────────────────────────┘
                    │
                    ▼
              ┌──────────────┐
              │ Wait for all │
              │   processes  │
              └──────────────┘
```

### Key Concepts

1. **Pipes**: Unidirectional communication channels between processes
   - `pipe_fd[0]`: Read end
   - `pipe_fd[1]`: Write end

2. **File Descriptors**: 
   - `STDIN_FILENO` (0): Standard input
   - `STDOUT_FILENO` (1): Standard output
   - `STDERR_FILENO` (2): Standard error

3. **Process Management**:
   - `fork()`: Creates child processes
   - `waitpid()`: Waits for child processes to complete
   - `dup2()`: Redirects file descriptors

4. **Command Resolution**:
   - Searches for executable commands in directories listed in `PATH`
   - Uses `execve()` to replace process image with command

## Building the Project

### Prerequisites

- GCC compiler
- Make
- Unix/Linux environment

### Compilation

```bash
make              # Compile the project
make clean        # Remove object files
make fclean       # Remove all generated files
make re           # Clean and recompile
```

### Usage

```bash
./pipex <infile> <command1> <command2> <outfile>
```

**Arguments:**
- `infile`: Input file to read from
- `command1`: First command to execute
- `command2`: Second command to execute
- `outfile`: Output file to write to (created if doesn't exist)

**Examples:**

```bash
# Equivalent to: cat infile.txt | grep "hello" > outfile.txt
./pipex infile.txt "cat" "grep hello" outfile.txt

# Equivalent to: < data.txt wc -l | sort > result.txt
./pipex data.txt "wc -l" "sort" result.txt

# Equivalent to: < file.txt ls -la | grep txt > output.txt
./pipex file.txt "ls -la" "grep txt" output.txt
```

## Implementation Details

### Memory Management

- Custom memory allocation and deallocation functions from libft
- Proper cleanup of dynamically allocated memory
- Attention to potential memory leaks

### Error Handling

- Validates command-line arguments (exactly 4 required)
- Checks file operations (open, read, write)
- Validates pipe creation and process forking
- Handles `execve()` failures gracefully
- Exit codes reflect command execution status

### Linked List Utilities (libft)

The project includes custom implementations of common C library functions:
- String manipulation: `ft_strdup()`, `ft_strlen()`
- Memory operations: `ft_memcpy()`, `ft_memmove()`
- Linked list operations: `ft_lstnew()`, `ft_lstadd_back()`, `ft_lstclear()`, `ft_lstlast()`
- Conversion functions: `ft_atoi()`
- I/O functions: `ft_putstr_fd()`, `ft_putnbr_fd()`, `ft_putchar_fd()`

## Learning Objectives

This project reinforces:
- ✅ Unix process creation and management (`fork`, `execve`, `waitpid`)
- ✅ Inter-process communication using pipes
- ✅ File descriptor manipulation (`dup2`, `open`, `close`)
- ✅ Environment variable handling
- ✅ C programming best practices
- ✅ Error handling and edge case management
- ✅ Memory management in C
- ✅ System call behavior and return values

## Bonus Features (if implemented)

Potential extensions:
- Multiple pipes (> 2 commands)
- Input/output redirection support
- Wildcard expansion
- Command options and flags
- Error messages improvements

## Author

**jiyawang** - 42 School Student  
Created: September 22, 2025  
Updated: October 21, 2025

## License

This project is part of the 42 School curriculum and follows school policies.

## References

- [pipe(2) - Linux man page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [fork(2) - Linux man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [execve(2) - Linux man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [dup2(2) - Linux man page](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [waitpid(2) - Linux man page](https://man7.org/linux/man-pages/man2/waitpid.2.html)

---

**Note:** For 42 School evaluation, ensure the project compiles with no warnings or errors and passes all mandatory requirements.
