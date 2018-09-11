# Filler

An algorithmic game of piece placing

## Filler Visualizer

![alt text](https://raw.githubusercontent.com/sjuery/filler/master/image/visualizer.gif)

## Introduction

Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.

Each successfully placed piece yields a number of points, and has only one player, the
goal of the game could be to get the best score possible. However, it is with two players
that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the
end of the game, the one with the most points wins the match...

### Prerequisites

In order to work, the project needs the filler VM. This can already be found in the resources folder.
For the visualizer to work, the graphic library Minilibx is also required. Once again it is already in the minilibx folder.

For more information of Minilibx visit https://github.com/qst0/ft_libgfx

### Installing

Using the Makefile provided will compile the player I have created for this project. This player will be named sjuery.filler.

```
make
[...] Creating Filler Player
[ ✔ ] Created Filler Player
```

Once this is done, both players must be run with the VM which can be found in the resources folder.

```
cd resources
./filler_vm

Usage: ./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]

   -t  --time		set timeout in second
   -q  --quiet		quiet mode
   -i  --interactive	interactive mode(default)
   -p1 --player1	use filler binary as a first player
   -p2 --player2	use filler binary as a second player
   -f  --file		use a map file (required)
   -s  --seed		use the seed number (initialization random) (man srand)
```

## Running the tests

In order to use the VM the only requirments are a map (resources/maps) and 2 players (resources/players and ../sjuery.filler)

```
./filler_vm -f resources/maps/map02 -p1 ../sjuery/sjuery.filler -p2 resources/players/carli.filler
```

There are 6 players, each varying in difficulty. The aim is to beat them all about 50% of the time.

> abanlin.filler		carli.filler		champely.filler		grati.filler		hcao.filler		superjeannot.filler

There are also 3 maps (00, 01, 02) each one increasing in size (Beat all players on all 3 maps)

## Authors

* **Stanislas Juery** -- (https://github.com/sjuery)

