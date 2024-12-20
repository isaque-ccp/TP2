#include "celulaPadrao.h"

CelulaPadrao::CelulaPadrao(bool estadoInicial):
Celula(estadoInicial){}

CelulaPadrao::~CelulaPadrao(){}

void CelulaPadrao::interagir(int vizinhosVivos){
    if(vizinhosVivos == 2 || vizinhosVivos == 3){
        proximoEstado_ = true;
    }
    else if(vizinhosVivos > 3 )
        proximoEstado_ = false;
    else if(vizinhosVivos == 3)
        proximoEstado_ = true;
    else if(vizinhosVivos < 2)
        proximoEstado_ = false;
}