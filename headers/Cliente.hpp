#ifndef Cliente_HPP
#define Cliente_HPP

#include "Loja.hpp"
#include <iostream>
#include <vector>
#include <tuple>

class Cliente {
  public:
    Cliente() {};
    Cliente(int id,int idade, string uf, string tipo_pagamento, int x, int y, vector<Loja> lojas);
    int GetId();
    int GetIdade();
    int GetXResidencia();
    int GetYResidencia();
    float GetUFScore();
    float GetTipoPagamentoScore();
    float GetScore();
    string GetUF();
    string GetTipoPagamento();
    void Imprime();
    vector<tuple<float, int>> GetDistancias();
  private:
    int id;
    int idade;
    string uf;
    string tipo_pagamento;
    int x_residencia;
    int y_residencia;
    float uf_score;
    float tipo_pagamento_score;
    float score;
    vector<tuple<float, int>> CalculaDistancias(vector<Loja> lojas);
    vector<tuple<float, int>> distancias;
};

#endif