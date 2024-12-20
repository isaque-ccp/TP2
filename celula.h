#ifndef CELULA_H
#define CELULA_H

class Celula{
    protected:
    bool estadoAtual_; 
    bool proximoEstado_;

    public:
    Celula(bool estadoAtual); //construtor de celula
    ~Celula();

    virtual void interagir(int vizinhosVivos) = 0; //metodo poliformico
    void atualizaEstado(); //metodo para atualizar o estado da celula
    bool isAlive(); //metodo que retorna estado da celula

};
#endif