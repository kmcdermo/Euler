#include "common.hh"

static const int N = 1000;

TString Multiply(const TString & input, const int n)
{
  TString output = "";
  int carry  = 0;
  for (int i = input.Length()-1; i >=0; i--)
  {
    int tmp = TString(input[i]).Atoi();
    tmp *= n; 
    if (carry != 0) tmp += carry;
    if (i != 0)
    {
      carry = 0;
      while (tmp >= 10)
      {
	tmp -= 10;
	carry++;
      }
    }
    output.Prepend(Form("%i",tmp));
  }
  return output;
}

TString getSelfPower(const int n)
{
  TString selfpower = "1";
  for (int i = 1; i <=n; i++)
  {
    selfpower = Multiply(selfpower,n);
  }
  return selfpower;
}

void CheckCarry(int& tmp, const int i, bool& carry)
{
  if (carry) tmp += 1;
  if (tmp >= 10 && i != 0) {carry = true; tmp -= 10;}
  else carry = false;
}

TString SumSelfPowers(const TString & insum, const TString & selfpower)
{
  TString outsum = "";
  bool carry = false;
  const int diff = selfpower.Length()-insum.Length();
  for (int i = selfpower.Length()-1; i >= 0; i--)
  {
    int tmp = 0;
    const int sp = TString(selfpower[i]).Atoi();
    if (i >= diff)
    { 
      const int is = TString(insum[i-diff]).Atoi();
      tmp = is + sp;
      CheckCarry(tmp,i,carry);
      outsum.Prepend(Form("%i",tmp));
    } 
    else
    {
      tmp = sp;
      CheckCarry(tmp,i,carry);
      outsum.Prepend(Form("%i",tmp));
    }
  }
  return outsum;
}

int main() 
{
  TString sum = "0";
  for (int i = 1; i <= N; i++)
  {
    std::cout << i << std::endl; 
    const TString selfpower = getSelfPower(i);
    sum = SumSelfPowers(sum,selfpower);
  }
  
  std::cout << sum.Data() << std::endl;
}
