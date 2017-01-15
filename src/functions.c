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

void parsing(FILE* file, Items* myItems,RoomItems* myRoomItems,Stats* myStats,EnemyCoordinates* myEnemyCoordinates) {

	char word[10];
  int rareWepon = 0; //variable used to ensure that there is only one rare wepon per level
  int bigGoldCount = 0;  //variable used to ensure that there is only one big gold per level
  int hero = 0;

  myItems->p=0;
	myItems->a=4;
	myItems->b=20;
  myItems->roomNum=0;
  myItems->doorNum=0;
  myItems->newLine=0;
  myStats->gold=0;
  myStats->inv=0;
  myStats->potions=1;
  myStats->attack=5;
  myStats->health=50;
  myStats->lastEnemyX=0;
  myEnemyCoordinates->batCount=0;
  myEnemyCoordinates->snakeCount=0;
  myEnemyCoordinates->zombieCount=0;
  myEnemyCoordinates->trollCount=0;

	initscr();
	noecho();//stops the command prompt from capturing the input

	while(!feof(file)) {

	fscanf(file, "%s", word);

	//Its an int
	if ((word[0]>47)&&(word[0]<58)) {
		room(word, myItems);
		myItems->p++;                         //counts so that the three boxes print above the other three
    myItems->newLine++;                   //counts to let me know when a new line is read
	if((myItems->y)>(myItems->big)) {
		myItems->big=myItems->y;
	}
  if((myItems->p<4)&&(myItems->y)>(myItems->big1)) { //this whole loop is for the notifications
    myItems->big1=myItems->y;
  }else if ((myItems->y)>(myItems->big2)){
    myItems->big2=myItems->y;
  }
	}

	if (word[0]=='d') {
		door(word, myItems,myRoomItems);
	}

  if (word[0]=='M') {
    itemPickup(word, myItems,'T',myEnemyCoordinates);
  }

  if (word[0]=='m') {
    weakMonster(word, myItems, myStats,myEnemyCoordinates);
  }

  if (word[0]=='p') {
    itemPickup(word, myItems,'!',myEnemyCoordinates);
  }

  if(rareWepon==0){
    if (word[0]=='W') {
      itemPickup(word, myItems,'(',myEnemyCoordinates);
      rareWepon++;
    }
  }

  if (word[0]=='w') {
    itemPickup(word, myItems,')',myEnemyCoordinates);
  }

  if (word[0]=='e') {
    itemPickup(word, myItems,']',myEnemyCoordinates);
  }

  if(bigGoldCount==0) {
    if (word[0]=='G') {
      itemPickup(word, myItems,'8',myEnemyCoordinates);
      bigGoldCount++;
    }
  }

  if(hero==0) {
    if (word[0]=='h') {
      itemPickup(word, myItems,'@',myEnemyCoordinates);
      hero++;
    }
  }

  if (word[0]=='g') {
    itemPickup(word, myItems,'*',myEnemyCoordinates);
  }

  if (word[0]=='a') {
    itemPickup(word, myItems,'>',myEnemyCoordinates);
  }

  if (word[0]=='z') {
    itemPickup(word, myItems,'<',myEnemyCoordinates);
  }

 	}//while loop ends

}

