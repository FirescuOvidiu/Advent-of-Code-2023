#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int main()
{
  fstream in("input.in", fstream::in);

  string    s, l;
  long long sum = 0, num = 0, nx = 0, ny = 0;
  char      c{};

  vector<vector<char>> m3(10000, vector<char>(10000, '0'));

  long long         max = 0, min = numeric_limits<long long>::max();
  vector<long long> v;

  while (getline(in, l))
  {
    stringstream ss{ l };

    for (ny = 0; ny < l.size(); ny++)
    {
      m3[nx][ny] = l[ny];
    }
    nx++;
  }

  vector<vector<char>> m(nx, vector<char>(ny, '0'));

  for (size_t i = 0; i < nx; i++)
  {
    for (size_t j = 0; j < ny; j++)
      m[i][j] = m3[i][j];
  }
  set<int> rows, columns;

  for (size_t i = 0; i < nx; i++)
  {
    bool check = true;
    for (size_t j = 0; j < ny; j++)
    {
      if (m[i][j] == '#')
      {
        check = false;
      }
    }

    if (check)
    {
      rows.insert(i);
    }
  }

  for (size_t i = 0; i < ny; i++)
  {
    bool check = true;
    for (size_t j = 0; j < nx; j++)
    {
      if (m[j][i] == '#')
      {
        check = false;
      }
    }

    if (check)
      columns.insert(i);
  }

  vector<pair<int, int>> g;

  for (size_t i = 0; i < nx; i++)
  {
    for (size_t j = 0; j < ny; j++)
    {
      if (m[i][j] == '#')
        g.push_back({ i, j });
    }
  }

  long long totalsum = 0;
  int       abc      = 1000000;

  for (size_t i = 0; i < g.size(); i++)
  {
    for (size_t j = i + 1; j < g.size(); j++)
    {
      vector<vector<bool>>  visit(nx, vector<bool>(ny, false));
      queue<pair<int, int>> x1;
      queue<long long>      sums;

      vector<int> dx{ 0, 1, 0, -1, -1, -1, +1, +1 };
      vector<int> dy{ -1, 0, 1, 0, -1, +1, -1, +1 };

      auto first  = g[i];
      auto second = g[j];

      x1.push({ first.first, first.second });
      sums.push({ 0 });

      visit[first.first][first.second] = true;
      long long currSum                = 0;

      while (!x1.empty())
      {
        auto currX = x1.front();
        auto ssss  = sums.front();
        sums.pop();
        x1.pop();

        if ((currX.first == second.first) && (currX.second == second.second))
        {
          totalsum += ssss;
          break;
        }

        for (int iz = 0; iz < 4; iz++)
        {
          int xa = currX.first + dx[iz];
          int xb = currX.second + dy[iz];

          if (checkInMap(xa, xb, nx, ny) && visit[xa][xb] == false)
          {
            x1.push({ xa, xb });
            long long curSSSS = ssss;
            if (rows.find(xa) != rows.end())
              curSSSS += abc - 1;
            if (columns.find(xb) != columns.end())
              curSSSS += abc - 1;
            sums.push({ curSSSS + 1 });
            visit[xa][xb] = true;
          }
        }
      }
    }
  }

  cout << endl << totalsum;
}
