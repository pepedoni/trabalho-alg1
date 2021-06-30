
#include "../headers/Posto.hpp"

Posto::Posto(int id, int capacidade, int x, int y) {
  this->id = id;
  this->capacidade = capacidade;
  this->x = x;
  this->y = y;
}

int Posto::GetX() { return this->x; }

int Posto::GetY() { return this->y; }

int Posto::GetId() { return this->id; }

int Posto::GetCapacidade() { return this->capacidade; }

void Posto::AddPessoa(int idPessoa) {
  if (this->capacidade > 0) {
    this->pessoas.push_back(idPessoa);
    this->capacidade--;
  }
}

void Posto::Imprimir() {
  if (this->pessoas.size() != 0) {
    printf("%d\n", this->id);
    for(unsigned int i = 0; i < this->pessoas.size(); i++) {
      printf("%d ", this->pessoas[i]);
    }
    printf("\n");
  }
}