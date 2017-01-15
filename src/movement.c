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

void bat(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats){


 	srand(time(NULL));
  	int random = (rand() % 4) + 1;

	int y=myEnemyCoordinates[count].baty;
	int x=myEnemyCoordinates[count].batx;

	char valuex = (char)mvinch(y,x);

	if (valuex!='B')
		myEnemyCoordinates[count].batDead=1;

	char value1 = (char)mvinch(y,x-1);
 	char value2 = (char)mvinch(y,x+1);
 	char value3 = (char)mvinch(y-1,x);
 	char value4 = (char)mvinch(y+1,x);

  	if((random==1)&&((value1=='.')||(value1=='@'))&&(myEnemyCoordinates[count].batDead!=1)){
  		if(value1=='.'){
  			mvprintw(y,x,".");
  			mvprintw(y,x-1,"B");
  			myEnemyCoordinates[count].batx=myEnemyCoordinates[count].batx-1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x-1,myEnemyCoordinates);
  		}
  	} else if((random==2)&&((value2=='.')||(value2=='@'))&&(myEnemyCoordinates[count].batDead!=1)){
  		if(value2=='.'){
  			mvprintw(y,x,".");
  			mvprintw(y,x+1,"B");
  			myEnemyCoordinates[count].batx=myEnemyCoordinates[count].batx+1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x+1,myEnemyCoordinates);
  		}
  	} else if((random==3)&&((value3=='.')||(value3=='@'))&&(myEnemyCoordinates[count].batDead!=1)){
   		if(value3=='.'){
	  		mvprintw(y,x,".");
	  		mvprintw(y-1,x,"B");
	  		myEnemyCoordinates[count].baty=myEnemyCoordinates[count].baty-1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y-1,x,myEnemyCoordinates);
  		}
  	} else if((random==4)&&((value4=='.')||(value4=='@'))&&(myEnemyCoordinates[count].batDead!=1)){
    	if(value4=='.'){
	  		mvprintw(y,x,".");
	  		mvprintw(y+1,x,"B");
	  		myEnemyCoordinates[count].baty=myEnemyCoordinates[count].baty+1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y+1,x,myEnemyCoordinates);
  		}
  	}
}
void snake(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats){

	int cycle = myEnemyCoordinates[count].snakeCycle;

	int y=myEnemyCoordinates[count].snakey;
	int x=myEnemyCoordinates[count].snakex;

	char valuex = (char)mvinch(y,x);

	if (valuex!='S')
		myEnemyCoordinates[count].snakeDead=1;

	char value1 = (char)mvinch(y,x-1);
 	char value2 = (char)mvinch(y,x+1);


  	if((cycle==1)&&((value2=='.')||(value2=='@'))&&(myEnemyCoordinates[count].snakeDead!=1)){

		myEnemyCoordinates[count].snakeCycle=2;

  		if(value2=='.'){
  			mvprintw(y,x,".");
  			mvprintw(y,x+1,"S");
  			myEnemyCoordinates[count].snakex=myEnemyCoordinates[count].snakex+1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x+1,myEnemyCoordinates);
  		}
  	} else if((cycle==2)&&((value2=='.')||(value2=='@'))&&(myEnemyCoordinates[count].snakeDead!=1)){
  		if(value2=='.'){

  			myEnemyCoordinates[count].snakeCycle=3;

  			mvprintw(y,x,".");
  			mvprintw(y,x+1,"S");
  			myEnemyCoordinates[count].snakex=myEnemyCoordinates[count].snakex+1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x+1,myEnemyCoordinates);
  		}
  	} else if((cycle==3)&&((value1=='.')||(value1=='@'))&&(myEnemyCoordinates[count].snakeDead!=1)){

 			myEnemyCoordinates[count].snakeCycle=4;

   		if(value1=='.'){
	  		mvprintw(y,x,".");
	  		mvprintw(y,x-1,"S");
  			myEnemyCoordinates[count].snakex=myEnemyCoordinates[count].snakex-1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x-1,myEnemyCoordinates);
  		}
  	} else if((cycle==4)&&((value1=='.')||(value1=='@'))&&(myEnemyCoordinates[count].snakeDead!=1)){
    	if(value1=='.'){
	  		mvprintw(y,x,".");
	  		mvprintw(y,x-1,"S");
  			myEnemyCoordinates[count].snakex=myEnemyCoordinates[count].snakex-1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x-1,myEnemyCoordinates);
  		}
		myEnemyCoordinates[count].snakeCycle=1;
  	}
 }

