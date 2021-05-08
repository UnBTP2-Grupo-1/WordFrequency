#include "header/aux_functions.hpp"

int main(int argc, char *argv[]) {
  try {
    if (argc == 1)
      throw invalid_argument("Nenhum argumento especificado");
    else if (argc > 2)
      throw invalid_argument("Especifique apenas um argumento");

    cout << argv[1] << endl;
    word_count("teste");
  } 
  catch (const invalid_argument& e) {
    cout << "Erro: " << e.what() << endl;
  }

  return 0;
}