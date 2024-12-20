#include "simulacao.h"
#include <iostream>
#include <stdexcept>

Simulacao::Simulacao(){
    tabuleiro_ = new Tabuleiro(10);
}

Simulacao::~Simulacao(){
    delete tabuleiro_;
}

void Simulacao::exibirMenu() {
    int opcao;

    do {
        std::cout << "\nMenu de Simulação:\n";
        std::cout << "1. Inicializar padrão Bloco\n";
        std::cout << "2. Inicializar padrão Bote\n";
        std::cout << "3. Inicializar padrão Planador\n";
        std::cout << "4. Inicializar estado aleatorio\n";
        std::cout << "5. Inicializar estado Sapo\n";
        std::cout << "6. Inicializar estado EspacoNave\n";
        std::cout << "7. Avançar 100 gerações\n";
        std::cout << "8. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                inicializarPadraoBloco();
                executarJogo();
                break;
            case 2:
                inicializarPadraoBote();
                executarJogo();
                break;
            case 3:
                inicializarPadraoPlanador();
                executarJogo();
                break;
            case 4:
                inicializarAleatorio();
                executarJogo();
                break;
            case 5:
                inicializarPadraoSapo();
                executarJogo();
                break;          
            case 6:
                inicializarPadraoEspacoNave();
                executarJogo();
                break;
            case 7:
                avancarGeracoes(100);
                break;
            case 8:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 8);
}

void Simulacao::executarJogo() {
    std::cout << "Estado inicial:\n";
    tabuleiro_->exibir();

    avancarGeracoes(2);

    std::cout << "Simulação concluída.\n";
}

void Simulacao::avancarGeracoes(int numGeracoes) {
    for (int i = 0; i < numGeracoes; ++i) {
        tabuleiro_->atualizarTabuleiro();
        geracaoAtual++;
        tabuleiro_->exibir();
    }
}

void Simulacao::inicializarPadraoBloco(){
    delete tabuleiro_; // Recriar o tabuleiro
    tabuleiro_ = new Tabuleiro(10);

    tabuleiro_->mudaEstado(4,4);
    tabuleiro_->mudaEstado(4,5);
    tabuleiro_->mudaEstado(5,4);
    tabuleiro_->mudaEstado(5,5);
    geracaoAtual = 0;
}

void Simulacao::inicializarPadraoPlanador(){
    delete tabuleiro_; // Recriar o tabuleiro
    tabuleiro_ = new Tabuleiro(10);

    tabuleiro_->mudaEstado(3,4);
    tabuleiro_->mudaEstado(3,5);
    tabuleiro_->mudaEstado(3,6);
    tabuleiro_->mudaEstado(4,4);
    tabuleiro_->mudaEstado(5,5);
    geracaoAtual = 0;
}
void Simulacao::inicializarPadraoPiscador(){
    delete tabuleiro_; // Recriar o tabuleiro
    tabuleiro_ = new Tabuleiro(10);

    tabuleiro_->mudaEstado(4,4);
    tabuleiro_->mudaEstado(4,5);
    tabuleiro_->mudaEstado(4,6);
    geracaoAtual = 0;
}
void Simulacao::inicializarPadraoSapo(){
    delete tabuleiro_; // Recriar o tabuleiro
    tabuleiro_ = new Tabuleiro(10);

    tabuleiro_->mudaEstado(4,5);
    tabuleiro_->mudaEstado(4,6);
    tabuleiro_->mudaEstado(4,7);
    tabuleiro_->mudaEstado(5,4);
    tabuleiro_->mudaEstado(5,5);
    tabuleiro_->mudaEstado(5,6);
    geracaoAtual = 0;
}
void Simulacao::inicializarPadraoBote(){
    delete tabuleiro_; // Recriar o tabuleiro
    tabuleiro_ = new Tabuleiro(10);

    tabuleiro_->mudaEstado(3,4);
    tabuleiro_->mudaEstado(3,5);
    tabuleiro_->mudaEstado(4,4);
    tabuleiro_->mudaEstado(4,6);
    tabuleiro_->mudaEstado(5,5);
    geracaoAtual = 0;
}

void Simulacao::inicializarPadraoEspacoNave(){}

void Simulacao::inicializarAleatorio(){}