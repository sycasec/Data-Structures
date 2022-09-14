/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*   10/05/2021
*/

#include <iostream>
#include <string>
#include <stdlib.h>

#define GRID_SIZE 3

class Game{

private:
    char grid[GRID_SIZE][GRID_SIZE];

public:

    Game(){
        generate_grid();
        print_grid();
        check_for_win();

        while(true){
            prompt_turn();
            check_for_win();

            dummy_ai_opponent();
            print_grid();
            check_for_win();
        }
    }

    void check_for_win(){
        const char* winning_moves[8] = {
            "123", "456", "789", "147", "258", "369", "159", "753"
        };

        for (int i = 0; i < 8; i++){
            bool win = true;
            char prev_grid = '0';
            const char* winning_move = *(winning_moves + i);

            for (int index = 0; index < 3; index++) {
                char character = *(winning_move + index);

                int entered_num = character - '0';
                int grid_space = entered_num - 1;

                int row = grid_space / GRID_SIZE;
                int col = grid_space % GRID_SIZE;

                char grid_char = grid[row][col];

                if ( prev_grid == '0' ){
                    prev_grid = grid_char;
                } else if ( prev_grid == grid_char ){
                    continue;
                } else {
                    win = false;
                    break;
                }
            }

            if (win) {
                std::puts("******* We have a winner! *******");
                std::cout << "Looks like [" << prev_grid << "] won!, congratulations!" << std::endl;
                exit(0);

            }
        }
    }

    void prompt_turn(){
        std::string input;
        while(true){
            std::puts("Give box number [1-9] or (input J to halt process.)");
            std::getline(std::cin, input);

            if (input != ""){
                char entered = input.c_str()[0];
                if (entered >= '1' && entered <= '9'){
                    int entered_num = entered - '0';
                    int index = entered_num - 1;

                    int row = index / GRID_SIZE;
                    int col = index % GRID_SIZE;

                    char grid_position = grid[row][col];

                    if (grid_position == 'X' || grid_position == 'O'){
                        puts("That grid position is taken");
                    } else {
                        grid[row][col] = 'X';
                        break;
                    }

                } else if (entered == 'J') {
                    exit(0);
                } else {
                    std::puts("You can only play in the range 1-9.");
                }

            } else {
                std::puts("You must enter something :madge: ");
            }
        }
    }

    void dummy_ai_opponent(){
        while (true){
            int ai_choice = ( std::rand() % 9 ) + 1;
            int row = (ai_choice - 1) / GRID_SIZE;
            int col = (ai_choice - 1) / GRID_SIZE;

            char grid_position = grid[row][col];

            if( grid_position == 'X' || grid_position == 'O'){

                continue;
            } else {
                std::cout << "The dummy ai played at [" << ai_choice << "]." << std::endl;
                grid[row][col] = 'O';
                break;
            }
        }
    }


    void generate_grid(){
        int number = 1;
        for(int x = 0; x < GRID_SIZE; x++){
            for(int y = 0; y < GRID_SIZE; y++){
                grid[x][y] = std::to_string(number).c_str()[0];
                number += 1;
            }
        }
    }

    void print_grid(){
        std::cout << "\n-------------" << std::endl;
        for(int x = 0; x < GRID_SIZE; x++){
            std::cout << "|";
            for(int y = 0; y < GRID_SIZE; y++){
                std::cout << " " << grid[x][y] << " |";
            }
            std::cout << "\n-------------" << std::endl;
        }
    }
};

int main(int argc, char *argv[]){
    Game game;
    return 0;
}
