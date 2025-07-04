# 42cursus

**Started in: `2023-10-09`**

Every cursus' project will have it's own branch.

This branch (`master`) is used only to share useful information for projects.

---

## Project status

Checked: *`done`*

- [x] [libft: 125/125](https://github.com/Sandoramix/42cursus/tree/libft)
- [x] [ft_printf: 125/125](https://github.com/Sandoramix/42cursus/tree/ft_printf)
- [x] [get_next_line: 125/125](https://github.com/Sandoramix/42cursus/tree/get_next_line)
- [x] [Born2Beroot](https://github.com/Sandoramix/42cursus/tree/born2beroot)
- [x] [so_long: 125/125](https://github.com/Sandoramix/42cursus/tree/so_long)
- [x] [push_swap: 96/125](https://github.com/Sandoramix/42cursus/tree/push_swap)
- [x] [pipex: 125/125](https://github.com/Sandoramix/42cursus/tree/pipex)
- [x] [minishell: 101/125](https://github.com/Sandoramix/42-minishell)
- [x] [Philosophers: 100/125](https://github.com/Sandoramix/42cursus/tree/philosophers)
- [x] NetPractice: 100/100
- [x] [Cpp Module 00-09](https://github.com/Sandoramix/42cursus/tree/cpp-modules)
- [x] [cub3d: 120/125](https://github.com/Sandoramix/42-cub3d)
- [x] [Inception: 100/125](https://github.com/Sandoramix/42cursus/tree/inception)
- [x] [ft_irc: 115/125](https://github.com/Sandoramix/42-ft_irc)
- [ ] [ft_transcendence](#)

---

## 🚀 Utilities

### 📁 Useful Scripts

I made some simple but yet powerful scripts to speed up the workflow:

- [`getSrc.py`](./utils/getSrc.py):  
  🔍 **Auto-Generate Source Lists for Makefiles**  
  Recursively scans your project directory for `*.c` and `*_bonus.c` files, then writes them into convenient `SRC` and `SRC_BONUS` lists for your Makefile. Supports excluding directories, custom extensions, and output file naming!

- [`proToC.py`](./utils/proToC.py):  
  🧙 **Prototype-to-Source Magic**  
  Feed it a header file, and it will generate `.c` files with skeleton implementations for every function prototype found inside!

- [`grabProtos.py`](./utils/grabProtos.py):  
  🎯 **Extract Function Prototypes**  
  Scans your C source files and extracts all function prototypes, perfect for creating header files! Supports filtering static functions, excluding directories, and custom formatting.

---

Feel free to check out the scripts in the [`utils`](./utils/) folder for more workflow-boosting tools!

### ⚙️ VSCode Settings

I've rearranged some useful settings for making the user experience a little better on C projects in vscode.

All you need to do is to copy the [`.vscode`](.vscode) folder into your project.
