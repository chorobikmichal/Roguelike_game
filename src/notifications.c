#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ncurses.h>
#include <time.h>
#include "functions.h"

/*
*Michal Chorobik 0937145
*CIS 2500
*mchorobi@uofguelph.mail.ca
*March 13, 2016
*/

void status(Items* myItems,Stats* myStats){

  mvprintw(myItems->big1 + myItems->big2 + 10 + 2, 20 ,"Health: %d%%, Potions: %d, Attack: <C>, Inv: %d/5",myStats->health,myStats->potions,myStats->inv);

}
void pickup(char* item){
  printw(".");
  mvprintw(1, 20 ,"Hero picked up %s item",item);
}
void invFull(char* item){
  printw(".");
  mvprintw(1, 20 ,"Hero stepped on %s, and broke it",item);
}
void takeDamage(int item){
  printw(".");
  mvprintw(1, 20 ,"Hero lost %d health or attack",item);
}
void giveDamage(int item){
  printw(".");
  mvprintw(1, 20 ,"Hero caused %d damage          ",item);
}
void killMonster(char* item){
  printw(".");
  mvprintw(1, 20 ,"Hero killed %s                ",item);
}
void stepDoor(Stats* myStats,int currentY,int currentX){
  if (myStats->doorOpenedCount==0){
  printw(".");
  myStats->doorOpenedCount=1;
  }else{
  printw("#");
  myStats->doorOpenedCount=0;
  }
  mvprintw(1, 20 ,"Hero opened a door   ");
    move(currentY,currentX);

}
void inventoryPrint(Stats* myStats){

int i;

	mvprintw(20,30,"**Congratulations you collected %d of gold**",myStats->gold );
	mvprintw(21,30,"**Your equipment list**");

if(myStats->inv>0){
  for(i=0;i<myStats->inv;i++){
	mvprintw(21+i,30,"**weapon: %c weapon power: %d**",myStats->wepKind[i],myStats->wepPow[i]);
  }
}

}