#include "common.hh"

static const int e = 5;
static const int N = std::pow(9,e)*e+1;

void generatePowers(std::map<int,int> & pows)
{
  for (int i = 0; i < 10; i++)
  {
    pows[i] = std::pow(i,e);
  }
}

bool testNumber(std::map<int,int> & pows, const int i)
{
  TString num = Form("%i",i);
  int sum = 0;
  for (Int_t j = 0; j < num.Length(); j++)
  {
    sum += pows[TString(num[j]).Atoi()];
  }

  return (sum == i);
}


int main() 
{
  std::map<int,int> pows;
  generatePowers(pows);

  int sum = 0;
  for (int i = 2; i <= N; i++)
  {
    bool isFifthSum = testNumber(pows,i);
    if (isFifthSum) sum += i;
  }

  std::cout << "Total: " << sum << std::endl;
}
