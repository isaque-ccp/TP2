#ifndef CELULA_MUTANTE_H
#define CELULA_MUTANTE_H

#include "celula.h"

class CelulaMutante : public Celula{
    public:
    CelulaMutante(int x,int y, bool vida);
    ~CelulaMutante();
    void interagir(int vizinhosVivos) override;

};
#endif