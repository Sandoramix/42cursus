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
- [x] [so_long: 125/125](https://github.com/Sandoramix/42cursus/tree/so_long)
- [x] WIP [push_swap: 96/125](https://github.com/Sandoramix/42cursus/tree/push_swap)
- [x] [Pipex: 125/125](https://github.com/Sandoramix/42cursus/tree/pipex)
- [x] [minishell: 101/125](https://github.com/Sandoramix/42-minishell)
- [x] [Philosophers: 100/125](https://github.com/Sandoramix/42cursus/tree/philosophers)

---

### Utilities

#### VSCode settings

I've rearranged some useful settings for making the user experience a little better on C projects in vscode.

All you need to do is to copy the [`.vscode`](.vscode) folder into your project.

#### Scripts
I made some simple but yet useful scripts to speed up the workflow:

- [`proToC.py`]("./utils/proToC.py"): convert every prototype inside a header file to it's own `.c` file with it's implemented function
- [`getSrc.py`]("./utils/getSrc.py"): get all filenames that end with `*_bonus.c` and `*.c` and create the list of `SRC` and `SRC_BONUS` for your Makefile
