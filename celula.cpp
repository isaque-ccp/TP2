#include "celula.h"

Celula::Celula(int x , int y , bool vida):
x_(x),y_(y),vida_(vida){}

int Celula::getX(){
    return x_;
}

int Celula::getY(){
    return y_;
}

bool Celula::getVida(){
    return vida_;
}

void Celula::setVida(bool vida){
    vida_ = vida;
}