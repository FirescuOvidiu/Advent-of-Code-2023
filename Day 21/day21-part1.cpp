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

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

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

  string    s, l;
  long long sum = 0, num = 0, nx = 0, ny = 0;
  ll        totalSum = 0;
  char      c{}, c1{}, c2{};

  vector<int> dx{ 0, +1, 0, -1 };
  vector<int> dy{ +1, 0, -1, 0 };

  long long max = 0, min = numeric_limits<long long>::max();

  // vector<string>       m(10000, string(10000, '.'));

  auto m = getMatrix(in, nx, ny);

  vector<vector<bool>> m1(nx, vector<bool>(ny, false));

  int st, end;
  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      if (m[i][j] == 'S')
      {
        st = i, end = j;
      }
    }
  }

  queue<pair<int, int>> q2;
  q2.push({ st, end });
  m1[st][end] = true;
  // while(in>>s)

  for (size_t ji = 0; ji < 64; ji++)
  {
    queue<pair<int, int>> q = q2;
    set<pair<int, int>>   alread;
    while (!q2.empty())
      q2.pop();
    alread.clear();
    while (!q.empty())
    {
      auto curr = q.front();
      q.pop();

      for (size_t i = 0; i < 4; i++)
      {
        int newX = curr.first + dx[i];
        int newY = curr.second + dy[i];
        if (checkInMap(newX, newY, nx, ny) && m[newX][newY] != '#')
        {
          if (alread.find({ newX, newY }) == alread.end())
          {
            q2.push({ newX, newY });
            alread.insert({ newX, newY });
            m1[newX][newY] = true;
          }
        }
      }
    }
    cout << q2.size() << endl;
  }
  /*
  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
    }
  }
  */

  cout << endl;
}
