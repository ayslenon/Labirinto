#ifndef _NOH_H_
#define _NOH_H_

#include "coord.h"
#include "noh.h"

class Noh {
private:
    //Variáveis
    Coord pos; /// Posição da celula Atual
    Coord ant; /// Posição da celula anterior
    double g; /// custo passado
    double h; /// custo futuro
public:
    //Consntrutores
    Noh(); // Construtor padrão;
    Noh(const Noh& x); // Construtor por cópia
    Noh(const Coord& post); //Construtor específico com uma coordenada
    Noh(const Coord& post, const Coord& ante); //Construtor específico com duas coordenadas
    Noh(const Coord& post, const Coord& ante, double a, double b); //Construtor específico completo
    //Métodos da classe
    void heuristica(const Coord& Dest); //Calcula o menor custo possível até o destino
    Coord getPos(); //Retorna a posição do nó
    Coord getAnt(); //Retorna a posição do nó
    double getG() const;  //Retorna o custo passado do nó
    double getH() const;  //Retorna o custo futuro do nó
    double f() const;  //Retorna o custo total do nó

    //Sobrecarga de operadores
    bool operator () (const Noh& C);
    bool operator == (const Noh& x);
    bool operator == (const Coord& C);

    //Fazendo amizades entre as classes para compartilhar seus métodos
    friend class Labirinto;
    friend class Coord;
};

#endif
