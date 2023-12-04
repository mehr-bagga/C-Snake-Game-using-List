#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000


GameMechs *g1 = new GameMechs;
Player *p1 = new Player(g1);

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(g1->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    objPosArrayList *temp1;
    temp1 = new objPosArrayList;

    MacUILib_init();
    MacUILib_clearScreen();
    p1->getPlayerPos(*temp1);
    g1->generateFood(temp1);

    
}

void GetInput(void)
{   
    
    if(MacUILib_hasChar()==1 ){
        g1->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    objPosArrayList *temp1;
    temp1 = new objPosArrayList;
    p1->getPlayerPos(*temp1);
    if(g1->getScore()<p1->getSize()){
        g1->incrementScore();
    }

    if(g1->getInput()==' '){
        g1->setExitTrue();
    }
    else{
        p1->updatePlayerDir();  
    }
    p1->movePlayer();
    p1->checkSelfCollision();
    g1->clearInput();

    

}

void DrawScreen(void)
{
    objPosArrayList *temp1;
    objPos *temp3,*temp2, temp;
    temp1 = new objPosArrayList;
    temp2= new objPos;
    temp3= new objPos;

    int t;
    MacUILib_clearScreen();
    for(int y=0;y<g1->getBoardSizeY();y++){
        for(int x=0;x<g1->getBoardSizeX();x++){
            if(x==g1->getBoardSizeX()-1){
                MacUILib_printf("#\n");
            }
            else if(y==0 || y==g1->getBoardSizeY()-1 || x==0){
                MacUILib_printf("#"); 
            }
            else{
                temp.setObjPos(x,y,' ');
                p1->getPlayerPos(*temp1);
                g1->getFoodPos(*temp2);
                t=1;
                for (int i=0;i<p1->getSize();i++){
                    temp1->getElement(*temp3,i);
                    if(temp.isPosEqual(temp3)){
                        MacUILib_printf("%c",temp3->getSymbol());
                        t=0;
                    }
                }
                if(temp.isPosEqual(temp2) && t){
                    MacUILib_printf("%c",temp2->getSymbol());
                }
                else if(t){
                    MacUILib_printf(" ");
                }
            }
        }
    } 
    MacUILib_printf("Size: %d", g1->getScore());
    delete temp2;
    delete temp3;

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
    
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    if(g1->getLoseFlagStatus()==1){
        MacUILib_printf("\nLOSER");
    }else
        MacUILib_printf("\nQUITTER");
    delete p1;
    delete g1;
    MacUILib_uninit();

}
