#include "common.hh"

TString doubleNum(TString input);

int main() 
{
  const int N = 1000;
  TString input = "1";
  for (int i = 0; i < N; i++)
  {
    input = doubleNum(input);    
  }

  int sum = 0;
  for (int i = 0; i < input.Length(); i++)
  {
    sum += TString(input[i]).Atoi();
  }

  std::cout << sum << std::endl;
}

TString doubleNum(TString input)
{
  TString output = "";
  bool carry = false;
  for (int j = input.Length()-1; j > -1; j--)
  {
    int tmp = TString(input[j]).Atoi();
    tmp *= 2;
    if (carry) tmp += 1;
    if (tmp >= 10 && j != 0) {carry = true; tmp -= 10;}
    else carry = false;
    output.Prepend(Form("%i",tmp));
  }
  return output;
}
