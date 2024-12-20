#include "tabuleiro.h"


Tabuleiro::Tabuleiro(int dimensao):
    dimensao_(dimensao),tamanhoMax_(50) {
        grade_ = new Celula**[dimensao_];
        for(int i = 0; i < dimensao_;i++){
            grade_[i] = new Celula*[dimensao_];
            for(int j = 0; j < dimensao_;j++){
                grade_[i][j] = new  CelulaPadrao(i,j,false);
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
    if(dimensao_ >= tamanhoMax_)
        throw std::runtime_error("Limite de tamanho");
    
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

