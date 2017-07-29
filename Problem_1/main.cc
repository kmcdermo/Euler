#include "common.hh"

int main() 
{
  const int N = 1000;
  std::vector<int> multiples = {3,5};
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    for (auto j : multiples)
    {
      if (i % j == 0) {sum += i; break;}
    }
  }
  std::cout << sum << std::endl;
}
