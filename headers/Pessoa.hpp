#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "Posto.hpp"
#include <iostream>
#include <vector>
#include <tuple>

class Pessoa {
  public:
    Pessoa() {};
    Pessoa(int id,int idade, int x, int y, vector<Posto> postos);
    int GetId();
    int GetIdade();
    int GetX();
    int GetY();
    void Imprime();
    vector<tuple<float, int>> GetDistancias();
  private:
    int id;
    int idade;
    int x;
    int y;
    vector<tuple<float, int>> CalculaDistancias(vector<Posto> postos);
    vector<tuple<float, int>> distancias;
};

#endif