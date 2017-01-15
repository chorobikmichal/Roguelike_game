#ifndef __MCHOROBI_FUNCTIONS__
#define __MCHOROBI_FUNCTIONS__
#define character "@"

/*
*Michal Chorobik 0937145
*CIS 2500
*mchorobi@uofguelph.mail.ca
*March 13, 2016
*/

struct EnemyCoordinates{
int baty;
int batx;
int batCount;
int batDead;
int snakey;
int snakex;
int snakeCount;
int snakeDead;
int snakeCycle;
int zombiey;
int zombiex;
int zombieCount;
int zombieDead;
int zombieCycle;
int trolly;
int trollx;
int trollCount;
int trollDead;
int trollCycle;
};

struct RoomItems {
int doorY[9]; //where the door goes on the west or east wall
int doorX[9]; //where the door goes on the north or south wall
int hallXVal;
int EndXVal;
char tile;
char lastTile;
int doorInRoom;
};

struct Stats {
int health;
int potions;
int attack;
int inv;
int gold; //sum of all gold collected
int monsterHealth;
int lastEnemyY;
int lastEnemyX;
int monsterSpeed;
int monsterAttack;
int doorOpenedCount;
int wepPow[5];
char wepKind[5];
};

struct Items {
int a;  //where it starts printing up/down
int b;  //where it starts printing left/right
int y;	//square height
int x;	//square length
int p;	//counts the squares printed so that after 3 the other 3 are brinted below
int big; //used to find the biggest out of the first 3 squares to print the other three underneath
int big1, big2; //used to print the notifications bar under everything
int roomNum;
int doorNum;
int newLine; //recogniezes when a new line is being read
int smallGold;
int bigGold;
int endGame;
int characterY;
int characterX;
};

typedef struct EnemyCoordinates EnemyCoordinates;
typedef struct Items Items;
typedef struct RoomItems RoomItems;
typedef struct Stats Stats;

void parsing(FILE* file, Items* myItems,RoomItems* myRoomItems,Stats* myStats,EnemyCoordinates* myEnemyCoordinates);
void room (char * word, Items* myItems);
void door(char * word, Items* myItems, RoomItems* myRoomItems);
void printRec(Items* myItems);
void gameLoop (Items* myItems,RoomItems* myRoomItems,Stats* myStats,EnemyCoordinates* myEnemyCoordinates);
void singleMove(char input,int currentY,int currentX, Items* myItems,RoomItems* myRoomItems, Stats* myStats,EnemyCoordinates* myEnemyCoordinates);
void moveCharacter(int updatedY,int updatedX,RoomItems* myRoomItems);
int canMove(int toGoY,int toGoX, Items* myItems,RoomItems* myRoomItems, Stats* myStats,EnemyCoordinates* myEnemyCoordinates);
void itemPickup (char * word, Items* myItems, char item,EnemyCoordinates* myEnemyCoordinates);
void weakMonster(char * word, Items* myItems,Stats* myStats,EnemyCoordinates* myEnemyCoordinates);
void gold (Items* myItems,char goldSize);
void randomItemVal (char item,Stats* myStats);
void hallway(Items* myItems,RoomItems* myRoomItems, int hallwayCount,int doorInHall);
void printLastTile(RoomItems* myRoomItems);
void combatSequence(char enemyType, Stats* myStats,int currentY,int currentX,int toGoY,int toGoX,EnemyCoordinates* myEnemyCoordinates);

void status(Items* myItems,Stats* myStats);
void pickup(char* item);
void invFull(char* item);
void takeDamage(int item);
void giveDamage(int item);
void killMonster(char* item);
void stepDoor(Stats* myStats,int currentY,int currentX);
void inventoryPrint(Stats* myStats);

void bat(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats);
void snake(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats);
void zombie(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats);
void troll(int count,EnemyCoordinates* myEnemyCoordinates,Stats* myStats);

#endif
