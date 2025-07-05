# linux-shell

A simple shell implemented in C.

### Features:

- Modular Code
- Color added for specific purposes.
- Proper handling of Ctrl+Z and Ctrl+C - similar to what happens in a normal terminal.
- Input/output redirection functionality.
- Command can be redirected using pipes as well as combination of pipes and I/O redirections.
- All basic features implemented.
  - Semicolon separated commands accepted
  - Builtin commmands like cd, echo, pwd.
  - Background and foreground processes.
  - ls command implemented separately
  - Exit and Quit commands for quitting the shell
  - fg <jobNumber> : brings a running or a stopped background job with given job number to foreground.
  - bg <jobNumber> : changes a stopped background job to a running background job.

### Building and Running

    cd linux-shell
    make
    ./mysh
