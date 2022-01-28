/*
 * Name: Charlie Hartsell
 * Date Submitted: April 9, 2021
 * Lab Section: 004
 * Assignment Name: Lab 9
 */

#include <iostream>
#include <vector>

using namespace std;

// Global int to hold number of solutions
int solutions;

// Given a position in the grid, this function checks whether it is safe
bool checkSafety(vector<vector<int>> table, int r, int c) {
    // We only need to check the left side, since this function
    // inserts only one queen per column and moves left to right

    // I realize now these are dumb variable names 
    // But I don't feel like changing them
    // cr = Check Row, cc = Check Column
    int cr, cc, n;
    n = table.size();

    // Check upper left
    for(cr=r, cc=c; cr>=0 && cc>=0; cr--, cc--) {
        if(table[cr][cc] == 1) {
            return false;
        }
    }

    // Check left
    for(cc=0; cc<c; cc++) {
        if(table[r][cc] == 1) {
            return false;
        }
    }

    // Check lower left
    for(cr=r, cc=c; cc>=0 && cr<n; cr++, cc--) {
        if(table[cr][cc] == 1) {
            return false;
        }
    }

    // Safe!
    return true;
}

// Goes row by row through a column determining if there is a solution
// table.size() is equivalent to N; c is starting column number
bool solveNQ(vector<vector<int>> table, int c) {
    int n = table.size();
    
    // Base case
    if(c >= n) {
        solutions++;
        return true;
    }

    // Loop through each row
    bool switcher = false;
    for(int i = 0; i < n; i++) {
        if(checkSafety(table, i, c)) {
            // Add queen
            table[i][c] = 1;

            // Move to next column with added queen
            switcher = solveNQ(table, c+1);

            // Remove queen
            table[i][c] = 0;
        }
    }

    // Backtrack
    return switcher;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess table
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions

    // Create n x n vector of false
    vector<vector<int>> table;
    for(int i = 0; i < n; i++) {
        vector<int> column(n, 0);
        table.push_back(column);
    }

    // Compute the number of solutions:

    // Set global variable to 0
    solutions = 0;

    // Run the recursive function on column 0
    solveNQ(table, 0);

    // Return the number of solutions
    return solutions;
}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}