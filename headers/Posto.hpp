#ifndef POSTO_HPP
#define POSTO_HPP

#include <iostream>
#include <vector>

using namespace std;

class Posto {
  public:
    Posto() {};
    Posto(int id,int capacidade, int x, int y);
    void Imprimir();
    int GetX();
    int GetY();
    int GetId();
    int GetCapacidade();
    void AddPessoa(int idPessoa);
  private:
    int id;
    int capacidade;
    int x;
    int y;
    vector<int> pessoas;
};

#endif