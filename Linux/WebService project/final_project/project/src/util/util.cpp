#include "util.hpp"
#include <iostream>


int num_of_params(const char* str, char tok)
{
    int num=0;
    int i=0;

    while ( str[i] != '\0')
    {
        if(str[i]!= tok && str[i+1] == tok)
            num++;
        i++;
    }
    if(str[i-1] != tok)
        num++;

    return num;
}

char* get_sub_string(const char* str, int start , int end)
{
    int size = end - start + 2;
    char* new_str = new char[size];

    for(int i=0 ; i+start <= end ; i++)
        new_str[i] = str[i+start];

    new_str[size-1] = '\0';

    return new_str;
}



std::vector<std::string> split(const char* str, char tok)

{
    int num_params = num_of_params(str, tok); // number of parameters
    std::vector<std::string> array; // the array of strings
    int start=0 ,end=0, old_end = 0, j;
    std::string temp;
    for (int i=0; i < num_params; i++) // loop for each word
    {
        while(str[start] == tok) // ignore word that start with the token
            start++;

        j = start;
        bool flag = false;
        while (str[j] != '\0' && !flag) // while the end of the word hasn't changed
        {
            if(str[j]!= tok && str[j+1] == tok){ // if its the last character before the token
                end = j;
                flag = true;
            }
            j++;
        }

        if (old_end == end) // if the last word of the string doesn't has a token after it
            end = j-1;
        temp = get_sub_string(str, start , end);
        array.push_back(temp);
        start = end+1;
        old_end = end;
    }

    return array;
}


void print_tokens(const std::vector<std::string>& tokens)
{
    for(unsigned int i=0;i<tokens.size();i++)
        std::cout << tokens[i] << std::endl;
}



std::string print_game_state(std::string& name, std::string state, std::vector<int> board){
    std::stringstream ss;
    ss << "{" << std::endl;
    ss << "\"state\": \"" << state <<"\" ," << std::endl;
    ss << "\"name\": \"" << name << "\" ," << std::endl;
    ss << "\"board\": [ ";
    for(unsigned int i=0;i<board.size() - 1;i++){
        ss << board[i] << " , ";
    }
    ss <<  board[8] << " ]" << std::endl;
    ss << "}" << std::endl;



    return ss.str();
}


std::string print_error_message(std::string msg){
    std::stringstream ss;
    ss << "{" << std::endl;
    ss << "\"state\": \"error\" ," << std::endl;
    ss << "\"message\": \"" << msg << "\"" << std::endl;
    ss << "}" << std::endl;
    return ss.str();
}

bool is_empty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}




std::string get_user_state(std::string& user){
    std::ofstream file_check;
    //creating the file if does not exists
    file_check.open (user + ".json", std::ios_base::app);
    if(!file_check.is_open()){
        std::cout << print_error_message("couldnt open the user's data[ofstream] 1 ");
        return "error";
    }
    file_check.close();
    std::ifstream game;
    game.open(user + ".json", std::ios_base::app);
    if(!game.is_open()){
        std::cout << print_error_message("couldnt open the user's data[ifstream] 2");
        return "error";
    }
    if(is_empty(game)){
        return "empty";
    }
    //returning the state
    std::string state;
    game >> state; //"{"
    game >> state; //" "state":"
    game >> state; //" name of state"
    state.erase(std::remove(state.begin(), state.end(), '\"'), state.end());
    game.close();
    return state;
}

std::string print_current_state(std::string name){
    std::string state = get_user_state(name);
    if(state == "empty"){
        return print_error_message("We do not have data about new users");
    }
    else return print_game_state(name, state,get_board(name));
}




bool write_to_file(std::string& user, std::string& state, std::vector<int> board){

    std::ofstream user_file;
    //creating the file if does not exists
    user_file.open (user + ".json");
    if(!user_file.is_open()){
        std::cout << print_error_message("couldnt open the user's data");
        return false;
    }

    if(state == "started"){
        user_file << print_game_state(user, state);
    }
    else {
        user_file << print_game_state(user, state, board);
    }

    return true;
}



std::vector<int> get_board(std::string& user){
    std::vector<int> board {0,0,0,0,0,0,0,0,0};
    std::ofstream file_check;
    //creating the file if does not exists
    file_check.open (user + ".json", std::ios_base::app);
    if(!file_check.is_open()){
        return board;
    }
    file_check.close();
    std::ifstream game;
    game.open(user + ".json", std::ios_base::app);
    if(!game.is_open()){
        std::cout << print_error_message("couldnt open the user's data[ifstream] 3");
        return board;
    }
    if(is_empty(game)){
        return board;
    }
    std::string value;
    for(int i=0;i<9;i++)
        game >> value;
    //getting the values from the file
    for(int i=0;i<9;i++){
        game >> board[i];
        game >> value;
    }
    return board;





}