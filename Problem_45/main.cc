#include "common.hh"

int main() 
{
  long long it = 285+1;
  long long tph = 0;
  bool isTPH = false;
  while (!isTPH)
  {
    const long long tn = it*(it+1)/2;

    const long long ip = (1+std::sqrt(1+24*tn))/6;
    const long long pn = ip*(3*ip-1)/2;

    if (tn == pn)
    {
      const long long ih = (1+std::sqrt(1+8*tn))/4;
      const long long hn = ih*(2*ih-1);

      if (tn == hn)
      {
	std::cout << it << " " << tn << std::endl;
	std::cout << ip << " " << pn << std::endl;
	std::cout << ih << " " << hn << std::endl;

	isTPH = true;
      }
    }
    it++;
  }
}
