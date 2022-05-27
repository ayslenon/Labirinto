#include "noh.h"
#include <cmath>
#include <algorithm>

//Contrutores
Noh::Noh(){  // Construtor Padrão
    g = 0;
    h = 0;  //As coords vão ser definidas pelo construtor padrão da struct coordg
}
Noh::Noh(const Noh& x){ // Construtor por cópia
    pos = x.pos;
    ant = x.ant;
    g = x.g;
    h = x.h;
}
Noh::Noh(const Coord& post){ // Construtor específico de coordenadas
    pos = post;
}
Noh::Noh(const Coord& post, const Coord& ante){ // Construtor específico com uma coordenada
    pos = post;
}
Noh::Noh(const Coord& post, const Coord& ante, double a, double b){ // Construtor específico completo
    pos = post;
    ant = ante;
    g = a;
    h = b;
}
//Métodos da classe

void Noh::heuristica(const Coord& Dest)
{//Calcula o menor custo possível até o destino
  Coord delta = abs(Dest-pos);
  h = sqrt(2)*std::min(delta.lin,delta.col)+abs(delta.lin-delta.col);
}
Coord Noh::getPos()
{ //Retorna a posição do nó
	return (pos);
}
Coord Noh::getAnt()
{ //Retorna a posição do nó
	return (ant);
}
double Noh::getG() const
{ //Retorna o custo passado do nó
	return (g);
}
double Noh::getH() const
{ // Retorna o provável custo futuro
	return (h);
}

double Noh::f() const
{
    return (g+h);
}

//Sobrecarga de operadores
bool Noh::operator () (const Noh& C)
{
    return (f() <= C.f());
}

bool Noh::operator == (const Noh& x)
{
    return (pos == x.pos);
}

bool Noh::operator == (const Coord& C)
{
    return (pos == C);
}
