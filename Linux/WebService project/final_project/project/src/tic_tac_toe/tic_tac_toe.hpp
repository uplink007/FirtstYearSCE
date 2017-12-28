#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP
#include "fcgio.h"
#include <string>
#include <algorithm>

//MENU OPTIONS
const int START = 0;
const int CURRENT = 1;
const int MOVE = 2;
const int SURRENDER = 5;



const unsigned long STDIN_MAX = 1000000;


std::string get_request_content(const FCGX_Request & request);


void proccess_request(const char* uri);



void start_game(std::string& user);
void game_move(std::string& user, std::string& index);
void game_cpu_move(std::string& user, std::vector<int>& b);
bool is_won(std::string& user, int i,std::vector<int>& b);

#endif
