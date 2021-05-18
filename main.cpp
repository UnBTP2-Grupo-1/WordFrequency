#include "header/aux_functions.hpp"

int main(int argc, char *argv[]) {
  vector <string> words;
  map<string, int> word_frequencies;

  try {
    if (argc == 1)
      throw invalid_argument("No argument. Please, insert an argument.");
    else if (argc > 2)
      throw invalid_argument("Specify just one argument.");

    words = remove_stop_words(extract_words(argv[1]));
    word_frequencies = frequencies(words);
    
    print_vector(words);
    print_map(word_frequencies);
    
  } 
  
  catch (const invalid_argument& exception) {
    cout << "Erro: " << exception.what() << endl;
  }

  return 0;
}