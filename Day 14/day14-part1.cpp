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

vector<string> getMatrix(fstream & in, long long & nx, long long & ny)
{
  vector<string> m;
  string         l;

  while (getline(in, l))
  {
    m.push_back(l);
  }
  nx = m.size(), ny = m[0].size();

  return m;
}

int main()
{
  fstream in("input.in", fstream::in);

  long long nx = 0, ny = 0;
  auto      m = getMatrix(in, nx, ny);

  for (int i = nx - 1; i >= 0; i--)
  {
    for (int j = 0; j < ny; j++)
    {
      if (m[i][j] == 'O')
      {
        int saveX = -1;
        for (int k = i; k >= 0; k--)
        {
          if (m[k][j] == '#')
            break;
          if (m[k][j] == '.')
            saveX = k;
        }

        if (saveX != -1)
        {
          m[saveX][j] = m[i][j];
          m[i][j]     = '.';
        }
      }
    }
  }

  ll totalSum = 0;
  FOR(i, nx)
  {
    FOR(j, ny)
    {
      if (m[i][j] == 'O')
        totalSum += nx - i;
    }
  }

  cout << totalSum;
}
