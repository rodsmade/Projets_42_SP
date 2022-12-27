English 💂 | [Français 🥐](https://github.com/rodsmade/Projets_42_SP/blob/main/README_fr.md) | [Português 🌵](https://github.com/rodsmade/Projets_42_SP/blob/main/README_ptbr.md)

# 42sp Projects
All projects developed at 42 school in São Paulo, Brazil.

[![roaraujo's 42 stats](https://badge42.vercel.app/api/v2/cl1rzz1es023009l2v061r4ou/stats?cursusId=21&coalitionId=undefined)](https://github.com/JaeSeoKim/badge42)

- [42sp Projects](#42sp-projects)
- [What is 42](#what-is-42)
- [Programme Overview](#programme-overview)
	- [Phase 1](#phase-1)
	- [Phase 2](#phase-2)
	- [Phase 3](#phase-3)
- [How to clone this repo](#how-to-clone-this-repo)


# What is 42

> "The 42 program is a college-level software engineering/coding program in a professional environment. There are no classes, teachers, or courses: we use **project-based learning**, skills mastery, **peer-to-peer correction**, and **gamification** to foster learning. Major learning milestones are expressed as levels of experience rather than years; your individual experience sets the pace for learning."
_[Official brochure](https://www.42.us.org/wp-content/uploads/2020/01/42-Booklet-Spring-2020.pdf)_

![42 Galaxy - the programme](https://user-images.githubusercontent.com/49699403/143270052-c0215136-3d13-480c-944b-94a6d36d2ee2.png)


This constellation-like programme is divided into two main parts: the core branch of fundamentals (inner layers - a.k.a. the **common core**), and the complementary **specialization** paths (outermost layer) branching out into infinity and beyond.

The common core comprises 16 projects, covering the fundamentals of Computer Science, each project granting you new skills and experience points in order to beat the levels and progress towards the final boss: the great **Transcendence**.

![Visual representation of the 16 projects of the common core divided into 3 parts](https://user-images.githubusercontent.com/49699403/146021410-fdd95ceb-d3ce-436c-ba6f-c836d0d1a922.png)
_(Projects under the same number are candidates for that level, students must pick only one.)_

From that point on, students are orbiting the outermost reaches of the galaxy, free to choose which path to get a specialization at, or even create their own specialization path for other students to follow once they've cleared the common core.


# Programme Overview

At 42 São Paulo, the common core is split in 3 main parts, the first two being entirely built using C/Shell scripts, moving on to Object-Oriented Programming (OOP) with C++ and complementary front-end, back-end and containerisation technologies in the last phase.

## Phase 1

|   	|   	|   	|
|---	|---	|---	|
| **[libft](https://github.com/rodsmade/Libft-42sp)** 	| Static library, Makefile. 	| Build your own basic C static library, which will be used throughout the rest of the programme. The ```ft_*``` functions mostly mimic the behaviour of the traditional C functions, and must be written using at most ```write()``` and ```malloc()```.	|
| **[get_next_line](https://github.com/rodsmade/Get_Next_Line-42sp)** 	| File descriptors and static+dynamic memory allocation. 	| Read from a file descriptor and deliver one line, that is, a ```\n```-terminated string of chars. This project is later incorporated into Libft.	|
| **[ft_printf](https://github.com/rodsmade/Ft_Printf-42sp.git)** 	| Formatting string and variable args. 	| Build your own version of ```printf```! This project is later incorporated into Libft.	|
| **[Born2BeRoot](https://github.com/rodsmade/Born2BeRoot-42sp)** 	| Virtualisation. 	| Set up an SSH server running on Linux with basic system administration, strong password rules, encryption, and more.	|
| **[So_Long](https://github.com/rodsmade/So_long-42sp)** / fractol / fdf 	| Window rendering and keyboard+mouse events management. 	| First steps into rendering graphics on the screen! A choice between rendering either fractals (`fractol`), 3D wireframes (`fdf`) or a 2D top-down video game (`so_long`).	|
| minitalk / **[pipex](https://github.com/rodsmade/Pipex-42sp)** 	| An intro to Unix Processes in C. 	| A choice between having a client/server pair of processes exchanging data (`minitalk`), or simulating the pipe operator (`\|`) in Bash using C pipes and forks (`pipex`).	|


## Phase 2
|   	|   	|   	|
|---	|---	|---	|
| **[Push_Swap](https://github.com/rodsmade/Push_Swap-42sp.git)** 	| Sorting algorithms and stacks. 	| A list of unordered numbers must be taken in and sorted out, with a twist: the numbers must be sorted by means of using exactly `two stacks`, and a set of 11 stipulated stack operations.	|
| **[Minishell](https://github.com/rodsmade/Minishell-42sp)** 	| A minified version of a Bash shell written in C. 	| Including basic parsing of pipes and redirections, built-ins, and support for commands execution via $PATH or absolute paths.	|
| **[Philosophers](https://github.com/rodsmade/Philosophers-42sp)** 	| Multithreading in C. 	| Solving the famous dining philosophers problem proposed by Dijkstra.	|
| **Netpractice** 	| Networking and routing. 	| A set of problems simulating LAN's and networks with internet access. A basic understanding of IP addresses and routing tables is needed to solve each and every problem in under 15 minutes altogether.	|
| **[Cub3d](https://github.com/rodsmade/Cub3D-42sp)** / minirt 	| Raycasting (cub3d) and Raytracing (miniRT). 	| Deeper study of graphics computing using a LibX interface to code either of a raycasting or a raytracing engine.	|

## Phase 3
|   	|   	|   	|
|---	|---	|---	|
| **CPP Modules (OOP)**	| TBA.	| -	|
| **ft_containers**	| TBA.	| -	|
| **inception**	| TBA.	| -	|
| **webservices / ft_irc**	| TBA.	| -	|
| **Transcendence**	| TBA.	| -	|


# How to clone this repo
This repository contains git submodules, that is, links to other repositories where the source code for each project is stored separately. Simply `git clone`-ing this project leads to an almost empty folder. If you wish to clone this repo and all the contents from the other repos as well, add the `--recurse-submodules` flag to your `git clone` command, like so:

```
git clone --recurse-submodules https://github.com/rodsmade/Projets_42_SP.git
```

If you wish to clone the code for a specific project, simply click on the desired project's link in the folder structure above, and then clone it locally.

Thank you for being here! :wink: