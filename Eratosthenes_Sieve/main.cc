#include "common.hh"

static const long N = 2e6;

void method1(std::vector<bool>& primes)
{
  const long sqrtN = std::sqrt(N);
  for (long p = 2; p <= sqrtN; p++)
  {
    if (primes[p])
    {
      for (long i = p*p; i <= N; i += p)
      {
	primes[i] = false;
      }
    }
  }
}

void method2(std::vector<bool>& primes)
{
  for (long p = 2; p*p <= N; p++) 
  {
    if (primes[p]) 
    {
      for (long i = 2*p; i <= N; i += p) 
      {
	primes[i] = false;
      }
    }
  }
}

int main() 
{
  std::vector<bool> primes(N);
  for (auto&& prime : primes) prime = true;
  
  method1(primes);
  //method2(primes);

  long sum = 0;
  for (long p = 2; p <= N; p++)
  {
    if (primes[p]) sum += p;
  }

  std::cout << sum << std::endl;
}
