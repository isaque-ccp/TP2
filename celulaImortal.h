#ifndef CELULA_IMORTAL_H
#define CELULA_IMORTAL_H

#include "celula.h"

class CelulaImortal : public Celula{
    public:
    CelulaImortal(int x,int y , bool vida);
    ~CelulaImortal();

    void virtual interagir(int vizinhosVivos) override;
};
#endif