#include "../header/aux_functions.hpp"
#include <fstream>

string remove_special_character(string s) {
    for (int i = 0; i < s.size(); i++) {
      // Finding the character whose ASCII value fall under this range
      if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z') {   
        // erase function to erase the character
        s.erase(i, 1); 
        i--;
      }
    }
    
    return s;
}

vector<string> extract_words(string path) {
  vector<string> word_list;
  ifstream input;
  string element;

  input.open(path);
  try {
    if(!input.is_open()) {
      throw invalid_argument("Arquivo não encotrado no caminho especificado");
    }
    while (input >> element) { 
      word_list.push_back(remove_special_character(element));
    }
  }

  catch(const invalid_argument& e) {
    throw e;
  }

  return word_list;
}

vector<string> remove_stop_words(vector<string> word_list) {
  vector <string> stop_words;
  
  try {
    if(word_list.empty()) {
      throw invalid_argument("Word list vazia ou não encontrada");
    }

    stop_words = extract_words("./text/stop_words.txt");
    if(stop_words.empty()){
      throw invalid_argument("Stop words vazia");
    }
    
    for (int i = 0; i < stop_words.size(); i++) {
      //Remover as stop_words da word_list
    }

  }

  catch(const invalid_argument& exception) {
    throw exception;
  }

  return word_list;
}

void print_vector(vector<string> vector) {
  for (int i = 0; i < vector.size(); i++){
    cout << vector[i] << '\n';
  }
}