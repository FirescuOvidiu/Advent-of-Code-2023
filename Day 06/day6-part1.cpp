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
  vector<long long> st, fin;

  getline(in, l);
  {
    stringstream ss{ l };
    ss >> s;
    while (ss >> num)
      st.push_back(num);
  }

  getline(in, l);
  {
    stringstream ss{ l };
    ss >> s;
    while (ss >> num)
      fin.push_back(num);
  }

  long long res = 1;

  for (size_t i = 0; i < st.size(); i++)
  {
    long long count = 0;

    long long j = 1;

    while (j < fin[i])
    {
      long long total = j * (st[i] - j);
      if (total > fin[i])
        count++;
      j++;
    }
    res *= count;
  }
  cout << res;
  cout << endl;
}
