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

    public:
    Tabuleiro(int dimensao);
    ~Tabuleiro();

    void proximaGen();
    void aumentaTamanho();
    int contarVizinhos(int x, int y);
};

#endif