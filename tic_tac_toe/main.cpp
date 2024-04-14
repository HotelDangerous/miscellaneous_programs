#include <iostream>
#include <vector>

void choose_square(int row, int col, char player_marker, std::vector<std::vector<char>> &board)
{
    /* When a player chooses a square and that square has not already been chosen, the square is marked with the players
     * marker (X or O). If the square has already been chosen, the player will be prompted to choose a new square. This
     * continues until the player chooses a legal square.*/

    while(true) {
        if ((row >= 0 and row < 3) and (col >= 0 and col < 3) and board[row][col] == '.') {
            board[row][col] = player_marker;
            break;
        } else {
            std::cout << "The square you have chosen is not a legal square. Please choose a new square.\n";
            std::cout << "Enter a row: ";
            std::cin >> row;
            std::cout << std::endl;
            std::cout << "Enter a column: ";
            std::cin >> col;
            std::cout << std::endl;
            row-=1; col-=1;
        }
    }
    for(int i = 0; i < 3; ++i){
         for (auto itr : board[i]){
             std::cout << itr << ' ';
         }
         std::cout << std::endl;
    }
}

bool check_for_winner(char player_marker, std::vector<std::vector<char>> &board)
{
    for (int i=0; i<3; ++i){
        // check rows
        if (board[i][0] == board[i][1] and board[i][0] == board[i][2] and board[i][0] == player_marker){
            std::cout << player_marker <<"'s Win!!!";
            return true;
        }
        // check columns
        if (board[0][i] == board[1][i] and board[0][i] == board[2][i] and board[0][i] == player_marker) {
            std::cout << player_marker << "'s Win!!!";
            return true;
        }
    }
    // check diagonals
    if ((board[0][0] == board[1][1] and board[0][0] == board[2][2] and board[0][0] == player_marker) or
        (board[2][0] == board[1][1] and board[2][0] == board[0][2] and board[2][0] == player_marker)){
        std::cout << player_marker << "'s Win!!!";
        return true;
    }
    return false;
}


int main() {
    // initialize an empty board and necessary variables
    char marker;
    int row_choice, column_choice;
    int turn_count = 0;
    std::vector<std::vector<char>> board= {{'.', '.', '.'},
                                           {'.', '.', '.'},
                                           {'.', '.', '.'}};

    // game starts, display empty board
    for(int i = 0; i < 3; ++i){
        for (auto itr : board[i]){
            std::cout << itr << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "Choose a row then a column. Separate your choice of the row and column by a [space]." << std::endl;

    // game begins
    while(true){
        // Player one's (X's) turn
        marker = 'X';
        std::cout << "Player 1, choose a row and column" << std::endl;
        std::cin >> row_choice >> column_choice;
        choose_square(row_choice-1, column_choice-1, marker, board);
        if(check_for_winner(marker, board)){
            break;
        }

        // after the 9th turn, if the game hasn't been won, then it's a draw
        if (++turn_count == 9){
            std::cout << "It's a Draw!";
            break;
        }

        //player two's (O's) turn
        marker = 'O';
        std::cout << "Player 2, choose a row and column" << std::endl;
        std::cin >> row_choice >> column_choice;
        choose_square(row_choice-1, column_choice-1, marker, board);
        if(check_for_winner(marker, board)){
            break;
        }
        ++turn_count;
    }

    return 0;
}
