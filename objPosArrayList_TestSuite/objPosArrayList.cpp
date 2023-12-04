#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    int temp = 5;
    sizeArray = new int;
    *sizeArray=temp;
    sizeList=0;
    aList=new objPos[5];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    delete sizeArray;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList== *sizeArray){
        addSpace();
    }
    for (int i=sizeList-1;i>=0;i--){
        aList[i+1]=aList[i];
    }
    aList[0]=thisPos;
    sizeList+=1;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList== *sizeArray){
        addSpace();
    }
    aList[sizeList]=thisPos;
    sizeList+=1;
}

void objPosArrayList::removeHead()
{
    for (int i=0;i<sizeList-1;i++){
        aList[i]=aList[i+1];
    }
    aList[sizeList-1].setObjPos(0,0,0);
    sizeList-=1;
}

void objPosArrayList::removeTail()
{   
    aList[sizeList-1].setObjPos(0,0,0);
    sizeList-=1;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos=aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos=aList[sizeList-1];
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index].x, aList[index].y, aList[index].symbol);
}
void objPosArrayList::addSpace(){
    objPos *temp = new objPos[*sizeArray + 5];
    for(int i=0; i< *sizeArray;i++){
        temp[i]=aList[i];
    }
    delete[] aList;
    aList=temp;
    delete[] temp;
    *sizeArray+=5;
}