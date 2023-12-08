#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int main()
{
  fstream in("input.in", fstream::in);

  string    s, l;
  long long sum = 0, num = 0;
  char      c{}, c1{}, c2{};

  vector<vector<char>> m(10000, vector<char>(10000, '0'));

  long long         max = 0, min = numeric_limits<long long>::max();
  vector<long long> v;
  string            p;
  getline(in, p);
  string                                      auxl;
  unordered_map<string, pair<string, string>> t;
  getline(in, l);
  while (getline(in, l))
  {
    string       a, b;
    stringstream ss{ l };
    ss >> s >> auxl >> c >> a >> b;
    a.erase(a.end() - 1);
    b.erase(b.end() - 1);
    t[s] = { a, b };
  }

  int            i = 0;
  vector<pair<string, int>> curr;
  for (const auto& sss : t)
  {
      if (sss.first[2] == 'A')
          curr.push_back({sss.first, 0});
  }
  int steps = 0;

  vector<int>cmmmc(6,0);


  while (i < p.size())
  {
    if (p[i] == 'L')
    {
        for (auto& cccc : curr)
        {
            cccc = { t[cccc.first].first,steps };
        }
    }
    else
    {
      for (auto & cccc : curr)
      {
          cccc = { t[cccc.first].second,steps };
      }
    }
    steps++;
    for (size_t i = 0; i < curr.size(); i++)
    {
        if (curr[i].first[2] == 'Z')
        {
            if (cmmmc[i] == 0)
                cmmmc[i] = steps;
        }

    }

    int good = 0;
    for (const auto& cc : cmmmc)
    {
        if (cc == 0)
            good = 1;
    }
    if (!good)
        break;
    i++;
    if (i == p.size())
      i = 0;
  }

  // calculeaza online cmmmc ul elementelor din vectorul cmmmc

  cout << steps;
  cout << endl;
}
