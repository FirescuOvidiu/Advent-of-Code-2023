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
  char      c{};

  vector<vector<char>> m(10000, vector<char>(10000, '0'));

  long long         max = 0, min = numeric_limits<long long>::max();
  vector<long long> v;
  int               j = 0;
  while (getline(in, l))
  {
    stringstream ss{ l };

    for (size_t i = 0; i < l.size(); i++)
    {
      m[j][i] = l[i];
    }
    j++;
  }

  int x, y;
  for (size_t i = 0; i < m[0].size(); i++)
  {
    for (size_t j = 0; j < m.size(); j++)
    {
      if (m[i][j] == 'S')
      {
        x = i;
        y = j;
      }
    }
  }

  m[x][y] = '|';

  vector<vector<bool>>  visit(m.size(), vector<bool>(m[0].size(), false));
  vector<vector<int>>   visit2(m.size(), vector<int>(m[0].size(), 0));
  queue<pair<int, int>> x1;

  x1.push({ x, y });
  visit[x][y]       = true;
  long long currSum = 0;

  while (!x1.empty())
  {
    auto currX = x1.front();
    x1.pop();

    if (m[currX.first][currX.second] == '|')
    {
      int xa = currX.first - 1;
      int xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }

      xa = currX.first + 1;
      xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }
    }
    if (m[currX.first][currX.second] == '-')
    {
      int xa = currX.first;
      int xb = currX.second - 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }

      xa = currX.first;
      xb = currX.second + 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }
    }
    if (m[currX.first][currX.second] == 'L')
    {
      int xa = currX.first - 1;
      int xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }

      xa = currX.first;
      xb = currX.second + 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }
    }
    if (m[currX.first][currX.second] == 'J')
    {
      int xa = currX.first - 1;
      int xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }

      xa = currX.first;
      xb = currX.second - 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }
    }
    if (m[currX.first][currX.second] == '7')
    {
      int xa = currX.first + 1;
      int xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }

      xa = currX.first;
      xb = currX.second - 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }
    }
    if (m[currX.first][currX.second] == 'F')
    {
      int xa = currX.first + 1;
      int xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }

      xa = currX.first;
      xb = currX.second + 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
      }
    }
  }

  int max2 = 0;
  for (int i = 0; i < m[0].size(); i++)
  {
    for (int j = 0; j < m.size(); j++)
    {
      if (visit2[i][j] > max2)
        max2 = visit2[i][j];
    }
  }

  cout << max2;

  cout << endl;
}
