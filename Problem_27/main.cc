#include "common.hh"

static const long N = 100000;
static const long a = 1000; 
static const long b = 1000; 

void makeSieve(std::vector<bool> & primes)
{
  primes[0] = primes[1] = false;
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

int main() 
{
  std::vector<bool> primes(N, true);
  makeSieve(primes);

  long product = 0;
  long counter = 0;
  for (long i = -a+1; i < a; i++)
  { 
    for (long j = -b; j <= b; j++)
    {
      long n = 0;
      bool isPrime = true;
      while (isPrime)
      {
	const long calc = std::abs(n*n+n*i+j);
	isPrime = primes[calc];
	if (isPrime) n++;
      }
      n--;
      if (n > counter) {counter = n; product = i*j;}
    }
  }
  std::cout << counter << " : " << product << std::endl;
}
