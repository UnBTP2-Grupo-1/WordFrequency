#include "header/aux_functions.hpp"

int main(int argc, char *argv[]) {
  vector <string> words;

  try {
    if (argc == 1)
      throw invalid_argument("Nenhum argumento especificado");
    else if (argc > 2)
      throw invalid_argument("Especifique apenas um argumento");

    words = remove_stop_words(extract_words(argv[1]));
    
    print_vector(words);
    
  } 
  catch (const invalid_argument& exception) {
    cout << "Erro: " << exception.what() << endl;
  }

  return 0;
}