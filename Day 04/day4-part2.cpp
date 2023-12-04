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

  vector<vector<int>> v2, v3;

  int lines = 0;
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
    v2.push_back(v);
    v3.push_back(v1);
    lines++;
  }

  stack<int>  p;
  vector<int> final(1000, 0);
  long long   total = 1;
  bool        found = 0;
  int         i     = 1;
  while (lines > 0)
  {
    p.push(i);
    i++;
    lines--;
  }

  while (!p.empty())
  {
    int d = p.top();
    p.pop();

    d--;
    final[d]++;

    int count = 0;
    for (const auto & f : v3[d])
      if (find(v2[d].begin(), v2[d].end(), f) != v2[d].end())
      {
        count++;
      }

    d++;
    for (int j = d + 1; j <= d + count; j++)
    {
      p.push(j);
    }
  }

  long long ff = 0;
  for (const auto & eee : final)
    ff += eee;
  cout << ff;
  cout << endl;
}
