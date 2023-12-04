#include "Food.h"
#include <time.h>

Food::Food(GameMechs* thisGMRef){
    mainGameMechsRef=thisGMRef;
}
Food::~Food(){
    foodPos.setObjPos(0,0,0);
}
void Food::generateFood(objPos* blockoff){
    srand(time(NULL));
    for(int i=0;i<1;i++){
        foodPos.setObjPos(1+rand()%(mainGameMechsRef->getBoardSizeX()-2),1+rand()%(mainGameMechsRef->getBoardSizeY()-2),'*');
        if(foodPos.isPosEqual(blockoff)){
            --i;
        }
    } 
}
void Food::getFoodPos(objPos &returnPos){
    foodPos.getObjPos(returnPos);
}