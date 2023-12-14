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

  auto                      m = getMatrix(in, nx, ny);
  vector<long long>         vTotalSums;
  vector<vector<long long>> iterators;

  for (ll p = 0; p < 1000000000; p++)
  {
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

    for (int i = 0; i < nx; i++)
    {
      for (int j = ny - 1; j >= 0; j--)
      {
        if (m[i][j] == 'O')
        {
          int saveY = -1;
          for (int k = j; k >= 0; k--)
          {
            if (m[i][k] == '#')
              break;
            if (m[i][k] == '.')
              saveY = k;
          }

          if (saveY != -1)
          {
            m[i][saveY] = m[i][j];
            m[i][j]     = '.';
          }
        }
      }
    }

    for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        if (m[i][j] == 'O')
        {
          int saveX = -1;
          for (int k = i; k < nx; k++)
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

    for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        if (m[i][j] == 'O')
        {
          int saveY = -1;
          for (int k = j; k < ny; k++)
          {
            if (m[i][k] == '#')
              break;
            if (m[i][k] == '.')
              saveY = k;
          }

          if (saveY != -1)
          {
            m[i][saveY] = m[i][j];
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
        {
          totalSum += nx - i;
        }
      }
    }

    if (ranges::find(vTotalSums, totalSum) == vTotalSums.end())
    {
      vector<long long> aux{ p };
      vTotalSums.push_back(totalSum);
      iterators.push_back(aux);
    }
    else
    {
      for (int o = 0; o < vTotalSums.size(); o++)
        if (vTotalSums[o] == totalSum)
          iterators[o].push_back(p);
      if (p == 5000)
        break;
    }
  }

  for (long long i = iterators.size() - 1; i >= 0; i--)
  {
    ll dif  = iterators[i][1] - iterators[i][0];
    ll dif2 = iterators[i][2] - iterators[i][1];
    if (dif == dif2)
    {
      if ((1000000000 - iterators[i][0] - 1) % dif == 0)
      {
        cout << vTotalSums[i];
        i = -1;
        break;
      }
    }
  }

  cout << endl;
}
