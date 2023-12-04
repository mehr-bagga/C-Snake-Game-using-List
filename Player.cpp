#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.x=1;
    playerPos.y=1;
    playerPos.symbol='@';

    objPos temp;
    temp.setObjPos(playerPos.x,playerPos.y, playerPos.symbol);
 
    playerPosList = new objPosArrayList;
    playerPosList->insertHead(temp);
    temp.setObjPos(1,2,playerPos.symbol);
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;

    delete playerPosList;
}

// void Player::getPlayerPos(objPosArrayList &returnPosList)
// {
//     //return the reference to the playerPos arrray list
//     objPos* temp;
//     temp = new objPos;
//     objPosArrayList* temp1;
//     temp1 = new objPosArrayList;
//     for (int i=0; i< playerPosList->getSize(); i++){
//         playerPosList->getElement(*temp,i);
//         temp1->insertTail(*temp);
//     }
//     delete temp;
//     temp=NULL;

//     returnPosList = *temp1;
//     delete temp1;
// }
void Player::getPlayerPos(objPosArrayList &returnPosList)
{
    //return the reference to the playerPos arrray list
    returnPosList=*playerPosList;
}
objPosArrayList Player::getPlayerPos()
{
    //return the reference to the playerPos arrray list
    return *playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    if(mainGameMechsRef->getInput() != 0)  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'w':
                if(myDir!=DOWN)
                    myDir = UP;
                break;
            case 'a':
                if(myDir!=RIGHT)
                    myDir = LEFT;
                break;
            case 's':
                if(myDir!=UP)
                    myDir = DOWN;
                break;
            case 'd':
                if(myDir!=LEFT)
                    myDir = RIGHT;
                break;
            default:
                break;
        }
    }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos temp, food, *temp1;
    temp1=new objPos;
    switch(myDir){
        case UP:
            playerPos.y-=1;
            break;
        case DOWN:
            playerPos.y+=1;
            
            break;
        case LEFT:
            playerPos.x-=1;
            
            break;
        case RIGHT:
            playerPos.x+=1;
            
            break;
    }
    if (playerPos.y<=0){
        playerPos.y=mainGameMechsRef->getBoardSizeY()-2;
    }
    if (playerPos.y>=mainGameMechsRef->getBoardSizeY()-1){
        playerPos.y=1;
    }
    if (playerPos.x<=0){
        playerPos.x=mainGameMechsRef->getBoardSizeX()-2;
    }
    if (playerPos.x>=mainGameMechsRef->getBoardSizeX()-1){
        playerPos.x=1;
    }
    temp.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    mainGameMechsRef->getFoodPos(food);
    if(temp.isPosEqual(&food)){
        playerPosList->insertHead(temp);
        mainGameMechsRef->generateFood(playerPosList);
    }
    else if(myDir!=STOP){
        playerPosList->insertHead(temp);
        playerPosList->removeTail();
    }
    

    delete temp1;
    temp1=NULL;
}

int Player::getSize(){
    return playerPosList->getSize();
}

bool Player::checkSelfCollision(){
    objPos *temp, *temp1;
    temp = new objPos;
    temp1 = new objPos;
    playerPosList->getHeadElement(*temp);
    for (int i=1; i<getSize();i++){
        playerPosList->getElement(*temp1,i);
        if(temp->isPosEqual(temp1)){
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
    }
    delete temp;
    delete temp1;
}

