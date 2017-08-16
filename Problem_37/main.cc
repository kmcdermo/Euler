#include "common.hh"

static const int N = 1000000;

void makeSieve(std::vector<bool> & primes)
{
  primes[0] = primes[1] = false;
  const int sqrtN = std::sqrt(N);
  for (int p = 2; p <= sqrtN; p++)
  {
    if (primes[p])
    {
      for (int i = p*p; i <= N; i += p)
      {
	primes[i] = false;
      }
    }
  }
}

bool isTruncatable(const int prime, const std::vector<bool>& primes)
{
  bool isTruncatable = true;

  const TString tprime = Form("%i",prime);
  const int length = tprime.Length();

  for (int i = 1; i < length; i++) 
  {
    const int tmp = TString(tprime(i,length-i)).Atoi();
    if (!primes[tmp]) {isTruncatable = false; break;}
  }

  if (isTruncatable)
  {
    for (int i = 0; i < length-1; i++) 
    {
      const int tmp = TString(tprime(0,length-i-1)).Atoi();
      if (!primes[tmp]) {isTruncatable = false; break;}
    }
  }

  return isTruncatable;
}

int main() 
{
  std::vector<bool> primes(N, true);
  makeSieve(primes);

  std::vector<int> truncatables;
  for (int i = 8; i <= N; i++)
  {
    if (primes[i]) 
    {
      if (isTruncatable(i,primes)) truncatables.push_back(i);
    }
  }

  int sum = 0;
  for (auto prime : truncatables) {sum += prime;}
  std::cout << sum << std::endl;
}
