# so_long
Bask in late-90's gaming nostalgia!

![2022-01-15 11-40-40](https://user-images.githubusercontent.com/49699403/149626600-089dc518-8d8e-4f39-a3a4-fd35f82169b9.gif)

This is my first 2D game, built with a custom graphic interface library that allows for window drawing and events handling. The sprites (from Game Freak/Nintendo's classic Pokémon Yellow) were retrieved from the internet, although I did the colouring myself.

The game is initiated by a map file in the ```.ber``` format containing only the following valid characters:
``` c
# define VALID_MAP_CHARS	"EPC10TJ"
```
- E stands for _exit_
- P stands for _player_
- C for _collectibles_
- 1 for _walls_
- 0 for _floor_
- T and J are other pokémon _trainers_

The player must guide Pikachu around the map (movement constrained by walls); the goal is to clear the level by collecting all the pokéballs on the floor and escape the scene through the exit, while avoiding the threat of Rocket Team!

This project is not meant to be a fully-fledged game, rather an introduction to a minimal, event-wise graphic library, developed over the course of 2-3 weeks.

_You can find more about the making of this project [over here](https://rodsmade.notion.site/Acelera-So_long-e5caded24d7b434aa1cb5daf73636fb9) (in Portuguese 🇧🇷)_

## Directories
* ```bin/```
	Where the final executable binary file goes.

* ```headerfiles/``` 
	Keeps all the custom-made .h header files used in the project.

* ```libs/``` 
	Keeps the local custom-made library Libft (see [this project](https://github.com/rodsmade/Projets_42_SP/tree/main/projets_obligatoires/1_libft) for reference), which comprises some of the string handling functions, for instance.

* ```objs/``` 
	Keeps all the .o files produced throughout the compilation process.

* ```resources/images``` 
	All the sprites used in the game in the ```.xpm``` format.

* ```resources/maps``` 
	Some preset maps used for running and testing the game. Some are purposefully invalid and shouldn't be allowed to open the game.

* ```srcs/```
	Where all the good stuff goes!

## Run the game
### Linux and MacOS
Please follow the instructions in [this repo](https://github.com/42Paris/minilibx-linux#readme) in order to install the necessary packets to run Minilibx

### Windows
You'll need to install Xserver in your machine seeing as the library runs on X-Window system. You may also use WSL on Windows 11 and run ```wsl --update``` and you should be good to go.

### Clone repo and run
``` c
git clone https://github.com/rodsmade/Projets_42_SP.git
make run MAP=<path to map>
```
You can use one of the preset maps in ```./resources/maps```, or you could even make a map of your own!

Game on! :)
