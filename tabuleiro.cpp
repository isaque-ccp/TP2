#include "tabuleiro.h"


Tabuleiro::Tabuleiro(int dimensao):
    dimensao_(dimensao),tamanhoMax_(50) {
        grade_ = new Celula**[dimensao_];
        for(int i = 0; i < dimensao_;i++){
            grade_[i] = new Celula*[dimensao_];
            for(int j = 0; j < dimensao_;j++){
                grade_[i][j] = new CelulaPadrao(i,j,false);
            }
        }
    }

Tabuleiro::~Tabuleiro(){
    for(int i = 0;i<dimensao_;i++){
        for(int j = 0;j<dimensao_;j++){
            delete grade_[i][j];
        }
        delete grade_[i];
    }
    delete grade_;
}

void Tabuleiro::aumentaTamanho(){
   bool expandirParaCima = false, expandirParaBaixo = false;
   bool expandirParaEsquerda = false, expandirParaDireita = false;

    // Verificar bordas horizontais (primeira e última linha)
    for (int y = 0; y < dimensao_; y++) {
        if (grade_[0][y] && grade_[0][y]->getVida()) expandirParaCima = true;
        if (grade_[dimensao_ - 1][y] && grade_[dimensao_ - 1][y]->getVida()) expandirParaBaixo = true;
    }
    // Verificar bordas verticais (primeira e última coluna)
    for (int x = 0; x < dimensao_; x++) {
        if (grade_[x][0] && grade_[x][0]->getVida()) expandirParaEsquerda = true;
        if (grade_[x][dimensao_ - 1] && grade_[x][dimensao_ - 1]->getVida()) expandirParaDireita = true;
    }

    if(dimensao_ >= tamanhoMax_)
        throw std::runtime_error("Limite de tamanho");
    else if(expandirParaBaixo || expandirParaCima || expandirParaDireita || expandirParaEsquerda && dimensao_ < tamanhoMax_){
    
            int novaDimensao = dimensao_ + 4;

            Celula*** novaGrade = new Celula**[novaDimensao];
            for(int i = 0; i < novaDimensao ; i < novaDimensao ){
                novaGrade[i] = new Celula*[novaDimensao];
                for(int j = 0 ; j < novaDimensao ; j++){
                    if(i <=  dimensao_ && j <= dimensao_){
                        novaGrade[i][j] = grade_[i][j]; 
                    } else {
                        novaGrade[i][j] = new CelulaPadrao(i,j,false);
                } 
            }
            for(int i = 0 ;  i < dimensao_ ; i++){
                for(int j = 0; j< dimensao_ ; j++){
                    delete grade_[i][j];
                }
                delete[] grade_[i];
            }
            delete[] grade_;

            grade_ = novaGrade;
            dimensao_ = novaDimensao;   
            }
    }
}

int Tabuleiro::contarVizinhos(int x , int y){
    int vizinhosVivos = 0;
    
    for(int dx = -1; dx <= 1;dx++)
        for(int dy = -1; dy <= 1;dy++){
            if(dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;

            if(nx >= 0 &&  nx < dimensao_ && ny < dimensao_ && grade_[nx][ny] && grade_[nx][ny]->getVida())
                vizinhosVivos++;
        }
        return  vizinhosVivos;
}   


void Tabuleiro::atualizarTabuleiro() {
    Celula*** novaGrade = new Celula**[dimensao_];
    for (int i = 0; i < dimensao_; ++i) {
        novaGrade[i] = new Celula*[dimensao_];
        for (int j = 0; j < dimensao_; ++j) {
            if (grade_[i][j]) {
                int vizinhosVivos = contarVizinhos(i, j);
                grade_[i][j]->interagir(vizinhosVivos);
                novaGrade[i][j] = grade_[i][j]; // Célula mantida ou alterada
            }
        }
    }

    // Substituir o grid antigo pelo novo
    for (int i = 0; i < dimensao_; i++){
        for(int j = 0;j<dimensao_;j++)
            delete grade_[i][j];
        delete[] grade_[i];
    }
    delete[] grade_;
    grade_ = novaGrade;
}

void Tabuleiro::exibir(){
    for (int i = 0; i < dimensao_; ++i) {
        for (int j = 0; j < dimensao_; ++j) {
            if (grade_[i][j]->getVida() == true) {
                std::cout << "+ ";
            } else {
                std::cout << "- "; // Representa células mortas
            }
        }
        std::cout << '\n';
    }
}
void Tabuleiro::mudaEstado(int x, int y){
    grade_[x][y]->setVida(true); 
}