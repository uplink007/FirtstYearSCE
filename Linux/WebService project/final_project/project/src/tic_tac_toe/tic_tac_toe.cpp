
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <stdlib.h> //for rand

#include "tic_tac_toe.hpp"
#include "../util/util.hpp"


/*
g++ hello_world.cpp -lfcgi++ -lfcgi
sudo nginx -c ~/Projects/linux_env/project/code/nginx.conf 
spawn-fcgi -p 8000 -n a.out


*/


const std::map<std::string,int> MENU = {
    {"start", 0},
    {"current", 1},
    {"move", 2},
    {"surrender", 5}
};


int main(void){
    std::cout <<"NEW VERSION\n";
    std::streambuf * cin_streambuf = std::cin.rdbuf();
    std::streambuf * cout_streambuf = std::cout.rdbuf();
    std::streambuf * cerr_streambuf = std::cerr.rdbuf();


    FCGX_Request request;

    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    while(FCGX_Accept_r(&request) == 0){
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        //getting the request uri

        const char* uri = FCGX_GetParam("REQUEST_URI", request.envp);

        std::cin.rdbuf(&cin_fcgi_streambuf);
        std::cout.rdbuf(&cout_fcgi_streambuf);
        std::cerr.rdbuf(&cerr_fcgi_streambuf);




        std::cout <<"Content-type: application/json; charset=ISO-8859-1\r\n\r\n";
        proccess_request(uri);


    }
    std::cin.rdbuf(cin_streambuf);
    std::cout.rdbuf(cout_streambuf);
    std::cerr.rdbuf(cerr_streambuf);


    return 0;
}



void proccess_request(const char* uri){
    std::vector<std::string> tokens = split(uri, '/');

    if(tokens.size() < 2){
        std::cout << print_error_message("Not enough arguments");
        return;
    }
    try{
        switch(MENU.at(tokens[1])){
            case START:
                start_game(tokens[0]);
                break;
            case SURRENDER:
                if(get_user_state(tokens[0]) == "move" || get_user_state(tokens[0]) == "started"){
                    std::cout << print_game_state(tokens[0], tokens[1], get_board(tokens[0])); // remember to get board
                    write_to_file(tokens[0], tokens[1], get_board(tokens[0]));
                }
                else
                   std::cout << print_error_message("You should start a new game before surrendering...");
                break;
            case CURRENT:
                std::cout << print_current_state(tokens[0]);
                break;
            case MOVE:
                if(tokens.size() > 2){
                    game_move(tokens[0], tokens[2]);
                }
                else{
                    std:: cout << print_error_message("Please add the placement");
                    return;
                }
                break;
            default:
                std::cout << print_error_message("No such argument");
       }
    }
    catch(std::out_of_range &e){
        std::cout << print_error_message("No such option");
    }

}




void start_game(std::string& user){

    std::string state = get_user_state(user);
    //if we can start a new game
    if(state == "move" || state == "started")
        std::cout << print_error_message("You are already in the middle of a game!");
    else if(state == "error")
        std::cout << print_error_message("An error has occured starting a new game");
    else{
        std::cout << print_game_state(user, "started");
        state = "started";
        int tmp[] ={0,0,0,0,0,0,0,0,0};
        write_to_file(user, state, std::vector<int>(tmp,tmp+9));
    }
}


void game_move(std::string& user, std::string& index){

    std::string state = get_user_state(user);



    if(state == "empty" || state == "surrender" || state == "won" || state == "lost" || state == "draw"){
        std::cout << print_error_message("You have to start a new game first!");
    }
    else if(state != "error"){
        std::vector<int> board = get_board(user);
        int i = -1;
        try{
            i = stoi(index);
        }
        catch(std::invalid_argument& e){
            std::cout << print_error_message("Please input an integer");
            return;
        }
        if(i < int(board.size()) && i >= 0){
            if(board[i] != 0)
                std::cout << print_error_message("Illegal move - not an empty place");
            else{
                board[i] = 1;
                std::string new_state;
                if(is_won(user,1,board))
                    new_state = "won";
                else{
                    bool is_over = true;
                    for(int i=0; i<9;i++)
                        if(board[i] == 0)
                            is_over = false;
                    if(!is_over){
                        game_cpu_move(user,board);
                        if(is_won(user,2,board))
                            new_state = "lost";
                        else
                            new_state = "move";
                    }
                    else
                        new_state = "draw";
                }
                std:: cout << print_game_state(user, new_state, board);
                write_to_file(user, new_state, board);
            }
        }
        else
            std::cout << print_error_message("Illegal move");

    }

}
// i is the symbol of the player
// 1 - player
// 2- cpu
bool is_won(std::string& user, int i,std::vector<int>& b){
    
    if(b[0] == i  && (
        (b[0] == b[1] && b[1] == b[2]) ||
        (b[0] == b[3] && b[3] == b[6]) ||
        (b[0] == b[4] && b[4] == b[8]) ))
    {
        return true;
    }

    if(b[1] == i && (b[1] == b[4] && b[4] == b[7]))
        return true;
    if(b[2] == i  && (
        (b[2] == b[5] && b[5] == b[8]) ||
        (b[2] == b[4] && b[4] == b[6])))
        return true;

    if(b[3] == i && (b[3] == b[4] && b[4] == b[5]))
        return true;
    if(b[6] == i && (b[6] == b[7] && b[7] == b[8]))
        return true;

    return false;

}




void game_cpu_move(std::string& user,std::vector<int>& board){

    srand(time(NULL));
    int placement = rand() % 9;
    int i = 0;
    while(board[placement] != 0 && i < 9){
        placement +=1;
        placement %=9;
        i++;
    }
    if( i != 9)
        board[placement] = 2;

}
