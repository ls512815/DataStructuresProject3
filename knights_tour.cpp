/* 
Name: Lydia Shiffler 
Date: 3/23/18
Description: Knights tour get_moves() and move() function
*/


#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves) 
{
  int row1 = 0;
  int col1 = 0;
  if(row - 1 >= 0 && col + 2 <= 4 && board[row - 1][col +2] == 0)
  {
    row_moves[row1] = row - 1;
    col_moves[col1] = col + 2;
    row1++;
    col1++;
    num_moves++;
  }
  if(row + 1 <= 4 && col +2 <= 4 && board[row + 1][col + 2] == 0)
  {
    row_moves[row1] = row + 1;
    col_moves[col1] = col + 2;
    row1++;
    col1++;
    num_moves++;
  }
  if(row + 2 <= 4 && col +2 <= 4 && board[row + 2][col + 1] == 0)
  {
    row_moves[row1] = row + 2;
    col_moves[col1] = col + 1;
    row1++;
    col1++;
    num_moves++;
  }
  if (row + 2 <= 4 && col - 1 >= 0 && board[row + 2][col - 1] == 0)
  {
    row_moves[row1] = row + 2;
    col_moves[col1] = col - 1;
    row1++;
    col1++;
    num_moves++;
  }
  if (row + 1 <= 4 && col - 2 >= 0 && board[row + 1][col - 2] == 0)
  {
    row_moves[row1] = row + 1;
    col_moves[col1] = col - 2;
    row1++;
    col1++;
    num_moves++;
  }
  if (row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == 0)
  {
    row_moves[row1] = row - 1;
    col_moves[col1] = col - 2;
    row1++;
    col1++;
    num_moves++;
  }
  if (row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == 0)
  {
    row_moves[row1] = row - 2;
    col_moves[col1] = col - 1;
    row1++;
    col1++;
    num_moves++;
  }
  if (row - 2 >= 0 && col + 1 <= 4 && board[row - 2][col + 1] == 0)
  {
    row_moves[row1] = row - 2;
    col_moves[col1] = col + 1;
    row1++;
    col1++;
    num_moves++;
  }

}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) 
{
  int moves = 0;
  int rMoves[8];
  int cMoves[8];
  m++;
  board[row][col] = m;
  get_moves(row, col, rMoves, cMoves, moves);
  if(m >= 25)
  {
    cout << "You found the knights tour!" << endl;
    print();
    num_tours++;
    m--;
    board[row][col] = 0;
    return;
  }
  if(moves == 0)
  {
    m--;
    board[row][col] = 0;
    return;
  }
  for(int i = 0; i < moves; i++)
  {
    move(rMoves[i], cMoves[i], m, num_tours);
  }
  m--;
  board[row][col] = 0;
  return;
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
