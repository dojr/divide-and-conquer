#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COINS 12000

int counter = 0; // count number of balances

void print_arr(int arr[], int n, int k)
{
  for (int i = 0; i < n; i++)
      printf("stack %d: %d\n", k, arr[i]);
    printf("\n");
}

void initArr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = 0;
}


int weigh(int arr[], int n)
{
  counter += 1;
  int stack1[n], stack2[n], stack3[n];
  int sum1 = 0, sum2 = 0, k = 0;
  initArr(stack1, n);
  initArr(stack2, n);

  //for loop gets the first 2/3rds of array for comparison
  for (int i = 0; i < n*2; i++)
  {
    if (i >= n){
      sum2 += arr[i];
      stack2[i-n] = arr[i];
    }
    else{
      sum1 += arr[i];
      stack1[i] = arr[i];
    }
  }

  //gets last third of arr for use when the stacks above are equal.
  for (int i = n*2; i < n*3; i++)
  {
    stack3[k++] = arr[i];
  }

  print_arr(stack1, n, 1);
  print_arr(stack2, n, 2);
  print_arr(stack3, n, 3);

  if(sum1 == sum2){
    if(n == 1){
      return 0;
    }
    weigh(stack3, n/3);         //weights are equal so we weight 3rd stack
  }
  else if(sum1 > sum2){
    if(n == 1){
      return 0;
    }
    weigh(stack1, n/3);         //stack1 is heavier so weigh that stack again
  }
  else{
    if(n == 1){
      return 0;
    }
    weigh(stack2, n/3);         //stack 2 is heavier
  }

}

int main()
{
  srand(time(NULL));
  int stack[COINS];
  initArr(stack, COINS);

  int i = rand() % COINS-1;
  stack[i] = 1;

  int n = COINS/3;



  clock_t begin = clock();

  weigh(stack, n);
  clock_t end = clock();
  float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

  printf("Time of program: %f\n", time_spent);
  printf("Counter: %d\n", counter);
  printf("location of coin i: %d\n", i);

}
