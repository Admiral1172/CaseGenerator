#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void genCases(int num) //generate test cases if input is 1 or 2
{
  FILE *fp;
  long long maxPages = pow(10, 14);
  long long maxBooks = pow(10, 10);
  long long lowPage = pow(10, 11);
  //pow() makes it easy to handle exponential numbers
  
  fp = fopen("sample.in", "w");

  srand(time(NULL));

  int numCases = rand() % 25; // random seed generator.

  printf("Enter 1 for 100000 Books or 2 for numbers larger than 10^9.");

  if (num == 1) //testing out the 100000 books case
  {
    fprintf(fp, "%d\n", numCases);
    for(int i=0; i<numCases; i++)
    {
      fprintf(fp, "%d %d\n", 100000, rand() % 10000);
      for(int i=0; i<100000; i++)
      {
        fprintf(fp, "%d ", rand() % 10000);
      }
    }
    
    fclose(fp);
  }
  if (num == 2) //this one handles numbers greater than 10^10 for the pages, also it has to be less than 10^13 because 10^9 is too small and would need 100000 books to get some variety.
  {
    fprintf(fp, "%d\n", 1);
    for(int i=0; i<1; i++)
    {
      fprintf(fp, "%d %lld\n", 100000, ((rand() * (long long)(RAND_MAX) + rand()) % (maxPages-lowPage+1)) + lowPage); //best way to go around rand limits and limit value to within range. Should allow for numbers greater than 32768
      for(int i=0; i<100000; i++)
      {
        fprintf(fp, "%lld ", (rand() * (long long)(RAND_MAX) + rand()) % maxBooks); 
      }
    }
    
    fclose(fp); //close file stream
  }

}

int main(void)
{
  int pCases;

  scanf("%d", &pCases);
  genCases(pCases);

  return 0;
}