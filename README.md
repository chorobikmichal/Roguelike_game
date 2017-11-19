# 2d adventure Roguelike Game

- The game’s objective is to collect as much gold as possible. 
- The player faces different challenges such as interacting with monsters as they manoeuvre through different rooms and hallways.
- The Player can fight zombies or trolls by walking into them. By doing so they will receive as well as cause damage. 
- The player can use potions to receive more health points.
- The player can cause more damage when fighting with monsters by picking up weapons.
- Once the player dies or goes on the stairs the game will end and all the statistics will be displayed.

![gggg](https://user-images.githubusercontent.com/24882037/32814735-4766e932-c97e-11e7-9d7c-e64b32e83164.gif)

## Compilation:
To run this program run the make command in its directory. The make file compiles the program and also executes the game.

## Usage:
You can create your own map. Every element's location can be customized through input.txt file. 
Once the game is ran and the board appears use w, a, s and d keys to control the character printed on the screen and interact with the game. You can press q to quit at any point.

## Example of game's map instructions:

**10X14** - example of a rooms dimentions

**de2** - means door on east side of the room 2 positions from the top

**m4,4** - means its a monster

**a8,8** - stairs(walking onto them will end the game)

**g2,2** - gold

**h6,6** - player will appear and start the game in that position


**10X10 de2 ds2 dn4 dw7 g2,2 m4,4 h6,6 a8,8**
14X14 de6 dw3 M6,6 p1,1 p1,2 p1,3
16X12 de3 ds6 m5,5 w1,1 W9,9 e10,10 w10,11 w11,10 w11,11
16X16 de4 ds8 z2,4 g1,1 g1,2 g1,3 g1,4 G6,6
18X18 de5 dn2 ds2 m6,6 m10,10
15X15 de7 dw3 z4,5 m8,8 m12,12

## Screenshots:

![rogue-screen2](https://user-images.githubusercontent.com/24882037/32814917-386f826c-c97f-11e7-91cd-817fc5c6afcd.png)

![rogue-screen1](https://user-images.githubusercontent.com/24882037/32814918-387b293c-c97f-11e7-91a4-bbdc489754a9.png)
