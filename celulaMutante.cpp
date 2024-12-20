#include "celulaMutante.h"

CelulaMutante::CelulaMutante(bool estadoInicial):
Celula(estadoInicial){}

CelulaMutante::~CelulaMutante(){}

void CelulaMutante::interagir(int numeroVizinhos){
    proximoEstado_ = !estadoAtual_;
}