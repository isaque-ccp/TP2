#include "celula.h"

Celula::Celula(bool estadoAtual):
estadoAtual_(estadoAtual){}

Celula::~Celula(){}

void Celula::atualizaEstado(){
    estadoAtual_ = proximoEstado_; 
}

bool Celula::isAlive(){
    return estadoAtual_;
}