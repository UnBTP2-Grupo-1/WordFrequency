#include "../header/aux_functions.hpp"

string remove_special_character(string word) {
  for (int counter = 0; counter < word.size(); counter++) {

    // Finding the character whose ASCII value fall under this range
    if (word[counter] < 'A' || word[counter] > 'Z' && word[counter] < 'a' || word[counter] > 'z') {   
      // erase function to erase the character
      word.erase(counter, 1); 
      counter--;
    } else {
      word[counter] = tolower(word[counter]);  // lower letter
    }

  }

  return word;
}

vector<string> extract_words(string path) {
  vector<string> word_list;
  ifstream input;
  string element;

  input.open(path);
  try {
    if(!input.is_open()) {
      throw invalid_argument("File not found. Please, specify the correct path.");
    }
    while (input >> element) { 
      string word_temp = remove_special_character(element);
      if(!word_temp.empty()) word_list.push_back(word_temp);
    }
  }

  catch(const invalid_argument& e) {
    throw e;
  }

  return word_list;
}

vector<string> remove_stop_words(vector<string> word_list) {
  vector <string> stop_words;
  ifstream input_stop_word("text/stop_words.txt");
  string element_stop_word;
  
  try {
    if(word_list.empty()) {
      throw invalid_argument("Empty word list or not found");
    } else {
      while (getline(input_stop_word, element_stop_word,',')) {
        if(element_stop_word.size() > 0)
          stop_words.push_back(element_stop_word);
      }
    }

    if(stop_words.empty()){
      throw invalid_argument("Empty stop words list");
    }
    
    for (int counter = 0; counter < stop_words.size(); counter++) {
      //Remove stop_words from word_list
      word_list.erase(remove(word_list.begin(), word_list.end(), stop_words[counter]), word_list.end());
    }

  }

  catch(const invalid_argument& exception) {
    throw exception;
  }

  return word_list;
}

void frequencies(vector<string> word_list) {
  map<string, int> word_list_frequencies;
  vector<string> word_list_uniques;

  try {
    if(word_list.empty()) {
      throw invalid_argument("Empty word list or not found");
    } else {
      word_list_uniques = remove_duplicate(word_list);
      
      for(int counter = 0; counter < word_list_uniques.size(); counter++) {
        int freq_counter = 0;

        for(int inner_counter = 0; inner_counter < word_list.size(); inner_counter++) {
          if(word_list_uniques[counter] == word_list[inner_counter]) freq_counter++;
        }

        word_list_frequencies.insert(pair<string, int>(word_list_uniques[counter], freq_counter));
      }

      print_map(word_list_frequencies);
    }

  }

  catch(const invalid_argument& exception) {
    throw exception;
  }

  //return word_list_frequencies;
}

/*vector<string> sort(vector<string> word_freq) {
  
  try {
    if(word_freq.empty()) {
      throw invalid_argument("Empty word list or not found");
    } else {

    }

  }

  catch(const invalid_argument& exception) {
    throw exception;
  }

  return word_freq;
}*/

void print_vector(vector<string> vector) {
  for (int i = 0; i < vector.size(); i++){
    cout << vector[i] << '\n';
  }

  cout << "=======";
}

vector<string> remove_duplicate(vector<string> v) {
  vector<string> v_out;

  for(int counter = 0; counter < v.size(); counter++) {
    if (!(find(v_out.begin(), v_out.end(), v[counter]) != v_out.end())) {
      v_out.push_back(v[counter]);
    }
  }

  return v_out;
}

void print_map(map<string, int> map_element) {

  // Printing map
  map<string, int>::iterator itr;

  cout << "\nThe word frequency is: \n";
  cout << "\tWORD\t\tFREQUENCY\n";

  for (itr = map_element.begin(); itr != map_element.end(); ++itr) {
      cout << '\t' << itr->first << '\t' << '\t' << itr->second << '\n';
  }

  cout << endl;
}
 