void door(char * word, Items* myItems, RoomItems* myRoomItems) {

	char doorInfo[3];
	doorInfo[0]=word[2];
  if(word[3]!=' '){
  doorInfo[1]=word[3];
	doorInfo[2]='\0';
  }else{
    doorInfo[1]='\0';
  }

  if(myItems->roomNum==myItems->newLine)
    myRoomItems[myItems->newLine].doorInRoom++;
  else {
    myRoomItems[myItems->newLine].doorInRoom=1;
  }

  int doorInTheRoom=myRoomItems[myItems->newLine].doorInRoom;

  myItems->roomNum=myItems->newLine;


	if(word[1]=='e') {
		myRoomItems[myItems->roomNum].doorY[doorInTheRoom]=atoi(doorInfo)+myItems->a;
		myRoomItems[myItems->roomNum].doorX[doorInTheRoom]= myItems->x + myItems->b;
		mvaddch( myRoomItems[myItems->roomNum].doorY[doorInTheRoom] , myRoomItems[myItems->roomNum].doorX[doorInTheRoom] , '+');
	}
	else if(word[1]=='w') {
		myRoomItems[myItems->roomNum].doorY[doorInTheRoom]=atoi(doorInfo)+myItems->a;
		myRoomItems[myItems->roomNum].doorX[doorInTheRoom]= myItems->b;
		mvaddch( myRoomItems[myItems->roomNum].doorY[doorInTheRoom], myRoomItems[myItems->roomNum].doorX[doorInTheRoom] , '+');
	}
	else if(word[1]=='s') {
		myRoomItems[myItems->roomNum].doorX[doorInTheRoom]=atoi(doorInfo)+myItems->b;
		myRoomItems[myItems->roomNum].doorY[doorInTheRoom]=myItems->a + myItems->y;
		mvaddch( myRoomItems[myItems->roomNum].doorY[doorInTheRoom],  myRoomItems[myItems->roomNum].doorX[doorInTheRoom] , '+');
	}
	else if(word[1]=='n') {
		myRoomItems[myItems->roomNum].doorX[doorInTheRoom]=atoi(doorInfo)+myItems->b;
		myRoomItems[myItems->roomNum].doorY[doorInTheRoom]=myItems->a -1;
		mvaddch( 	myRoomItems[myItems->roomNum].doorY[doorInTheRoom],  myRoomItems[myItems->roomNum].doorX[doorInTheRoom] , '+');
	}

}

