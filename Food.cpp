#include "Food.h"
#include <time.h>

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef=thisGMRef;

    foodPos=new objPosArrayList;
}

Food::~Food()
{
    delete foodPos;
    
}

void Food::generateFood(objPosArrayList* blockoff)
{
    objPos *temp1, *temp2, zero;
    temp1 = new objPos;
    temp2 = new objPos;
    special=0;
    srand(time(NULL));
    for(int i=0;i<2;i++){
        temp2->setObjPos(1+rand()%(mainGameMechsRef->getBoardSizeX()-2),1+rand()%(mainGameMechsRef->getBoardSizeY()-2),'*');
        if(rand()%100>75){
            special=i+1;
        }
        for(int j=0;j<blockoff->getSize();j++){
            blockoff->getElement(*temp1,j);
            if(temp2->isPosEqual(temp1)){
                --i;
            }
        }
        for(int j=0;j<i;j++){
            foodPos->getElement(*temp1,j);
            if(temp2->isPosEqual(temp1)){
                --i;
            }
        }
        foodPos->insertHead(*temp2); 
        if(foodPos->getSize()>3){   
            foodPos->removeTail();
        }  
    }   
    delete temp1;
    delete temp2;
}

void Food::getFoodPos(objPos &returnPos, int i)
{
    foodPos->getElement(returnPos,i);
}
char Food::getSymbol(int i){
    if (special==i+1){
        count++;
        if(count%2==0){
            return('*');
        }
        else
            return('-');
    }
    return('*');
}
int Food::getSpecial(){
    return special;
}
