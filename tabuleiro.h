#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "celula.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "celulaPadrao.h"
#include "celulaImortal.h"
#include "celulaMutante.h"

class Tabuleiro{
    private:
    int dimensao_;
    const int tamanhoMax_;
    Celula*** grade_;
    Celula*** aux_;

    public:
    Tabuleiro(int dimensao);
    ~Tabuleiro();

    void adicionaCelula(int coordX, int coordY, Celula* celula);
    void proximaGen();
    void imprimir() const;
    Celula* criaCelulasAleatoriamente();

};

#endif