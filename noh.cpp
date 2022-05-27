#include "noh.h"
#include <cmath>
#include <algorithm>

//Contrutores
Noh::Noh(){  // Construtor Padr�o
    g = 0;
    h = 0;  //As coords v�o ser definidas pelo construtor padr�o da struct coordg
}
Noh::Noh(const Noh& x){ // Construtor por c�pia
    pos = x.pos;
    ant = x.ant;
    g = x.g;
    h = x.h;
}
Noh::Noh(const Coord& post){ // Construtor espec�fico de coordenadas
    pos = post;
}
Noh::Noh(const Coord& post, const Coord& ante){ // Construtor espec�fico com uma coordenada
    pos = post;
}
Noh::Noh(const Coord& post, const Coord& ante, double a, double b){ // Construtor espec�fico completo
    pos = post;
    ant = ante;
    g = a;
    h = b;
}
//M�todos da classe

void Noh::heuristica(const Coord& Dest)
{//Calcula o menor custo poss�vel at� o destino
  Coord delta = abs(Dest-pos);
  h = sqrt(2)*std::min(delta.lin,delta.col)+abs(delta.lin-delta.col);
}
Coord Noh::getPos()
{ //Retorna a posi��o do n�
	return (pos);
}
Coord Noh::getAnt()
{ //Retorna a posi��o do n�
	return (ant);
}
double Noh::getG() const
{ //Retorna o custo passado do n�
	return (g);
}
double Noh::getH() const
{ // Retorna o prov�vel custo futuro
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
