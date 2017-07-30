#include "common.hh"

static const int N = 1000;

TString AddNumber(TString fibi, TString fibj);
void CheckCarry(int& tmp, const int i, bool& carry);

int main() 
{
  TString fibi = "1";
  TString fibj = "1";

  int index = 2;
  
  while (fibj.Length() < N)
  {
    TString tmp = fibj;

    fibj = AddNumber(fibi,fibj);

    fibi = tmp;
    index++;
  }
  
  std::cout << "Fibonnaci index: " <<  index << std::endl;
  std::cout << "Fibonnaci number: " <<  fibj.Data() << std::endl;
}

TString AddNumber(TString fibi, TString fibj)
{
  const int iL = fibi.Length();
  const int jL = fibj.Length();
  const int diff = jL-iL;
  
  // L = length, D = digit

  TString output = "";
  bool carry = false;
  for (int i = jL-1; i > -1; i--)
  {
    int tmp = 0;
    const int jD = TString(fibj[i]).Atoi();
    if (i >= diff)
    { 
      const int iD = TString(fibi[i-diff]).Atoi();
      tmp = jD + iD;
      CheckCarry(tmp,i,carry);
      output.Prepend(Form("%i",tmp));
    } 
    else
    {
      tmp = jD;
      CheckCarry(tmp,i,carry);
      output.Prepend(Form("%i",tmp));
    }
  }

  return output;
}

void CheckCarry(int& tmp, const int i, bool& carry)
{
  if (carry) tmp += 1;
  if (tmp >= 10 && i != 0) {carry = true; tmp -= 10;}
  else carry = false;
}
