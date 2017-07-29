#include "common.hh"

int main() 
{
  const int N = 10001;
  std::vector<long> primes;

  long i = 2;
  while (primes.size() != N)
  {
    bool isPrime = true;
    for (auto prime : primes) 
    {
      if (i%prime==0) {isPrime = false; break;}
    }
    
    if (isPrime) primes.push_back(i);
    i++;
  }

  for (auto prime : primes) std::cout << prime << std::endl;
}
