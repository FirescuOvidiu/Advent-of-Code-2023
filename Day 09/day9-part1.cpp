#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int main()
{
  fstream in("input.in", fstream::in);

  vector<int> dx{ 0, 1, 0, -1 };
  vector<int> dy{ -1, 0, 1, 0 };

  string    s, l;
  long long sum = 0, num = 0;
  char      c{};

  vector<vector<char>> m(10000, vector<char>(10000, '0'));

  long long max = 0, min = numeric_limits<long long>::max();
  long long total = 0;
  while (getline(in, l))
  {
    long long         curr = 0;
    vector<long long> v;
    stringstream      ss{ l };

    while (ss >> sum)
    {
      v.push_back(sum);
      v.push_back(0);
    }
    v.erase(v.end() - 1);

    vector<vector<long long>> calc(50000, vector<long long>(v.size(), 0));

    int i = 0;
    for (const auto & c : v)
    {
      calc[0][i] = c;
      i++;
    }

    for (int j = 1; j < calc.size(); j++)
    {
      bool test = 1;
      for (int k = j; k < calc[j].size() - j; k += 2)
      {
        calc[j][k] = calc[j - 1][k + 1] - calc[j - 1][k - 1];
        if (calc[j][k] != 0)
          test = 0;
      }
      if (test)
        break;
    }

    int z  = v.size() - 1;
    int lp = 0;
    while (z > 0)
    {
      curr += calc[lp][z];
      z--;
      lp++;
    }
    total += curr;
    // cout << curr << "\n";
  }
  cout << total;
  cout << endl;
}
