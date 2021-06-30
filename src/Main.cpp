#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "../headers/Pessoa.hpp"
#include "../headers/Posto.hpp"

using namespace std;

bool ordena_pessoas(Pessoa A, Pessoa B) {
  if(A.GetIdade() > B.GetIdade()) {
    return true ;
  } else if(A.GetIdade() == B.GetIdade()) {
    return  A.GetId() < B.GetId();
  } 
  return false;
}

int main() {
  int numPostos = 0, numPessoas = 0;
  vector<Posto> postos;
  vector<Pessoa> pessoas;

  // Obtem o número de postos
  scanf("%d", &numPostos);

  // Le os postos
  for(int i=0; i < numPostos; i++){
    int capacidade, x, y;
    scanf("%d %d %d", &capacidade, &x, &y);  
    Posto p = Posto(i, capacidade, x, y);
    postos.push_back(p);
  } 

  // Obtem o número de pessoas
  scanf("%d", &numPessoas);
  // Le as pessoas
  for(int i=0; i < numPessoas; i++){
    int idade, x, y;
    scanf("%d %d %d", &idade, &x, &y);  
    Pessoa p = Pessoa(i, idade, x, y, postos);
    pessoas.push_back(p);
  } 

  sort(pessoas.begin(), pessoas.end(), ordena_pessoas);

  // Percorre a lista de pessoas e busca um posto para elas
  for(unsigned int i = 0; i < pessoas.size(); i++){
    Pessoa p = pessoas[i];

    bool adicionada = false;
    for(tuple<double,int> d: p.GetDistancias()){

      if(!adicionada && postos.at(get<1>(d)).GetCapacidade() > 0  ){
        // Adiciona a pessoa no posto 
        postos.at(get<1>(d)).AddPessoa(p.GetId());
        adicionada = true;
      }
    }
    if(!adicionada){
      break;
    }
  }

  for(int i=0; i < numPostos; i++){
    postos.at(i).Imprimir();
  }
}