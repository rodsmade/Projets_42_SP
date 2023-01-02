[Português 🌵](https://github.com/rodsmade/Projets_42_SP/) | English 💂

# 42sp Projects
All projects developed at 42 school in São Paulo, Brazil.

[![roaraujo's 42 stats](https://badge42.vercel.app/api/v2/cl1rzz1es023009l2v061r4ou/stats?cursusId=21&coalitionId=undefined)](https://github.com/JaeSeoKim/badge42)

### Table of Contents
- [What is 42](#what-is-42)
- [Programme Overview](#programme-overview)
	- [Phase 1](#phase-1)
	- [Phase 2](#phase-2)
	- [Phase 3](#phase-3)
- [How to clone this repo](#how-to-clone-this-repo)


# What is 42

> *"There are no classes, teachers, or courses: we use **project-based learning**, skills **mastery**, **peer-to-peer correction**, and **gamification** to foster learning. Major learning milestones are expressed as levels of experience rather than years; your individual experience sets the pace for learning."*
_[Official brochure](https://www.42.us.org/wp-content/uploads/2020/01/42-Booklet-Spring-2020.pdf)_

![42 Galaxy - the holy graph](https://user-images.githubusercontent.com/49699403/209717594-ea05be2d-14d7-42e1-a4db-22ea612d251c.png)


This constellation-like programme is divided into two main parts: the core branch of fundamentals (inner layers - a.k.a. the **common core**), and the complementary **specialization** paths (outermost layer) branching out into infinity and beyond.

The common core comprises 16 projects, covering the fundamentals of Computer Science, each project granting you new skills and experience points in order to beat the levels and progress towards the final boss: the great **Transcendence**.

![Visual representation of the 16 projects of the common core divided into 3 parts](https://user-images.githubusercontent.com/49699403/146021410-fdd95ceb-d3ce-436c-ba6f-c836d0d1a922.png)
_(Projects under the same number are candidates for that level, students must pick only one.)_

From that point on, students are orbiting the outermost reaches of the galaxy, free to choose which path to get a specialization at, or even create their own specialization path for other students to follow once they've cleared the common core.


# Programme Overview

At 42 São Paulo, the common core is split in 3 main parts, the first two being entirely built using C/Shell scripts, moving on in the 3rd part to Object-Oriented Programming (OOP) with C++ and complementary front-end, back-end and containerisation technologies.

All projects in phase 1 are individual deliberables. Starting in phase 2, for some projects students must team up in pairs or groups and work together to learn and solve problems. Group projects are marked with a :restroom:.

## Phase 1

|   	|   	|   	|
|---	|---	|---	|
| **[libft](https://github.com/rodsmade/Libft-42sp)** 	| Static library, Makefile. 	| Build your own basic C static library, which will be used throughout the rest of the programme. Some of the ```ft_*``` functions mostly mimic the behaviour of the traditional C functions, while others are custom-made. All functions must be written using at most ```write()``` and ```malloc()```.	|
| **[get_next_line](https://github.com/rodsmade/Get_Next_Line-42sp)** 	| File descriptors and static+dynamic memory allocation. 	| Read from a file descriptor and deliver one line, that is, a ```\n```-terminated string of chars. This project is later incorporated into Libft.	|
| **[ft_printf](https://github.com/rodsmade/Ft_Printf-42sp.git)** 	| Formatting string and variable args. 	| Build your own version of ```printf```! This project is later incorporated into Libft.	|
| **[Born2BeRoot](https://github.com/rodsmade/Born2BeRoot-42sp)** 	| Virtualisation. 	| Set up an SSH server running on Linux with basic system administration, strong password rules, encryption, and more.	|
| **[So_Long](https://github.com/rodsmade/So_long-42sp)** / fractol / fdf 	| Window rendering and keyboard+mouse events management. 	| First steps into rendering graphics on the screen! A choice between rendering either fractals (`fractol`), 3D wireframes (`fdf`) or a 2D top-down video game (`so_long`). The proprietary Minilibx library (an X11 API) is used in these projects.	|
| **[pipex](https://github.com/rodsmade/Pipex-42sp)** / minitalk 	| An intro to Unix Processes in C. 	| A choice between having a client/server pair of processes exchanging data (`minitalk`), or simulating the pipe operator (`\|`) in Bash using C pipes and forks (`pipex`).	|


## Phase 2
|   	|   	|   	|
|---	|---	|---	|
| **[Push_Swap](https://github.com/rodsmade/Push_Swap-42sp.git)** 	| Sorting algorithms and stacks. 	| A list of unordered numbers must be taken in and sorted out, with a twist: the numbers must be sorted by means of using exactly `two stacks`, and a set of 11 stipulated stack operations.	|
| **[Minishell](https://github.com/rodsmade/Minishell-42sp)** :restroom: 	| A minified version of a Bash shell written in C. 	| Including basic parsing of pipes and redirections, built-ins, and support for commands execution via `$PATH` or absolute paths.	|
| **[Philosophers](https://github.com/rodsmade/Philosophers-42sp)** 	| Multithreading in C. 	| Solving the famous dining philosophers problem proposed by Dijkstra, avoiding data races and deadlocks.	|
| **Netpractice** 	| Networking and routing. 	| A set of problems simulating LAN's and networks with Internet access. A basic understanding of IP addresses and routing tables is needed to solve each and every problem in under 15 minutes altogether.	|
| **[Cub3d](https://github.com/rodsmade/Cub3D-42sp)** / miniRT :restroom: 	| Raycasting and Raytracing 	| Deeper study of graphics computing using a LibX interface to code either of a raycasting (`cub3d`) or a raytracing (`miniRT`) engine.	|

## Phase 3
|   	|   	|   	|
|---	|---	|---	|
| **CPP**	| Object Oriented Programming.	| 9 sets of exercises to guide a hands-on study on classical OOP concepts.	|
| **ft_containers**	| Classical data structures	| Build your own replica of selected C++ Standard Library containers: vectors, maps, stacks and black-red binary trees, implementing class definitions, iterators, operators overload and more.	|
| **inception**	| Containerisation of a simple web application.	| Using `docker-compose` and `Dockerfile`, students must set up a network with services needed to run a Wordpress server (including static html files and a database).	|
| **webserv / ft_irc** :restroom:	| Internet Protocols in C++.	| Either build an HTTP server to serve a static file (`webserv`) or build an IRC server running over TCP/IP (`ft_irc`). 	|
| **Transcendence** :restroom:	| Play the renowned Pong game online with friends!	| Teams must deploy a web application where any 42 student can log in and pair up with another student to play a live Pong match. The webapp must also broadcast current matches and allow for friends lists, achievements and more.	|


# How to clone this repo
This repository contains git submodules, that is, links to other repositories where the source code for each project is stored separately. Simply `git clone`-ing this project leads to an almost empty folder. If you wish to clone this repo and all the contents from the other repos as well, add the `--recurse-submodules` flag to your `git clone` command, like so:

```
git clone --recurse-submodules https://github.com/rodsmade/Projets_42_SP.git
```

If you wish to clone the code for a specific project, simply click on the desired project's link in the folder structure above, and then clone it locally.

<br><br>

---

<br><br>

### **Thank you for being here!** :wink:
