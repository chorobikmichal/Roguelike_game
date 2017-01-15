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

void room (char * word, Items* myItems) {

	char ystr[5];
	char xstr[5];

	if(myItems->p==3) {
		myItems->b=20;
		myItems->big+=10;
		myItems->a=myItems->big;
	}
	else if((myItems->p!=3)&&(myItems->p!=0)) {
		myItems->b+=myItems->x;
		myItems->b+=10;
	}

	for(int i = 0; i<strlen(word) ;i++) {
		ystr[i]=word[i];
		if(word[i]=='X') {
			for(int b = i+1, z=0;b<=strlen(word);b++,z++)
				xstr[z]=word[b];
				}
				ystr[strlen(ystr)]='\0';
				xstr[strlen(xstr)]='\0';
			}

	myItems->y=atoi(ystr);
	myItems->x=atoi(xstr);
	printRec(myItems);

}
void printRec(Items* myItems) {

	int i;

	for(i=myItems->b; i<=myItems->x+myItems->b; i++)
		mvaddch(myItems->a-1,i,'-');

	for(i=myItems->a; i<myItems->y+myItems->a; i++) {
		mvaddch(i,myItems->b,'|');


	for(int y=0;y<(myItems->x );y++) {
		if(i< (myItems->y+myItems->a))
		mvaddch(i,myItems->b+1+y,'.');
	}

		mvaddch(i,myItems->b+myItems->x,'|');
	}

	for(i=myItems->b; i<=myItems->b+myItems->x; i++)
		mvaddch(myItems->a+myItems->y,i,'-');

}
void itemPickup (char * word, Items* myItems, char item,EnemyCoordinates* myEnemyCoordinates) {
  char ystr[5];
  char xstr[5];
  char itemStr[2];
  itemStr[0]=item;
  itemStr[1]='\0';

  for(int i = 1, a=0; i<strlen(word) ;i++, a++) {
    ystr[a]=word[i];
    if(word[i]==',') {
      for(int b = i+1, z=0;b<=strlen(word);b++,z++)
        xstr[z]=word[b];
        }
        ystr[strlen(ystr)]='\0';
        xstr[strlen(xstr)]='\0';
      }
  if(item != '@') {
  mvprintw(myItems->a + atoi(ystr) -1, myItems->b + atoi(xstr),itemStr);
  } else {
    myItems->characterY=atoi(ystr)+myItems->a;
    myItems->characterX=atoi(xstr)+myItems->b;
    myItems->doorNum=myItems->roomNum-1;
  }

  if(item == 'B'){
  	myEnemyCoordinates[myEnemyCoordinates->batCount].baty=myItems->a + atoi(ystr) -1;
  	myEnemyCoordinates[myEnemyCoordinates->batCount].batx=myItems->b + atoi(xstr);
	myEnemyCoordinates->batCount++;
  } else if (item == 'S'){
    myEnemyCoordinates[myEnemyCoordinates->snakeCount].snakey=myItems->a + atoi(ystr) -1;
  	myEnemyCoordinates[myEnemyCoordinates->snakeCount].snakex=myItems->b + atoi(xstr);
	myEnemyCoordinates->snakeCount++;
  } else if (item == 'Z'){
    myEnemyCoordinates[myEnemyCoordinates->zombieCount].zombiey=myItems->a + atoi(ystr) -1;
  	myEnemyCoordinates[myEnemyCoordinates->zombieCount].zombiex=myItems->b + atoi(xstr);
	myEnemyCoordinates->zombieCount++;
  } else if (item == 'T'){
    myEnemyCoordinates[myEnemyCoordinates->trollCount].trolly=myItems->a + atoi(ystr) -1;
  	myEnemyCoordinates[myEnemyCoordinates->trollCount].trollx=myItems->b + atoi(xstr);
	myEnemyCoordinates->trollCount++;
  }
}
void hallway(Items* myItems,RoomItems* myRoomItems, int hallwayCount,int doorInHall){


int y=myRoomItems[hallwayCount].doorY[doorInHall];
int x=myRoomItems[hallwayCount].doorX[doorInHall];

if(myRoomItems[hallwayCount].doorX[doorInHall]==2){
	x=myRoomItems[hallwayCount].doorX[doorInHall-1];
}

  char value1 = (char)mvinch(y,x-1);
  char value2 = (char)mvinch(y,x+1);
  char value3 = (char)mvinch(y-1,x);
  char value4 = (char)mvinch(y+1,x);

  int count=0;

while ((y!=myItems->big1+4+2)||(x=!20)){

count++;
if(count==1000){
	break;
}

  value1 = (char)mvinch(y,x-1);
  value2 = (char)mvinch(y,x+1);
  value3 = (char)mvinch(y-1,x);
  value4 = (char)mvinch(y+1,x);

if (y>(myItems->big1+4+2)){

		  if ((value3==' ')||(value3=='#')) {
			mvprintw(y-1,x,"#");
		    move(y-1,x);
		    y-=1;
		  }
		  else if ((value1==' ')||(value1=='#')) {
		    mvprintw(y,x-1,"#");
		    move(y,x-1);
		    x-=1;
		  }
		  else if ((value2==' ')||(value2=='#')) {
			mvprintw(y,x+1,"#");
		    move(y,x+1);
		    x+=1;
		  }
		  else if ((value4==' ')||(value4=='#')) {
			mvprintw(y+1,x,"#");
		    move(y+1,x);
		    y+=1;
		  }

}else if(y<(myItems->big1+4+2)){

		  if ((value4==' ')||(value4=='#')) {
			mvprintw(y+1,x,"#");
		    move(y+1,x);
		    y+=1;
		  }
		  else if ((value1==' ')||(value1=='#')) {
		    mvprintw(y,x-1,"#");
		    move(y,x-1);
		    x-=1;
		  }
		  else if ((value2==' ')||(value2=='#')) {
			mvprintw(y,x+1,"#");
		    move(y,x+1);
		    x+=1;
		  }
		  else if ((value3==' ')||(value3=='#')) {
			mvprintw(y-1,x,"#");
		    move(y-1,x);
		    y-=1;
		  }
}else if(x<20){

		  if ((value2==' ')||(value2=='#')){
			mvprintw(y,x+1,"#");
		    move(y,x+1);
		    x+=1;
		  }else if ((value4==' ')||(value4=='#')) {
			mvprintw(y+1,x,"#");
		    move(y+1,x);
		    y+=1;
		  }
		  else if ((value3==' ')||(value3=='#')) {
			mvprintw(y-1,x,"#");
		    move(y-1,x);
		    y-=1;
		  }
		  else if ((value1==' ')||(value1=='#')){
		    mvprintw(y,x-1,"#");
		    move(y,x-1);
		    x-=1;
		  }

}else if(x>20){

		  if ((value1==' ')||(value1=='#')){
			mvprintw(y,x-1,"#");
		    move(y,x-1);
		    x-=1;
		  }
		  else if ((value4==' ')||(value4=='#')) {
			mvprintw(y+1,x,"#");
		    move(y+1,x);
		    y+=1;
		  }
		  else if ((value3==' ')||(value3=='#')) {
			mvprintw(y-1,x,"#");
		    move(y-1,x);
		    y-=1;
		  }
		  else if ((value2==' ')||(value2=='#')){
		    mvprintw(y,x+1,"#");
		    move(y,x+1);
		    x+=1;
		  }
}

if(x<myRoomItems->hallXVal)
	myRoomItems->hallXVal=x;

if(x>myRoomItems->EndXVal)
	myRoomItems->EndXVal=x;

	}//while loop ends

}
void printLastTile(RoomItems* myRoomItems){

if(myRoomItems->lastTile=='.'){
  printw(".");
} else if (myRoomItems->lastTile=='+'){
  printw("+");
} else if (myRoomItems->lastTile=='#'){
  printw("#");
} else {
  printw(".");
}

myRoomItems->lastTile=myRoomItems->tile;

}


