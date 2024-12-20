#ifndef CELULA_PADRAO_H
#define CELULA_PADRAO_H

#include "celula.h"

class CelulaPadrao : public Celula{
    public:
    CelulaPadrao(bool estadoInicial);
    ~CelulaPadrao();

    void virtual interagir(int vizinhosVivos) override;
};
#endif