#include <stdio.h>

int count = 0;
int board[14][14];

int isSafe(int row, int col, int n) {
    int i = 0, j = 0;
    while(i < col){
        if (board[row][i]) 
            return 0;
        i = i + 1;
    }
    i = row;
    j = col;
    while(i>=0 && j>=0){
        if (board[i][j]) 
            return 0;
        i = i - 1;
        j = j - 1;
    }
    i = row;
    j = col;
    while(j>=0 && i<n){
        if (board[i][j]) 
            return 0;
        i = i + 1;
        j = j - 1;
    }
    return 1;
}

void solveNQUtil(int col, int n) {
    //printf("%d ",col);
    if (col >= n) {
        count = count + 1;
        return;
    }
    int i = 0;
    while(i < n){
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            solveNQUtil(col + 1, n);
            board[i][col] = 0;
        }
        i=i+1;
    }
}

void solveNQ(int n) {
    int i = 0, j = 0;
    while(i < n) {
        j = 0;
        while(j < n) {
            board[i][j] = 0;
            j = j + 1;
        }
        i = i + 1;
    }
    solveNQUtil(0, n);
    printf("Total solutions: %d\n", count);
}

int main() {
    int n = 6;
    solveNQ(n);
    return 0;
}
