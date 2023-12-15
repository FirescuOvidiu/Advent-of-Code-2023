#include "../AOCHeaders/stdafx.h"

using ll  = long long;
using VL  = vector<long long>;
using VLL = vector<vector<long long>>;
using VS  = vector<string>;

// Template
#define REP(n)     for (int _ = 0; _ < (n); _++)
#define FOR(i, a)  for (int i = 0; i < (a); i++)
#define FORd(i, a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()

int main()
{
  fstream in("input.in", fstream::in);

  string    s, l;
  char      c{}, c1{}, c2{};

  getline(in, l);
  stringstream ss{ l };
  long long    totalSum = 0;

  while (ss >> c)
  {
    if (c == ',')
    {
      long long curr = 0;
      for (int i = 0; i < s.size(); i++)
      {
        curr += (long long)s[i];
        curr *= 17;
        curr %= 256;
      }
      s.clear();
      totalSum += curr;
    }
    else
      s.push_back(c);
  }

  long long curr = 0;
  for (int i = 0; i < s.size(); i++)
  {
    curr += (long long)s[i];
    curr *= 17;
    curr %= 256;
  }
  totalSum += curr;
  cout << totalSum;

  cout << endl;
}
