Simple Shell

The Simple Shell is a basic command-line interpreter that allows you to execute commands in a simple
and straightforward manner. It provides a prompt where you can enter commands, and it executes them accordingly.
Here are the features and functionalities of the Simple Shell:

Features

    Prompt Display: The Simple Shell displays a prompt symbol to indicate that it is ready to receive a command. After executing a command, the prompt is displayed again, waiting for the next command.

    Simple Command Lines: The command lines in the Simple Shell are simple and restricted to a single word. No semicolons, pipes, redirections, or any other advanced features are supported.

    Command Execution: The Simple Shell executes the entered command.
	If the command is valid and can be found, it is executed accordingly.

    Error Handling: If an executable cannot be found or if there is an error during the execution of a command, the Simple Shell displays an error message and continues to display the prompt, allowing you to enter another command.

    End of File Handling: The Simple Shell handles the "end of file" condition, triggered by pressing Ctrl+D. When this condition occurs, the Shell gracefully exits.

    Command Lines with Arguments: The Simple Shell supports command lines with arguments. You can pass arguments to programs within the command line.

    PATH Handling: The Simple Shell handles the PATH environment variable, allowing you to execute commands located in directories specified in the PATH.

    Built-in Commands:
        exit: The Simple Shell implements the exit built-in command, which allows you to exit the Shell.
        env: The Simple Shell implements the env built-in command, which prints the current environment.

    Comment Handling: The Simple Shell handles comments denoted by the '#' symbol. Any text following the '#' symbol in a command line is considered a comment and is ignored during command execution.

Usage

To use the Simple Shell, follow these steps:

    Launch the Simple Shell application.
    A prompt symbol will be displayed, indicating that the Shell is ready to receive a command.
    Enter your desired command. Remember to follow the rules of simple command lines specified above.
    Press Enter to execute the command.
    If the command is valid and can be executed, the Shell will perform the corresponding action.
    After executing the command, the prompt symbol will be displayed again, waiting for the next command.
    To exit the Shell, use the exit command or press Ctrl+D.

Please note that the Simple Shell is a minimalistic implementation and does not support advanced features found in more comprehensive shell environments.

Enjoy using the Simple Shell!
