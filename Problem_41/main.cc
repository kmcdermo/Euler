#include "common.hh"

static const long N = 1000000000;

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

bool isPandigital(const long prime)
{
  bool isPandigital = true;

  const TString tprime = Form("%li",prime);
  const int length = tprime.Length();

  std::map<int,bool> digits;
  for (int i = 0; i < length; i++) 
  {
    const int tmp = TString(tprime[i]).Atoi();
    if   (tmp == 0 || tmp > length) {isPandigital = false; break;}
    if   (!digits[tmp]) digits[tmp] = true;
    else {isPandigital = false; break;}
  }
  return isPandigital;
}

int main() 
{
  std::vector<bool> primes(N, true);
  makeSieve(primes);

  long pandigital = 0;
  for (long i = 0; i < N; i++)
  {
    if (primes[i]) 
    {
      if (isPandigital(i)) {pandigital = i;}
    }
  }
  std::cout << pandigital << std::endl;
}
