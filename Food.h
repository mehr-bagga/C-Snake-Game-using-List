#ifndef FOOD_H
#define FOOD_H
#include "objPos.h"
#include "GameMechs.h"
#include <time.h>

class Food
{
    public:

        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPos* blockoff);
        void getFoodPos(objPos &returnPos);

    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;
};

#endif