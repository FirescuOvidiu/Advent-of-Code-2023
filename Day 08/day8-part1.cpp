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

  int    i     = 0;
  string curr  = "AAA";
  int    steps = 0;

  while (i < p.size())
  {
    if (p[i] == 'L')
    {
      curr = t[curr].first;
    }
    else
    {
      curr = t[curr].second;
    }
    steps++;
    if (curr == "ZZZ")
      break;
    i++;
    if (i == p.size())
      i = 0;
  }
  cout << steps;
  cout << endl;
}
