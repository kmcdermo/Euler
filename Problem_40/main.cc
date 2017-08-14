#include "common.hh"

static const int N = 1000000;

int main() 
{
  TString irrational = "";
  int i = 1;
  while (irrational.Length() <= N)
  {
    irrational.Append(Form("%i",i));
    i++;
  }
  
  int product = 1;
  for (int i = 0; i <= 6; i++)
  { 
    int pos = std::pow(10,i)-1;
    product *= TString(irrational(pos)).Atoi();
  }
  std::cout << product << std::endl;
}
