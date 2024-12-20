#include "celulaImortal.h"

CelulaImortal::CelulaImortal():
Celula(true){}

CelulaImortal::~CelulaImortal(){}

void CelulaImortal::interagir(int numeroVizinhos){
    proximoEstado_ =  true;
}