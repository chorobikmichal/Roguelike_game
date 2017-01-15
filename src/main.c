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

int main (int argc, char * argv[]) {

	FILE * levelFile;
	levelFile = fopen(argv[1],"r");

	Items* myItems = NULL;
	myItems = malloc(sizeof(Items));

	Stats* myStats = NULL;
	myStats = malloc(sizeof(Stats));

 	RoomItems* myRoomItems = NULL;
  	myRoomItems = malloc(6*sizeof(RoomItems));

  	EnemyCoordinates* myEnemyCoordinates = NULL;
  	myEnemyCoordinates = malloc(20*sizeof(EnemyCoordinates));

	parsing(levelFile,myItems,myRoomItems,myStats,myEnemyCoordinates);

	myRoomItems->EndXVal=0;
	myRoomItems->hallXVal=30;

	for(int i=1;i<7;i++){
		for(int w=1;w<myRoomItems[i].doorInRoom+1;w++){
			hallway(myItems,myRoomItems,i,w);
		}
	}

	for(int f=myRoomItems->EndXVal;f>myRoomItems->hallXVal;f--){
		mvprintw(myItems->big1+4+2,f,"#");
	}

	for(int h=0;h<20;h++){
		myEnemyCoordinates[h].snakeCycle=1;
		myEnemyCoordinates[h].zombieCycle=1;
		myEnemyCoordinates[h].trollCycle=1;
	}

	gameLoop (myItems,myRoomItems,myStats,myEnemyCoordinates);

  return 0;

  fclose(levelFile);
  free(myItems);
  free(myStats);
  free(myRoomItems);
}
