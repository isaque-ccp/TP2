#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "tabuleiro.h"
#include "celulaPadrao.h"
#include "celulaMutante.h"
#include "celulaImortal.h"
#include <iostream>

class Simulacao {
private:
    Tabuleiro* tabuleiro_; // Ponteiro para o tabuleiro
    int geracaoAtual;     // Contador de gerações



public:
    // Construtor e destrutor
    Simulacao();
    ~Simulacao();

    // Métodos principais
    void exibirMenu();
    void executarJogo();
    void avancarGeracoes(int numGeracoes);
    void inicializarPadraoBloco();
    void inicializarPadraoBote();
    void inicializarPadraoPlanador();
    void inicializarPadraoSapo();
    void inicializarPadraoEspacoNave();
    void inicializarPadraoPiscador();    
    void inicializarAleatorio();
};

#endif