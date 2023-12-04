#include "GameMechs.h"
#include <time.h>
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX=20;
    boardSizeY=10;
    exitFlag=0;
    loseFlag=0;
    score=0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX=boardX;
    boardSizeY=boardY;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}
bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}


void GameMechs::setExitTrue()
{
    exitFlag=1;
}

void GameMechs::setLoseFlag()
{
    loseFlag=1;
}

void GameMechs::setInput(char this_input)
{
    input=this_input;
}

void GameMechs::clearInput()
{
    input=0;
}

void GameMechs::incrementScore()
{
    score+=1;
}

void GameMechs::generateFood(objPosArrayList* blockoff)
{
    objPos *temp1;
    temp1 = new objPos;
    srand(time(NULL));
    for(int i=0;i<1;i++){
        foodPos.setObjPos(1+rand()%(getBoardSizeX()-2),1+rand()%(getBoardSizeY()-2),'*');
        for(int j=0;j<blockoff->getSize();j++){
            blockoff->getElement(*temp1,j);
            if(foodPos.isPosEqual(temp1)){
                --i;
            }
        }
    } 
    delete temp1;
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    foodPos.getObjPos(returnPos);
}

