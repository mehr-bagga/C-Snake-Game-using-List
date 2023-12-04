#ifndef FOOD_H
#define FOOD_H
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include <time.h>

class Food
{
    private:
        objPosArrayList* foodPos;
        GameMechs* mainGameMechsRef;
        int special, count;
    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPosArrayList* blockoff);
        void getFoodPos(objPos &returnPos, int i);
        char getSymbol(int i);
        int getSpecial();

        
};

#endif