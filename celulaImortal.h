#ifndef CELULA_IMORTAL_H
#define CELULA_IMORTAL_H

#include "celula.h"

class CelulaImortal : public Celula{
    public:
    CelulaImortal();
    ~CelulaImortal();

    void virtual interagir(int vizinhosVivos) override;
};
#endif