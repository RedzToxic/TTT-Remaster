#include <iostream>

using namespace std;

char grid[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};

char player_one_symbol = 'X';
char player_two_symbol = 'O';

// Just prints the grid
void Grid() {

    for (int n = 0; n < 3; n++) {

        for (int m = 0; m < 3; m++) {

            cout << grid[n][m] << " ";
        }
        cout << "\n";
    }
}

// Resets the grid. Goes through and makes a new one and puts those values into the grid
void Reset_Grid() {

    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 3; j++) {
            grid[i][j] = '.';
        }
    }
}

// Checks for a win 
bool Check_Win(char player_symbol) {

    // Horizontal check
    if (player_symbol == grid[0][0] && player_symbol == grid[0][1] && player_symbol == grid[0][2] ||
        player_symbol == grid[1][0] && player_symbol == grid[1][1] && player_symbol == grid[1][2] ||
        player_symbol == grid[2][0] && player_symbol == grid[2][1] && player_symbol == grid[2][2] ||
    
    // Vertical check
        player_symbol == grid[0][0] && player_symbol == grid[1][0] && player_symbol == grid[2][0] ||
        player_symbol == grid[0][1] && player_symbol == grid[1][1] && player_symbol == grid[2][1] ||
        player_symbol == grid[0][2] && player_symbol == grid[1][2] && player_symbol == grid[2][2] ||
    
    //Diagonal Check
        player_symbol == grid[0][0] && player_symbol == grid[1][1] && player_symbol == grid[2][2] ||
        player_symbol == grid[0][2] && player_symbol == grid[1][1] && player_symbol == grid[2][0]) {
            return false;
        }
    return true;
}

// Checks if index is a int or not
bool Check_User_Input(int user_input) {

    if (cin.fail()) {
        cout << "Enter a integer! \n";
        cin.clear();
        cin.ignore();

        return false;
    }
    return true;
}

// Gets row position for either user
int Get_Row(string prompt) {
    
    int row_space;

    cout << prompt;
    cin >> row_space;

    if (Check_User_Input(row_space) == false) {
        return Get_Row(prompt);
    } 

    return row_space;
}

// Gets col position for either user
int Get_Col(string prompt) {

    int col_space;

    cout << prompt;
    cin >> col_space;

    if (Check_User_Input(col_space) == false) {
        return Get_Col(prompt);
    }

    return col_space;
}

// Asks if user wants to continue
bool Continue_Game(int player_one_win, int player_two_win, int counter) {

    char user_input;

    cout << "Continue playing? Y/N: ";
    cin >> user_input;
    cout << "\n";

    if (user_input == 'Y' || user_input == 'y') {

        cout << "Score \n";
        cout << "Player one: " << player_one_win << "\n";
        cout << "Player two: " << player_two_win << "\n";
        cout << "Draw: " << counter << "\n";
        cout << "\n"; 

        return true;
    }

    else if (user_input == 'N' || user_input == 'n') {

        return false;
     }

    else {
        cout << "Answer properly! \n";
        return Continue_Game(player_one_win, player_two_win, counter);
    }
}


int main() {
   
    int while_counter = 0;
    int draw_counter = 0;

    int player_one_wins = 0;
    int player_two_wins = 0;

    cout << "Welcome to TTT. \n";

    while (while_counter < 5) {

        // Gets player one's input
        int player_one_row = Get_Row("First player place your row: ");
        int player_one_col = Get_Col("First player place your col: ");

        // Places gained int's into n and m as well as placing the symbol there.
        grid[player_one_row][player_one_col] = player_one_symbol;


        // Checks if player one has won
        if (Check_Win(player_one_symbol) == false) {

            cout << "Player One Wins! \n";
            Grid();
            player_one_wins++;

            while_counter = 0;
            Reset_Grid();

            if (Continue_Game(player_one_wins, player_two_wins, draw_counter) == false) {
                break;
            }
            continue;
        }

        // Draw check
        if (while_counter == 4) {

            draw_counter++;

            cout << "It's a draw! \n";

            while_counter = 0;
            Reset_Grid();

            if (Continue_Game(player_one_wins, player_two_wins, draw_counter) == false) {
                break;
            }
            continue;
        }

        Grid();

        // Gets player two's input
        int player_two_row = Get_Row("Second player place your row: ");
        int player_two_col = Get_Col("Second player place your col: ");

        grid[player_two_row][player_two_col] = player_two_symbol;
        
        // Checks if player two has won
        if(Check_Win(player_two_symbol) == false) {

            cout << "Player Two Wins! \n";
            Grid();
            player_two_wins++;

            while_counter = 0;
            Reset_Grid();

            if (Continue_Game(player_one_wins, player_two_wins, draw_counter) == false) {
                break;
            }
            continue;
        }

        Grid();
        
        while_counter++;
    }  
    return 0;
}