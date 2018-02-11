#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARDSIZE 256

int counter = 0;

struct Point
{
  int i;
  int j;
  int k;
  int l;
};

int get_tile(int board[BOARDSIZE][BOARDSIZE], int n, Point a, int i, int j);


//printing for debugging
void print_board(int board[BOARDSIZE][BOARDSIZE])
{
  int i, j;
  for (i = 0; i < BOARDSIZE; i++)
  {
    for(j = 0; j < BOARDSIZE; j++)
    {
      printf(" %d, ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");

}

int place_tile(int board[BOARDSIZE][BOARDSIZE], int n, Point a, int i, int j)
{
  Point c; // center point

  c.i = n/2 + i;
  c.j = n/2 + j;

  Point tr, tl, br, bl, br2; //points for each quadrant

  tr.i = c.i - 1;
  tr.j = c.j;

  tl.i = c.i - 1;
  tl.j = c.j - 1;

  bl.i = c.i;
  bl.j = c.j - 1;

  br.i = c.i;
  br.j = c.j;

   br2.i = c.i + 1;
   br2.j = c.j + 1;

  if (a.i >= c.i && a.j >= c.j) //if given point is in bottom_right
  {
    // printf("bottom_right\n");
    // printf("POINT: (%d, %d)\n", a.i, a.j);
    // printf("CENTER: (%d, %d)\n", c.i, c.j);

      board[tr.i][tr.j] = counter;
      board[tl.i][tl.j] = counter;
      board[bl.i][bl.j] = counter;

    //print_board(board);


      br.i = a.i;
      br.j = a.j;

  }

  else if(a.i >= c.i && a.j < c.j) //if given point is in bottom_left
  {
    // printf("bottom_left\n");
    // printf("POINT: (%d, %d)\n", a.i, a.j);
    // printf("CENTER: (%d, %d)\n", c.i, c.j);

      board[br.i][br.j] = counter;
      board[tl.i][tl.j] = counter;
      board[tr.i][tr.j] = counter;

    //print_board(board);

    bl.i = a.i;
    bl.j = a.j;

  }

  else if(a.i < c.i && a.j >= c.j) // if given point is in top_right
  {
    // printf("top_right\n");
    // printf("POINT: (%d, %d)\n", a.i, a.j);
    // printf("CENTER: (%d, %d)\n", c.i, c.j);

      board[br.i][br.j] = counter;
      board[bl.i][bl.j] = counter;
      board[tl.i][tl.j] = counter;

    //print_board(board);

    tr.i = a.i;
    tr.j = a.j;


  }

  else if(a.i < c.i && a.j < c.j) //if given point is in top_left
  {
    // printf("top_left\n");
    // printf("POINT: (%d, %d)\n", a.i, a.j);
    // printf("CENTER: (%d, %d)\n", c.i, c.j);

      board[br.i][br.j] = counter;
      board[bl.i][bl.j] = counter;
      board[tr.i][tr.j] = counter;

  //  print_board(board);

    tl.i = a.i;
    tl.j = a.j;


  }

    if (n == 2) return 0;

     get_tile(board, n/2, tr, i, j+(n/2));
     get_tile(board, n/2, tl, i, j);
     get_tile(board, n/2, bl, i+(n/2), j);
     get_tile(board, n/2, br, i+(n/2), j+(n/2));


}

int get_tile(int board[BOARDSIZE][BOARDSIZE], int n, Point a, int i, int j)
{
  counter++;
  //if (counter > 6) exit(0);

  if (n == 2) //base case
  {
    place_tile(board, n, a,  i,  j);
    return 0;
  }
  else
  {
    place_tile(board, n, a,  i,  j); //places L shaped tile in section not containing a filled in point
  }

}



int main()
{
  srand(time(NULL));
  int board [BOARDSIZE][BOARDSIZE] = {{}};
  Point a, b; //inital point and inital difference.
  a.i = rand() % BOARDSIZE;
  a.j = rand() % BOARDSIZE;
  a.k = 0;
  a.l = 0;
  int n = BOARDSIZE;
  board[a.i][a.j] = 1;

  //print_board(board);

  clock_t begin = clock();

  get_tile(board, n, a, 0, 0);

  clock_t end = clock();
  float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

  //print_board(board);
  printf("Time of program: %f\n", time_spent);

}
