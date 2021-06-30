#include <iostream>
#include <cmath>
#include <algorithm>
#include "../headers/Pessoa.hpp"


Pessoa::Pessoa(int id,int idade, int x, int y, vector<Posto> postos){
    this->id =id;
    this->idade = idade;
    this->x = x;
    this->y =  y;
    this->distancias = CalculaDistancias(postos);
}

vector<tuple<float,int>> Pessoa::GetDistancias(){
  return this->distancias;
}

int Pessoa::GetId(){
  return this->id;
}

int Pessoa::GetIdade(){
  return this->idade;
}

int Pessoa::GetX(){
  return this->x;
}

int Pessoa::GetY(){
  return this->y;
}

// Calcula a distância de uma pessoa em relação a cada posto
vector<tuple<float,int>> Pessoa::CalculaDistancias(vector<Posto> postos){

  vector<tuple<float,int>> distancias;

  for(unsigned int i = 0; i < postos.size(); i++){
    Posto p = postos[i];
    float distancia = sqrt(pow((this->x - p.GetX()), 2) + pow((this->y - p.GetY()), 2));
    distancias.push_back({distancia, p.GetId()});
  } 
  // Ordena as distâncias criando um vector distancias de preferências pessoa->posto
  sort(distancias.begin(),distancias.end());

  return distancias;
}


