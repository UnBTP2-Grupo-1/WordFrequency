#ifndef AUX_FUNCTIONS_H  
#define AUX_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

vector<string> extract_words(string path);
void print_vector(vector <string> vector);
vector<string> remove_stop_words(vector<string> word_list);
string remove_special_character(string s);

#endif