#ifndef _NOH_H_
#define _NOH_H_

#include "coord.h"
#include "noh.h"

class Noh {
private:
    //Vari�veis
    Coord pos; /// Posi��o da celula Atual
    Coord ant; /// Posi��o da celula anterior
    double g; /// custo passado
    double h; /// custo futuro
public:
    //Consntrutores
    Noh(); // Construtor padr�o;
    Noh(const Noh& x); // Construtor por c�pia
    Noh(const Coord& post); //Construtor espec�fico com uma coordenada
    Noh(const Coord& post, const Coord& ante); //Construtor espec�fico com duas coordenadas
    Noh(const Coord& post, const Coord& ante, double a, double b); //Construtor espec�fico completo
    //M�todos da classe
    void heuristica(const Coord& Dest); //Calcula o menor custo poss�vel at� o destino
    Coord getPos(); //Retorna a posi��o do n�
    Coord getAnt(); //Retorna a posi��o do n�
    double getG() const;  //Retorna o custo passado do n�
    double getH() const;  //Retorna o custo futuro do n�
    double f() const;  //Retorna o custo total do n�

    //Sobrecarga de operadores
    bool operator () (const Noh& C);
    bool operator == (const Noh& x);
    bool operator == (const Coord& C);

    //Fazendo amizades entre as classes para compartilhar seus m�todos
    friend class Labirinto;
    friend class Coord;
};

#endif
