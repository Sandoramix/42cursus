# 42cursus

**Started in: `2023-10-09`**

Every cursus' project will have it's own branch.

This branch (`master`) is used only to share useful information for projects.

---

## Project status

Checked: *`done`*

- [x] [libft<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/94a9fac7-a6a1-43b8-b80f-f20e3f65c8bf" style="height: 160px;object-fit: scale-down;">](https://github.com/Sandoramix/42cursus/tree/libft)
- [x] [ft_printf<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/6b116105-06d1-4915-98bd-6355513e55d6" style="height: 160px;object-fit: scale-down;">](https://github.com/Sandoramix/42cursus/tree/ft_printf)
- [x] [get_next_line<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/8485fb9f-0ef5-47b0-a663-3cfcf90bf989" style="height: 160px;object-fit: scale-down;">](https://github.com/Sandoramix/42cursus/tree/get_next_line)
- [x] [so_long<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/73b400a6-2203-4cba-ac40-64c1101ed8d9" style="height: 160px;object-fit: scale-down;">](https://github.com/Sandoramix/42cursus/tree/so_long)
- [x] WIP [push_swap<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/8eb95aed-9656-4290-bf6f-daae6bd4989a" style="height: 160px;object-fit: scale-down;">](https://github.com/Sandoramix/42cursus/tree/push_swap)
- [x] [Pipex<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/a2d0edf2-34d0-4b77-acfb-2c22e74f1ff0" style="height: 160px; object-fit: scale-down;">](https://github.com/Sandoramix/42cursus/tree/pipex)
- [x] [minishell<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/5887671f-ed72-4fbb-9da9-3147591f63bd" style="height: 160px; object-fit: scale-down;">](https://github.com/Sandoramix/42-minishell)
- [x] [Philosophers<br><img src="https://github.com/Sandoramix/42cursus/assets/70036883/80879259-f272-4943-aa88-0539eb7cc934" style="height: 160px; object-fit: scale-down;">](https://github.com/Sandoramix/42cursus/tree/philosophers)

---

### Utilities

#### VSCode settings

I've rearranged some useful settings for making the user experience a little better on C projects in vscode.

All you need to do is to copy the [`.vscode`](.vscode) folder into your project.

#### Scripts
I made some simple but yet useful scripts to speed up the workflow:

- [`proToC.py`]("./utils/proToC.py"): convert every prototype inside a header file to it's own `.c` file with it's implemented function
- [`getSrc.py`]("./utils/getSrc.py"): get all filenames that end with `*_bonus.c` and `*.c` and create the list of `SRC` and `SRC_BONUS` for your Makefile
