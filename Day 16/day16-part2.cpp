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

  long long nx = 0, ny = 0;

  auto m = getMatrix(in, nx, ny);

  vector<tuple<int, int, char>> totalTiles;
  for (size_t i = 0; i < ny; i++)
  {
    totalTiles.push_back({ 0, i, 'S' });
    totalTiles.push_back({ nx - 1, i, 'N' });
  }
  for (size_t i = 0; i < nx; i++)
  {
    totalTiles.push_back({ i, 0, 'R' });
    totalTiles.push_back({ i, ny - 1, 'L' });
  }

  int maxCount = 0;
  for (const auto & tile : totalTiles)

  {
    vector<tuple<int, int, char>> points;

    auto & [x0, y0, dir0] = tile;
    points.push_back({ x0, y0, dir0 });

    vector<vector<bool>> v(nx, vector<bool>(ny, false));
    set<tuple<int, int, char>> visited;

    while (!points.empty())
    {
      auto aux = points;
      points.clear();
      while (!aux.empty())
      {
        auto [x, y, dir] = aux[aux.size() - 1];
        aux.pop_back();

        if (visited.find({ x, y, dir }) == visited.end())
          visited.insert({ x, y, dir });
        else
          continue;

        v[x][y] = true;

        if (m[x][y] == '.')
        {
          if (dir == 'R')
            y++;
          else if (dir == 'L')
            y--;
          else if (dir == 'N')
            x--;
          else if (dir == 'S')
            x++;
          if (checkInMap(x, y, nx, ny))
            points.push_back({ x, y, dir });

          continue;
        }

        if (m[x][y] == '-')
        {
          if (dir == 'R')
          {
            if (checkInMap(x, y + 1, nx, ny))
              points.push_back({ x, y + 1, dir });
          }
          else if (dir == 'L')
          {
            if (checkInMap(x, y - 1, nx, ny))
              points.push_back({ x, y - 1, dir });
          }
          else if ((dir == 'N') || (dir == 'S'))
          {
            if (checkInMap(x, y - 1, nx, ny))
              points.push_back({ x, y - 1, 'L' });
            if (checkInMap(x, y + 1, nx, ny))
              points.push_back({ x, y + 1, 'R' });
          }
        }

        if (m[x][y] == '|')
        {
          if (dir == 'N')
          {
            if (checkInMap(x - 1, y, nx, ny))
              points.push_back({ x - 1, y, dir });
          }
          else if (dir == 'S')
          {
            if (checkInMap(x + 1, y, nx, ny))
              points.push_back({ x + 1, y, dir });
          }
          else if ((dir == 'R') || (dir == 'L'))
          {
            if (checkInMap(x - 1, y, nx, ny))
              points.push_back({ x - 1, y, 'N' });
            if (checkInMap(x + 1, y, nx, ny))
              points.push_back({ x + 1, y, 'S' });
          }
        }

        if (m[x][y] == '\\')
        {
          if (dir == 'R')
          {
            if (checkInMap(x + 1, y, nx, ny))
              points.push_back({ x + 1, y, 'S' });
          }

          else if (dir == 'N')
          {
            if (checkInMap(x, y - 1, nx, ny))
              points.push_back({ x, y - 1, 'L' });
          }

          else if (dir == 'S')
          {
            if (checkInMap(x, y + 1, nx, ny))
              points.push_back({ x, y + 1, 'R' });
          }

          else if (dir == 'L')
          {
            if (checkInMap(x - 1, y, nx, ny))
              points.push_back({ x - 1, y, 'N' });
          }
        }

        if (m[x][y] == '/')
        {
          if (dir == 'R')
          {
            if (checkInMap(x - 1, y, nx, ny))
              points.push_back({ x - 1, y, 'N' });
          }
          else if (dir == 'N')
          {
            if (checkInMap(x, y + 1, nx, ny))
              points.push_back({ x, y + 1, 'R' });
          }
          else if (dir == 'S')
          {
            if (checkInMap(x, y - 1, nx, ny))
              points.push_back({ x, y - 1, 'L' });
          }
          else if (dir == 'L')
          {
            if (checkInMap(x + 1, y, nx, ny))
              points.push_back({ x + 1, y, 'S' });
          }
        }
      }
      aux = points;
    }

    int count = 0;
    for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        if (v[i][j])
          count++;
      }
    }
    if (count > maxCount)
      maxCount = count;
  }
  cout << maxCount;
}
