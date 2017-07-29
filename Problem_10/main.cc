#include "common.hh"

int main() 
{
  const long N = 50;
  std::vector<long> primes;

  for (long i = 2; i < N; i++) 
  {
    bool isPrime = true;
    for (auto prime : primes) 
    {
      if (i%prime==0) {isPrime = false; break;}
    }
    
    if (isPrime) primes.push_back(i);
  }
  
  long sum = 0;
  for (auto prime : primes) sum += prime;

  std::cout << sum << std::endl;
}
