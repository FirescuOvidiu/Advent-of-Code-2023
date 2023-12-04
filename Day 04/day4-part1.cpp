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

  long long max = 0, min = 9223372036854775807;
  int       id;

  set<int> se;

  while (getline(in, l))
  {
    vector<int>  v, v1;
    stringstream ss{ l };
    ss >> s >> id >> c;
    while (ss >> s)
    {
      if (s[0] == '|')
        break;
      v.push_back(stoi(s));
    }
    while (ss >> s)
    {
      v1.push_back(stoi(s));
    }

    long long total = 1;
    bool      found = 0;
    for (const auto & f : v1)
    {
      if (find(v.begin(), v.end(), f) != v.end())
      {
        total *= 2;
        found = 1;
      }
    }
    if (found)
    {
      if (total != 1)
        total = total / 2;
      sum += total;
    }
  }
  cout << sum;

  cout << endl;
}
