#include "celulaPadrao.h"

CelulaPadrao::CelulaPadrao(int x,int y,bool vida):
Celula(x,y,vida){}

CelulaPadrao::~CelulaPadrao(){}

void CelulaPadrao::interagir(int vizinhosVivos){
    if(vizinhosVivos == 2  || vizinhosVivos == 3)
        vida_ = true;
    else if(vizinhosVivos < 2)
        vida_ = false;
    else if(vizinhosVivos == 3)
        vida_ = true;
    else 
        vida_ = false;
}