#include "tabuleiro.h"


Tabuleiro::Tabuleiro(int linha, int coluna):
    linhas_(linha),colunas_(coluna),tamanhoMax_(50) {
        elementos_ = new Celula**[linha];
        for(int i = 0; i < linha;i++){
            elementos_[i] = new Celula*[coluna];
            for(int j = 0; j < coluna;j++){
                elementos_[i][j] = nullptr;
            }
        }
    }

Tabuleiro::~Tabuleiro(){
    for(int i = 0;i<linhas_;i++){
        for(int j = 0;j<colunas_;j++){
            delete elementos_[i][j];
        }
        delete elementos_[i];
    }
    delete elementos_;
}

