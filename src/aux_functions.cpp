#include "../header/aux_functions.hpp"
#include <fstream>

vector<string> extract_words(string path){
  vector<string> word_list;
  ifstream input;
  string element;

  input.open(path);
  try{
    if(!input.is_open()){
      throw invalid_argument("Arquivo não encotrado no caminho especificado");
    }
    while (input >> element) {
      word_list.push_back(element);
    }
  }
  catch(const invalid_argument& e){
    throw e;
  }
  return word_list;
}

vector<string> remove_stop_words(vector<string> word_list){
  vector <string> stop_words;
  
  try{
    if(word_list.empty()){
      throw invalid_argument("Word list vazia");
    }
    stop_words = extract_words("./text/stop_words.txt");
    if(stop_words.empty()){
      throw invalid_argument("Stop words vazia");
    }
    
    for (int i = 0; i < stop_words.size(); i++){
      //Remover as stop_words da word_list
    }

  }
  catch(const invalid_argument& exception){
    throw exception;
  }
  return word_list;
}

void print_vector(vector<string> vector){
  for (int i = 0; i < vector.size(); i++){
    cout << vector[i] << '\n';
  }
}