#ifndef CELULA_H
#define CELULA_H

class Celula{
    protected:
        bool vida_;
        int x_,y_;
    
    public:
        Celula(int x, int y, bool vida);
        virtual void interagir(int vizinhoVivos) = 0;
        bool getVida();
        void setVida(bool vida);
        int getX();
        int getY();


};
#endif