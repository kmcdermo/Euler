#include "common.hh"

int main() 
{
  const int N = 4e6;
  int i = 1;
  int j = 2;

  int sum = 0;

  do
  { 
    const int tmp = j; 
    j += i;
    i = tmp;
    
    if (j % 2 == 0) sum+=j;
  } while (j < N);

  std::cout << sum+2 << std::endl;
}
