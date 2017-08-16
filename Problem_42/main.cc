#include "common.hh"

static const int N = 200;

typedef std::map<TString,int> TStrIMap;

void generateMap(TStrIMap & letterMap)
{
  std::vector<TString> letters = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  for (int i = 0; i < letters.size(); i++)
  {
    letterMap[letters[i]] = i+1;
  }
}

int getWordValue(const TStrIMap & letterMap, const TString & word)
{
  int wordval = 0;
  for (int i = 0; i < word.Length(); i++)
  {
    wordval += letterMap.at(word(i,1));
  }
  return wordval;
}

void readin_words(const TString & inname, const TStrIMap & letterMap, TStrIMap & wordMap)
{
  std::ifstream input(inname.Data(),std::ios::in);

  TString word;
  while (input >> word)
  {
    const int wordval = getWordValue(letterMap,word);
    wordMap[word] = wordval;
  }

  input.close();
}


int main() 
{
  TStrIMap letterMap;
  generateMap(letterMap);

  TStrIMap wordMap;
  readin_words("words.txt",letterMap,wordMap);

  std::vector<bool> isTriNum(N,false);
  int n = 0; 
  int trinum = 0;
  while (trinum < N)
  {
    n++;
    trinum = (0.5*n)*(n+1);
    isTriNum[trinum] = true;
  }
    
  int count = 0;
  for (auto&& pair : wordMap)
  {
    if (isTriNum[pair.second]) count++;
  }

  std::cout << count << std::endl;
}
