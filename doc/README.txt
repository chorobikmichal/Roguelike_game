Michal Chorobik (0937145)
mchorobi@mail.ouguelph.ca 
CIS*2500 Assignment3
March 13,2016

Compilation:
1. cis2500/A2/src
2. gcc main.c functions.c printing.c notifications.c combat.c movement.c -std=c99 -lncurses -Wall -o run -I ../include -I ../assets
3. ./run ../assets/input.txt

Usage:
To use this program input the name of a text file with the level data. 
Then once the game board appears use wasd keays to control the character 
printed on the screen and interact with the game. You can press q to quit at any point.

Known limitations:
You can't input any other file names than text files.
There has to be a file name passed as an argument or there is a set fault


Testing:
I used different combinations of items and parameters to ensure that my program works 
at all times that it should. This is the list of those combinations. I put multiple items 
like big gold or the character to check if they would print more then once which they don't.
Also i put multiple doors in each room to see if they would print and work propertly. Lastly I
printed the character in a room other then the first one to check if the teleportation from door to door would work.

10X14 de4 dw9 ds8 g8,7 g4,1 G4,2 g2,2
13X16 dw21 w5,4 p2,2
31X22 dn5 p9,2 de7 M4,12 g3,1 W8,8 W9,9 w3,3
9X20 ds1 de6 W8,8 h6,5
23X11 dw3 a5,8 z8,4
16X24 dw18 ds3 p10,10

References:
Stackoverflow.com
MAN pages