void gameLoop (Items* myItems,RoomItems* myRoomItems,Stats* myStats,EnemyCoordinates* myEnemyCoordinates) {

	char input;
	int currentY;
	int currentX;

  mvprintw(myItems->characterY,myItems->characterX,character);
  move(myItems->characterY,myItems->characterX);

	currentY=getcury(stdscr);
	currentX=getcurx(stdscr);
	input=getch();

	while((input != 'q')&&(myItems->endGame!=1)&&(myStats->health>0))
	{

  mvprintw(1, 20 ,"                                                 ");
  mvprintw(myItems->big1 + myItems->big2 + 10 + 2, 20 ,"                                                 ");

  if(input=='p'){
    if((myStats->potions)>0){
      myStats->potions--;
      myStats->health=50;
      mvprintw(1, 20 ,"Hero recovered full health");
    } else {
      mvprintw(1, 20 ,"Out of potions");
    }
  }

  for(int a =0;a<myEnemyCoordinates->batCount;a++)
    bat(a,myEnemyCoordinates,myStats);

  for(int b =0;b<myEnemyCoordinates->snakeCount;b++)
    snake(b,myEnemyCoordinates,myStats);

  for(int c =0;c<myEnemyCoordinates->zombieCount;c++){
    zombie(c,myEnemyCoordinates,myStats);
    printf("cicle : %d ",myEnemyCoordinates[c].zombieCycle);
}

  for(int d =0;d<myEnemyCoordinates->trollCount;d++)
    troll(d,myEnemyCoordinates,myStats);

	singleMove( input, currentY, currentX, myItems, myRoomItems,myStats,myEnemyCoordinates);
	input=getch();

	currentY=getcury(stdscr);
	currentX=getcurx(stdscr);

  move(currentY, currentX);

	}//wasd controll loop ends here

  inventoryPrint(myStats);

  getch();
  endwin();
}
void singleMove(char input,int currentY,int currentX, Items* myItems,RoomItems* myRoomItems, Stats* myStats,EnemyCoordinates* myEnemyCoordinates) {

    status(myItems,myStats);
    move(currentY,currentX);

		if(input=='w')
		{
			if (canMove(currentY-1,currentX, myItems, myRoomItems,myStats,myEnemyCoordinates)==1) {
				moveCharacter(currentY-1,currentX,myRoomItems);
			}
		}
		else if(input=='a')
		{
			if (canMove(currentY,currentX-1, myItems, myRoomItems,myStats,myEnemyCoordinates)==1) {
				moveCharacter(currentY,currentX-1,myRoomItems);
			}
		}
		else if(input=='s')
		{
			if (canMove(currentY+1,currentX, myItems, myRoomItems,myStats,myEnemyCoordinates)==1) {
				moveCharacter(currentY+1,currentX,myRoomItems);
			}
		}
		else if(input=='d')
		{
			if (canMove(currentY,currentX+1, myItems, myRoomItems,myStats,myEnemyCoordinates)==1) {
				moveCharacter(currentY,currentX+1,myRoomItems);
			}
		}
}
void moveCharacter(int updatedY,int updatedX,RoomItems* myRoomItems) {

  printLastTile(myRoomItems);

	mvprintw(updatedY,updatedX,character);
	move(updatedY,updatedX);

}
int canMove(int toGoY,int toGoX, Items* myItems,RoomItems* myRoomItems, Stats* myStats,EnemyCoordinates* myEnemyCoordinates) {

	int currentX=getcurx(stdscr);
	int currentY=getcury(stdscr);

  myRoomItems->tile = (char)mvinch(toGoY,toGoX);

	char value = (char)mvinch(toGoY,toGoX);

  move(currentY,currentX);

  if((value=='T')||(value=='A')||(value=='B')||(value=='S')||(value=='Z')){
    combatSequence(value,myStats,currentY,currentX,toGoY,toGoX,myEnemyCoordinates);
    return 0;
  }

  if(value=='+') {
      if(myItems->doorNum==6)
        myItems->doorNum=0;
    stepDoor(myStats,currentY,currentX);
    myItems->doorNum++;
  }

  if(value=='('){
    if((myStats->inv)<5){
      randomItemVal('(',myStats);
      myStats->inv++;
      pickup("rare weapon");
    } else {
      invFull("rare weapon");
    }
  }

  if(value==')'){
    if((myStats->inv)<5){
      randomItemVal(')',myStats);
      myStats->inv++;
      pickup("common weapon");
    } else {
      invFull("common weapon");
    }
  }

  if(value==']'){
    if((myStats->inv)<5){
      randomItemVal(']',myStats);
      myStats->inv++;
      pickup("equipment");
    } else {
      invFull("equipment");
    }
  }

    if(value=='!'){
      myStats->potions++;
      randomItemVal('!',myStats);
      pickup("potion");
  }

  if(value == '*') {
    gold(myItems,'*');
    pickup("gold");
    myStats->gold += myItems->smallGold;
    printw(".");
  }

  if(value == '8') {
    gold(myItems,'8');
    pickup("big gold");
    myStats->gold += myItems->bigGold;
    printw(".");
  }

  if((value == '>')||(value == '<')) {
      printw(".");
      myItems->endGame=1;
  }

	if((value == '|')||(value == '-')||(value == ' ')) {
		return 0;
	}
  else
	  return 1;

}
void weakMonster(char * word, Items* myItems,Stats* myStats,EnemyCoordinates* myEnemyCoordinates) {

  srand(time(NULL));
  int random = 4;//(rand() % 4) + 1;

    if(random==1) {
      itemPickup(word,myItems,'A',myEnemyCoordinates);
    }
    else if(random==2) {
      itemPickup(word,myItems,'B',myEnemyCoordinates);
    }
    else if(random==3) {
      itemPickup(word,myItems,'S',myEnemyCoordinates);
    }
    else if(random==4) {
      itemPickup(word,myItems,'Z',myEnemyCoordinates);
    }

}
void gold (Items* myItems,char goldSize) {

  srand(time(NULL));

  if (goldSize=='*') {
    myItems->smallGold = (rand() % 50) + 0;
  }
  else if (goldSize=='8') {
    myItems->bigGold = (rand() % 250) + 50;
  }

}

