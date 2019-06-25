#include <iostream>
#include <cstring>

struct Telefone {
  int residencial, celular1, celular2;
};

struct Data {
  short dia;
  std::string mes;
  int ano;
};

struct Dados {
  long int cpf;
  int rg, tia;
};

int main() {
  struct Telefone TCarlos, *pontTele;
  pontTele = &TCarlos;
  pontTele->residencial = 94620163;
  pontTele->celular1 = 973213300;
  pontTele->celular2 = 988220192;
  std::cout << "Carlos" << std::endl;
  std::cout << "\nTelefones" << std::endl;
  std::cout << "Residencial: " << pontTele->residencial << std::endl;
  std::cout << "Celular 1: " << pontTele->celular1 << std::endl;
  std::cout << "Celular 2: " << pontTele->celular2 << std::endl;

  struct Data NascimentoCarlos, *pontData;
  pontData = &NascimentoCarlos;
  pontData->dia = 13;
  pontData->mes = "Junho";
  pontData->ano = 1997;
  std::cout << "\nData de Nascimento: " << pontData->dia << '/' << pontData->mes << '/' << pontData->ano << std::endl;

  struct Dados DCarlos, *pontDados;
  pontDados = &DCarlos;
  pontDados->cpf = 93702312209;
  pontDados->rg = 921249570;
  pontDados->tia = 41802391;
  std::cout << "\nDados" << std::endl;
  std::cout << "CPF: " << pontDados->cpf << std::endl;
  std::cout << "RG: " << pontDados->rg << std::endl;
  std::cout << "TIA: " << pontDados->tia << std::endl;
}