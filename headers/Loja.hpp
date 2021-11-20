#ifndef Loja_HPP
#define Loja_HPP

#include <iostream>
#include <vector>

using namespace std;

class Loja {
  public:
    Loja() {};
    Loja(int id,int estoque, int x, int y);
    void Imprimir();
    int GetX();
    int GetY();
    int GetId();
    int GetEstoque();
    void AddCliente(int idCliente);
  private:
    int id;
    int estoque;
    int x;
    int y;
    vector<int> clientes;
};

#endif