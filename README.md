```diff
+ ███╗   ███╗ █████╗ ██████╗  ██╗██████╗  █████╗ ███████╗██╗  ██╗
+ ████╗ ████║██╔══██╗██╔══██╗███║██╔══██╗██╔══██╗██╔════╝██║  ██║
+ ██╔████╔██║███████║██████╔╝╚██║██████╔╝███████║███████╗███████║
+ ██║╚██╔╝██║██╔══██║██╔══██╗ ██║██╔══██╗██╔══██║╚════██║██╔══██║
+ ██║ ╚═╝ ██║██║  ██║██║  ██║ ██║██████╔╝██║  ██║███████║██║  ██║
+ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
+ ---------------------------------------------------------------
```

# mar1bash

A lightweight, simple and custom Unix shell implementation written in C with readline support and command history.

## 🚀 Features

- **Interactive Command Line**: Built with GNU readline for advanced line editing and history
- **Built-in Commands**: `cd`, `exit` with proper error handling
- **External Commands**: Execute any system command via `execvp`
- **Signal Handling**: Graceful SIGINT (Ctrl+C) handling
- **Colorful Prompt**: Displays username and current directory with ANSI color codes
- **Path Abbreviation**: Shows `~` for home directory in prompt
- **Command History**: Navigate through previous commands with arrow keys
- **Memory Safe**: Custom wrappers for malloc/realloc with error checking

## 📋 Prerequisites

- GCC compiler
- GNU readline library
- Make build system

Install readline on Debian/Ubuntu:

```bash
sudo apt-get install libreadline-dev
```

## 🔧 Building

Build the project using make:

```bash
make
```

Clean build artifacts:

```bash
make clean
```

## 🎯 Usage

Run the shell:

```bash
./bin/mar1bash
```

Exit the shell:

- Type `exit` and press Enter
- Press `Ctrl+D` (EOF)
- Press `Ctrl+C` (SIGINT)

## 📁 Project Structure

```
mar1bash/
├── include/                    # Header files
│   ├── main.h                  # Function declarations and includes
│   ├── colors.h                # ANSI color code definitions
│   └── constants.h             # Global constants
├── src/                        # Source files
│   ├── main.c                  # Main shell loop
│   ├── builtins/               # Built-in command implementations
│   │   ├── changeDirectory.c
│   │   ├── executeBuiltin.c
│   │   └── exitShell.c
│   └── utils/                  # Utility functions
│       ├── executeCommand.c    # Fork and exec external commands
│       ├── functions.c         # Helper functions (malloc wrappers, etc.)
│       ├── getCWD.c            # Get current working directory
│       ├── interpretArgs.c     # Parse and route commands
│       ├── lineTokenizer.c     # Split input into tokens
│       ├── readShellLine.c     # Read user input with readline
│       └── signals.c           # Signal handler
├── obj/                        # Compiled object files (auto-generated)
├── bin/                        # Final executable (auto-generated)
└── Makefile                    # Build configuration

```

### Adding New Built-in Commands

1. Implement the command function in `src/builtins/`
2. Add the prototype to `include/main.h`
3. Register it in the `builtinCommands` array in `executeBuiltin.c`

## 🐛 Known Limitations

- No pipe (`|`) or redirection (`>`, `<`) support
- No background process support (`&`)
- No command substitution or environment variable expansion
- The `cd -` (previous directory) feature is not yet implemented

I'm actively working on these features for future releases.

## 📄 License

See [LICENSE](LICENSE) file for details.

---

<p align="center">Made with ❤️ by mar1shell</p>
