#ifndef UTIL_HPP
#define UTIL_HPP
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>


int num_of_params(const char* str, char tok);

char* get_sub_string(const char* str, int start , int end);

std::vector<std::string> split(const char* str, char tok);


void print_tokens(const std::vector<std::string>& tokens);


std::string print_game_state(std::string& name, std::string state, std::vector<int> board = std::vector<int> {0,0,0,0,0,0,0,0,0});
std::string print_current_state(std::string name);
std::string print_error_message(std::string msg);


std::string get_user_state(std::string& user);


bool write_to_file(std::string& state, std::string& user, std::vector<int> board = std::vector<int> {0,0,0,0,0,0,0,0,0});


bool is_empty(std::ifstream& file);

std::vector<int> get_board(std::string& user);



#endif