void zombie(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats){

	int cycle = myEnemyCoordinates[count].zombieCycle;

	int y=myEnemyCoordinates[count].zombiey;
	int x=myEnemyCoordinates[count].zombiex;

	char valuex = (char)mvinch(y,x);

	if (valuex!='Z')
		myEnemyCoordinates[count].zombieDead=1;

	char value1 = (char)mvinch(y+1,x);
 	char value2 = (char)mvinch(y-1,x);


  	if((cycle==1)&&((value1=='.')||(value1=='@'))&&(myEnemyCoordinates[count].zombieDead!=1)){

		myEnemyCoordinates[count].zombieCycle=2;

  		if(value1=='.'){
  			mvprintw(y,x,".");
  			mvprintw(y+1,x,"Z");
  			myEnemyCoordinates[count].zombiey=myEnemyCoordinates[count].zombiey+1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y+1,x,myEnemyCoordinates);
  		}
  	} else if((cycle==2)&&((value2=='.')||(value2=='@'))&&(myEnemyCoordinates[count].zombieDead!=1)){
  		  			
  		if(value2=='.'){
  			mvprintw(y,x,".");
  			mvprintw(y-1,x,"Z");
  			myEnemyCoordinates[count].zombiey=myEnemyCoordinates[count].zombiey-1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y-1,x,myEnemyCoordinates);
  		}

  		myEnemyCoordinates[count].zombieCycle=1;

  	}
 }
void troll(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats){

	int cycle = myEnemyCoordinates[count].trollCycle;

	int y=myEnemyCoordinates[count].trolly;
	int x=myEnemyCoordinates[count].trollx;

	char valuex = (char)mvinch(y,x);

	if (valuex!='T')
		myEnemyCoordinates[count].trollDead=1;

	char value1 = (char)mvinch(y,x-1);
 	char value2 = (char)mvinch(y,x+1);
 	char value3 = (char)mvinch(y-1,x);
 	char value4 = (char)mvinch(y+1,x);

  	if((cycle==1)&&((value3=='.')||(value3=='@'))&&(myEnemyCoordinates[count].trollDead!=1)){

		myEnemyCoordinates[count].trollCycle=2;

  		if(value2=='.'){
  			mvprintw(y,x,".");
  			mvprintw(y-1,x,"T");
  			myEnemyCoordinates[count].trolly=myEnemyCoordinates[count].trolly-1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y-1,x,myEnemyCoordinates);
  		}
  	} else if((cycle==2)&&((value2=='.')||(value2=='@'))&&(myEnemyCoordinates[count].trollDead!=1)){
  		if(value2=='.'){

  			myEnemyCoordinates[count].trollCycle=3;

  			mvprintw(y,x,".");
  			mvprintw(y,x+1,"T");
  			myEnemyCoordinates[count].trollx=myEnemyCoordinates[count].trollx+1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x+1,myEnemyCoordinates);
  		}
  	} else if((cycle==3)&&((value4=='.')||(value4=='@'))&&(myEnemyCoordinates[count].trollDead!=1)){

 			myEnemyCoordinates[count].trollCycle=4;

   		if(value1=='.'){
	  		mvprintw(y,x,".");
	  		mvprintw(y+1,x,"T");
  			myEnemyCoordinates[count].trolly=myEnemyCoordinates[count].trolly+1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y+1,x,myEnemyCoordinates);
  		}
  	} else if((cycle==4)&&((value1=='.')||(value1=='@'))&&(myEnemyCoordinates[count].trollDead!=1)){
    	if(value1=='.'){
	  		mvprintw(y,x,".");
	  		mvprintw(y,x-1,"T");
  			myEnemyCoordinates[count].trollx=myEnemyCoordinates[count].trollx-1;
  		}else{
  			combatSequence(valuex,myStats,y,x,y,x-1,myEnemyCoordinates);
  		}
		myEnemyCoordinates[count].trollCycle=1;
  	}
}