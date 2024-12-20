#ifndef CELULA_PADRAO_H
#define CELULA_PADRAO_H

#include "celula.h"

class CelulaPadrao : public Celula{
    public:
    CelulaPadrao(int x,int y, bool vida);
    ~CelulaPadrao();
    void interagir(int vizinhoVivos) override;

   
};
#endif