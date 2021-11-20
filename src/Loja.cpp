
#include "../headers/Loja.hpp"

Loja::Loja(int id, int estoque, int x, int y) {
  this->id = id;
  this->estoque = estoque;
  this->x = x;
  this->y = y;
}

int Loja::GetX() { return this->x; }

int Loja::GetY() { return this->y; }

int Loja::GetId() { return this->id; }

int Loja::GetEstoque() { return this->estoque; }

void Loja::AddCliente(int idCliente) {
  if (this->estoque > 0) {
    this->clientes.push_back(idCliente);
    this->estoque--;
  }
}

void Loja::Imprimir() {
  if (this->clientes.size() != 0) {
    printf("%d\n", this->id);
    for(unsigned int i = 0; i < this->clientes.size(); i++) {
      printf("%d ", this->clientes[i]);
    }
    printf("\n");
  }
}