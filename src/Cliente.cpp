#include <iostream>
#include <cmath>
#include <algorithm>
#include "../headers/Cliente.hpp"

float GetScoreByUF(string uf) { 
  if(uf == "MG") {
    return 0.0;
  } else if(uf == "PR") {
    return 10.0;
  } else if(uf == "SP") {
    return 20.0;
  } else if(uf == "SC") {
    return 30.0;
  } else if(uf == "RJ") {
    return 40.0;
  } else if(uf == "RN") {
    return 50.0;
  } else if(uf == "RS") {
    return 60.0;
  } 
  return 0;
}

float GetScoreByTipoPagamento(string tipo_pagamento) {
  if(tipo_pagamento == "DINHEIRO") {
    return 1.0;
  } else if(tipo_pagamento == "DEBITO") {
    return 2.0;
  } else if(tipo_pagamento == "CREDITO") {
    return 3.0;
  } 
  return 0;
}

int calcDistance(int xOrig, int yOrig, int xDest, int yDest) {
    int moves = 0;
    while (abs(xOrig - xDest) > 1 || abs(yOrig - yDest) > 1) {
      int xDistance = xOrig - xDest;
      int yDistance = yOrig - yDest;
      if(xDistance > 1){
        xOrig--;

      } else if (xDistance < -1){
        xOrig++;
      }
      
      if(yDistance > 1){
        yOrig--;
      } else if (yDistance < -1){
        yOrig++;
      }

      moves++;
    }
    return moves;
}

bool ordenaDistancias(tuple<float,int> A, tuple<float,int> B) {

  if(get<0>(A) < get<0>(B)) {
    return true ;
  } else if(get<0>(A) == get<0>(B)) {
    return get<1>(A) < get<1>(B);
  } 
  return false;
}

float GetClienteScore(int idade, float uf_score, float tipo_pagamento_score) {
  return (abs(60.0 - idade) + uf_score)/tipo_pagamento_score;
}

Cliente::Cliente(int id,int idade, string uf, string tipo_pagamento, int x, int y, vector<Loja> lojas){
    this->id =id;
    this->idade = idade;
    this->uf = uf;
    this->uf_score = GetScoreByUF(uf);
    this->tipo_pagamento_score = GetScoreByTipoPagamento(tipo_pagamento);
    this->tipo_pagamento = tipo_pagamento;
    this->x_residencia = x;
    this->y_residencia =  y;
    this->distancias = CalculaDistancias(lojas);
    this->score = GetClienteScore(this->idade, this->uf_score, this->tipo_pagamento_score);
}

vector<tuple<float,int>> Cliente::GetDistancias(){
  return this->distancias;
}

int Cliente::GetId(){
  return this->id;
}

int Cliente::GetIdade(){
  return this->idade;
}

int Cliente::GetXResidencia(){
  return this->x_residencia;
}

int Cliente::GetYResidencia(){
  return this->y_residencia;
}
string Cliente::GetUF() {
  return this->uf;
}

string Cliente::GetTipoPagamento() {
  return this->tipo_pagamento;
}

float Cliente::GetTipoPagamentoScore() {
  return this->tipo_pagamento_score;
}

float Cliente::GetUFScore() {
  return this->uf_score;
}

float Cliente::GetScore() {
  return this->score;
}

// Calcula a distância de uma Cliente em relação a cada loja
vector<tuple<float,int>> Cliente::CalculaDistancias(vector<Loja> lojas){

  vector<tuple<float,int>> distancias;

  for(unsigned int i = 0; i < lojas.size(); i++){
    Loja l = lojas[i];
    float distancia = calcDistance(this->x_residencia, this->y_residencia, l.GetX(), l.GetY());
    distancias.push_back({distancia, l.GetId()});
  } 
  // Ordena as distâncias criando um vector distancias de preferências Cliente->loja
  sort(distancias.begin(),distancias.end(), ordenaDistancias);

  return distancias;
}


