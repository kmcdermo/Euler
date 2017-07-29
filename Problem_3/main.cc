#include "common.hh"

void loopdiv(const long N, std::vector<long>& factors);

int main() 
{
  const long N = 600851475143;
  std::vector<long> factors;

  loopdiv(N,factors);

  long product = 1;
  std::cout << "Factors: " << std::endl;
  for (auto factor : factors)
  {  
    std::cout << "  " << factor << std::endl;
    product *= factor;
  }

  std::cout << std::endl << "Product: " << product << std::endl;
}

void loopdiv(const long N, std::vector<long> & factors)
{
  long factor = 0;
  for (long i = 2; i < N; i++)
  {
    if (N%i==0) {factor = i; break;}
  }

  if (factor != 0)
  {
    const long dividend = N/factor;
    factors.push_back(factor);
    if (dividend != 1) loopdiv(dividend,factors);
  }
  else factors.push_back(N);
}



