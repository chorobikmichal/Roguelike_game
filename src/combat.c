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

void combatSequence(char enemyType, Stats* myStats,int currentY,int currentX,int toGoY,int toGoX,EnemyCoordinates* myEnemyCoordinates){

	srand(time(NULL));
  	int random = (rand() % 10) + 1;

if((myStats->lastEnemyY!=toGoY)&&(myStats->lastEnemyX!=toGoX)){

myStats->lastEnemyY=toGoY;
myStats->lastEnemyX=toGoX;

	if(enemyType=='A'){
		//Aquator
		myStats->monsterHealth=5;
		myStats->monsterAttack=1;
		myStats->monsterSpeed=2;
	}else if(enemyType=='B'){
		//bat
		myStats->monsterHealth=2;
		myStats->monsterAttack=5;
		myStats->monsterSpeed=4;
	}else if(enemyType=='S'){
		//snake
		myStats->monsterHealth=5;
		myStats->monsterAttack=5;
		myStats->monsterSpeed=4;
	}else if(enemyType=='Z'){
		//zombie
		myStats->monsterHealth=15;
		myStats->monsterAttack=5;
		myStats->monsterSpeed=2;
	}else if(enemyType=='T'){
		//troll
		myStats->monsterHealth=50;
		myStats->monsterAttack=5;
		myStats->monsterSpeed=3;
	}
}


	char valuex = (char)mvinch(currentY,currentX);

  	if (random>myStats->monsterSpeed){
		myStats->monsterHealth=myStats->monsterHealth-myStats->attack;
		giveDamage(myStats->attack);
			mvprintw(currentY,currentX,"%c",valuex);
			move(currentY,currentX);

		if(myStats->monsterHealth<1){


				if(enemyType=='A'){
					killMonster("Aquator");
				}else if(enemyType=='B'){
					killMonster("bat");
				}else if(enemyType=='S'){
					killMonster("snake");
				}else if(enemyType=='Z'){
					killMonster("zombie");
				}else if(enemyType=='T'){
					killMonster("troll");
				}

				if(valuex=='@'){
					mvprintw(toGoY,toGoX,".");
					mvprintw(currentY,currentX,character);
					move(currentY,currentX);
				}else{
				//	mvprintw(currentY,currentX,".");
					mvprintw(toGoY,toGoX,character);
					move(toGoY,toGoX);
				}

			}
		}else{
		myStats->health=myStats->health-myStats->monsterAttack;
		takeDamage(myStats->monsterAttack);
			mvprintw(currentY,currentX,character);
			move(currentY,currentX);

		}

}
void randomItemVal (char item,Stats* myStats){

  srand(time(NULL));

  if(item==')'){
    myStats->wepPow[myStats->inv] = (rand() % 9) + 1;
    myStats->wepKind[myStats->inv] = ')';

  }else if (item=='('){
    myStats->wepPow[myStats->inv] = (rand() % 10) + 15;
    myStats->wepKind[myStats->inv] = '(';
      
  }else if(item==']'){
    myStats->wepPow[myStats->inv] = (rand() % 1) + 20;
    myStats->wepKind[myStats->inv] = ']';
  }

    printw(".");
    mvprintw(1, 20 ,"Hero picked up %c item",item);

}