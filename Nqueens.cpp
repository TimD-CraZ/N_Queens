#include <iostream>
using namespace std;

bool checkBoard(int n, int qcount, int x, int y, char **matrix, int **queens) {
    int row = x; // y coordinate
    int col = y; // x coordinate
    char l = 'Q';
    //cout << "checking queen no: " << qcount + 1 << ": at position: " << x << " " << y << endl;

    if(matrix[x][y] != l){
        //Checking row on left
        //cout << "enterd row col and diag checking" << endl;
        for (int i = 0; i < col; ++i) {
            //cout << row << i << matrix[row][i] << " ";
            //cout << matrix[row][i];
            if (matrix[row][i] == l) {
                return false;
            }
        }

        // Checking row on right
        for (int i = col + 1; i < n; ++i) {
            //cout << row << i << matrix[row][i] << " ";
            //cout << matrix[row][i];
            if (matrix[row][i] == l) {
                return false;
            }
        }
        //cout << endl;

        // checking above col
        for (int i = 0; i < row; ++i) {
            //cout << i << col << matrix[i][col] << " ";
            //cout << matrix[i][col];
            if (matrix[i][col] == l) {
                return false;
            }
        }

        // checking below col
        for (int i = row + 1; i < n; ++i) {
            //cout << i << col << matrix[i][col] << " ";
            //cout << matrix[i][col];
            if (matrix[i][col] == l) {
                return false;
            }
        }
        //cout << endl;
        
        // Checking upper diagonal on the left
        for (int i = row - 1, j = col - 1; i >= 0  && i < n && j >= 0 && j < n; --i, --j) {
            //cout << i << j << matrix[i][j] << " ";
            //cout << matrix[i][j];
            if (matrix[i][j] == l) {
                return false;
            }
        }

        // checking lower diagonal on the right
        for (int i = row + 1, j = col + 1; i >= 0  && i < n && j >= 0 && j < n; ++i, ++j) {
            //cout << i << j << matrix[i][j] << " ";
            //cout << matrix[i][j];
            if (matrix[i][j] == l) {
                return false;
            }
        }
        //cout << endl;
        
        // Checking lower diagonal on the left
        for (int i = row + 1, j = col - 1; i >= 0  && i < n && j >= 0 && j < n; ++i, --j) {
            //cout << i << j << matrix[i][j] << " ";
            //cout << matrix[i][j];
            if (matrix[i][j] == l) {
                return false;
            }
        }

        // Checking upper diagonal on the right
        for (int i = row - 1, j = col + 1; i >= 0  && i < n && j >= 0 && j < n; --i, ++j) {
            //cout << i << j << matrix[i][j] << " ";
            //cout << matrix[i][j];
            if (matrix[i][j] == l) {
                return false;
            }
        }
        //cout << endl;
    }

    else return false;

    return true;
}

void printBoard(int n, char **matrix){
    cout << "printing board" << endl;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y)
			std::cout << matrix[x][y] << " ";
		std::cout << std::endl;
    }
}

bool placeQueen(int n, int row, char **matrix, int **queens) {
    if (row == n) {
        // All queens have been successfully placed
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (checkBoard(n, 0, row, col, matrix, queens)) {
            // Place the queen in this position
            matrix[row][col] = 'Q';
            queens[row][0] = row;
            queens[row][1] = col;

            // Recursively try to place the next queen
            if (placeQueen(n, row + 1, matrix, queens)) {
                return true; // A solution was found
            }

            // If placing the queen here did not lead to a solution, backtrack
            matrix[row][col] = '_';
            queens[row][0] = -1;
            queens[row][1] = -1;
        }
    }

    return false; // No valid placement for this row
}	

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    char **matrix;
    int **queens; 
    int option = 0;
    int qcount = 0;
	
	matrix = (char **)malloc(n * sizeof(char*));
    //queens = (int **)malloc(20 * sizeof(int*));
	queens = (int **)malloc(n * sizeof(int*));
	
	for (int i = 0; i < n; i++){
		matrix[i] = (char *)malloc(n * sizeof(char));
		queens[i] = (int *)malloc(2 * sizeof(int));	
	}
      //for (int i = 0; i < 20; i++){
      //  queens[i] = (int *)malloc(2 * sizeof(int));	
      //}
		
	for (int x = 0; x < n; ++x) {
    	for (int y = 0; y < 2; ++y)
            queens[x][y] = 0;
	}
    
	//cout<< "Initializing Board..." << endl;
    for (int x = 0; x < n; ++x) {
    	for (int y = 0; y < n; ++y)
            matrix[x][y] = '_';
	}
	
	
    // cout<< "Printing Initial Board..." << endl;
    // printBoard(n, matrix);
    
    /*
    cout<< "Placing queen" << endl;
    if(n % 2 == 0){
        matrix[0][0] = 'Q';
        queens[0][0] = 0;
        queens[0][1] = 0;
        qcount++;
    }
    else{
        matrix[1][0] = 'Q';
        queens[0][0] = 0;
        queens[0][1] = 1;
        qcount++;
    }

    printBoard(n, matrix);

    
    for (int i = 0; i < n; ++i){
    	qcount = placeQueen(n, option, qcount, matrix, queens);
    	printBoard(n, matrix);
    }
	printBoard(n, matrix);

    for (int x = 0; x < 20; ++x) {           // printing queens array
		for (int y = 0; y < 2; ++y)
			std::cout << queens[x][y] << " ";
		std::cout << std::endl;
    }
    */
    if (placeQueen(n, 0, matrix, queens)) {
        cout << "Solution found:" << endl;
        printBoard(n, matrix);
    } else {
        cout << "No solution found for N = " << n << endl;
    }
    
	
					/*
                    cout<< "Testing Board Traversal..." << endl;
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
							cout<< "Placing Queen at : "<< i+1 << " " << j+1 << endl;
							matrix[i][j] = 'Q';

							printBoard(n, matrix);
							
							std::cout << std::endl;
							matrix[i][j] = '_';
						}
					}*/
    

	
    return 0;
}