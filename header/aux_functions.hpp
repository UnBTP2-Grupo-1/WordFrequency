#ifndef AUX_FUNCTIONS_H  
#define AUX_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

vector<string> extract_words(string path);
void print_vector(vector <string> vector);
vector<string> remove_stop_words(vector<string> word_list);
string remove_special_character(string s);
map<string, int> frequencies(vector<string> word_list);
vector<string> sort(vector<string> word_freq);
vector<string> remove_duplicate(vector<string> v);
void print_map(map<string, int> map_element);

#endif