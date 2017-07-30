#include "common.hh"

void read_in(TString inputname, std::vector<TString>& numbers);
TString AddNumber(TString input, TString number);
void CheckCarry(int& tmp, const int i, bool& carry);

const int N = 10;

int main() 
{
  TString inputname = "input.txt";
  std::vector<TString> numbers;
  read_in(inputname,numbers);

  TString sum = "0";
  for (auto&& number : numbers)
  {
    sum = AddNumber(sum,number);
  }

  std::cout << sum.Data() << std::endl;
  std::cout << TString(sum(sum.Length()-N,N)).Data() << std::endl;
}

TString AddNumber(TString input, TString number)
{
  const int iL = input.Length();
  const int nL = number.Length();
  const int diff = iL-nL;
  
  // L = length, D = digit

  TString output = "";
  if (diff >= 0)
  {
    bool carry = false;
    for (int i = iL-1; i > -1; i--)
    {
      int tmp = 0;
      const int iD = TString(input[i]).Atoi();
      if (i >= diff)
      { 
	const int nD = TString(number[i-diff]).Atoi();
	tmp = iD + nD;
	CheckCarry(tmp,i,carry);
	output.Prepend(Form("%i",tmp));
      } 
      else
      {
	tmp = iD;
	CheckCarry(tmp,i,carry);
	output.Prepend(Form("%i",tmp));
      }
    }
  }
  else // hack for now
  {
    output = number;
  }
  return output;
}

void CheckCarry(int& tmp, const int i, bool& carry)
{
  if (carry) tmp += 1;
  if (tmp >= 10 && i != 0) {carry = true; tmp -= 10;}
  else carry = false;
}

void read_in(TString inputname, std::vector<TString>& numbers)
{
  std::ifstream inputfile(inputname.Data(),std::ios_base::in);

  TString number;
  while (inputfile >> number)
  {
    numbers.push_back(number);
  }
}
