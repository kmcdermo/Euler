#include "common.hh"

void generateMap(std::map<TString,long> & letterMap)
{
  std::vector<TString> letters = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  for (Int_t i = 0; i < letters.size(); i++)
  {
    letterMap[letters[i]] = i+1;
  }
}

long getScore(const std::map<TString,long> & letterMap, const TString name)
{
  long score = 0;
  for (UInt_t i = 0; i < name.Length(); i++)
  {
    score += letterMap.at(name[i]);
  }
  return score;
}

void readin_names(std::ifstream & input, const std::map<TString,long> & letterMap, std::map<TString,long> & names)
{
  TString name = "";
  while (input >> name)
  {
    const long score = getScore(letterMap, name);
    names[name] = score;
  }
}

long sumNameScores(std::map<TString,long> & names)
{
  long sum = 0;
  long pos = 1;
  for (auto&& name : names)
  {
    sum += (name.second*pos);
    pos++;
  }
  return sum;
}

int main() 
{
  std::map<TString,long> letterMap;
  generateMap(letterMap);

  std::map<TString,long> names;
  std::ifstream input("names.txt");
  readin_names(input,letterMap,names);
  
  const long sum = sumNameScores(names);
  std::cout << sum << std::endl;
}
