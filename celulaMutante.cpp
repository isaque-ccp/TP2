#include "celulaMutante.h"

CelulaMutante::CelulaMutante(int x, int y, bool vida):
Celula(x,y,vida){}

void CelulaMutante::interagir(int vizinhosVivos){
    vida_ = !vida_;
}