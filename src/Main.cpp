#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "../headers/Cliente.hpp"
#include "../headers/Loja.hpp"

using namespace std;

bool ordena_clientes(Cliente A, Cliente B) {

  if(A.GetScore() > B.GetScore()) {
    return true ;
  } else if(A.GetScore() == B.GetScore()) {
    return  A.GetId() < B.GetId();
  } 
  return false;
}

int main() {
  int numLojas = 0, numClientes = 0;
  int x_grid = 0, y_grid = 0;
  vector<Loja> lojas;
  vector<Cliente> clientes;

  // Obtem os dados do grid
  scanf("%d %d", &x_grid, &y_grid);

  // Obtem o número de lojas
  scanf("%d", &numLojas);

  // Le as lojas
  for(int i=0; i < numLojas; i++){
    int estoque, x, y;
    scanf("%d %d %d", &estoque, &x, &y);  
    Loja l = Loja(i, estoque, x, y);
    lojas.push_back(l);
  } 

  // Obtem o número de clientes
  scanf("%d", &numClientes);
  // Le os clientes
  for(int i=0; i < numClientes; i++){ 
    int idade, x, y;
    string line, uf, tipo_pagamento;
    cin >> line;
    idade = stoi(line);
    cin >> uf;
    cin >> tipo_pagamento;
    cin >> line;
    x = stoi(line);
    cin >> line;
    y = stoi(line);

    Cliente c = Cliente(i, idade, uf, tipo_pagamento, x, y, lojas);

    clientes.push_back(c);
  } 

  sort(clientes.begin(), clientes.end(), ordena_clientes);

  // Percorre a lista de clientes e busca uma loja para elas
  for(unsigned int i = 0; i < clientes.size(); i++){
    Cliente c = clientes[i];
       bool adicionada = false;
    for(tuple<double,int> d: c.GetDistancias()){
      if(!adicionada && lojas.at(get<1>(d)).GetEstoque() > 0  ){
        // Adiciona o cliente na loja 
        lojas.at(get<1>(d)).AddCliente(c.GetId());
        adicionada = true;
        break;
      } 
    }
    if(!adicionada){
      break;
    }
  }

  for(int i=0; i < numLojas; i++){
    lojas.at(i).Imprimir();
  }
}