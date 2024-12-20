#ifndef CELULA_MUTANTE_H
#define CELULA_MUTANTE_H

#include "celula.h"

class CelulaMutante : public Celula{
    public:
    CelulaMutante(bool estadoInicial);
    ~CelulaMutante();

    void virtual interagir(int vizinhosVivos) override;
};
#endif