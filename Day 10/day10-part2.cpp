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

  vector<vector<char>> m(10000, vector<char>(10000, 'W'));

  long long         max = 0, min = numeric_limits<long long>::max();
  vector<long long> v;

  int nx = 0, ny = 0;

  while (getline(in, l))
  {
    stringstream ss{ l };

    for (size_t i = 0; i < l.size(); i++)
    {
      m[nx][i] = l[i];
    }
    ny = l.size();
    nx++;
  }

  int x = 0, y = 0;
  for (size_t i = 0; i < nx; i++)
  {
    for (size_t j = 0; j < ny; j++)
    {
      if (m[i][j] == 'S')
      {
        x = i;
        y = j;
      }
    }
  }

  m[x][y] = '|';

  bool check = true;
  while (check)
  {
    check = false;

    for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        if (m[i][j] != '.')
        {
          if (m[i][j] == '|')
          {
            int xa  = i - 1;
            int xb  = j;
            int xa2 = i + 1;
            int xb2 = j;

            if (checkInMap(xa, xb, nx, ny) == false || checkInMap(xa2, xb2, nx, ny) == false ||
                m[xa][xb] == '.' || m[xa][xb] == 'W' || m[xa2][xb2] == '.' || m[xa2][xb2] == 'W')
            {
              m[i][j] = 'W';
              check   = true;
              continue;
            }
            if ((m[xa][xb] != '7') && (m[xa][xb] != 'F') && (m[xa][xb] != '|'))
            {
              m[i][j] = 'W';
              check   = true;
            }
            if ((m[xa2][xb2] != 'L') && (m[xa2][xb2] != 'J') && (m[xa2][xb2] != '|'))
            {
              m[i][j] = 'W';
              check   = true;
            }
          }
          if (m[i][j] == '-')
          {
            int xa  = i;
            int xb  = j - 1;
            int xa2 = i;
            int xb2 = j + 1;

            if (checkInMap(xa, xb, nx, ny) == false || checkInMap(xa2, xb2, nx, ny) == false ||
                m[xa][xb] == '.' || m[xa][xb] == 'W' || m[xa2][xb2] == '.' || m[xa2][xb2] == 'W')
            {
              m[i][j] = 'W';
              check   = true;
              continue;
            }
            if ((m[xa][xb] != 'L') && (m[xa][xb] != 'F') && (m[xa][xb] != '-'))
            {
              m[i][j] = 'W';
              check   = true;
            }

            if ((m[xa2][xb2] != 'J') && (m[xa2][xb2] != '7') && (m[xa2][xb2] != '-'))
            {
              m[i][j] = 'W';
              check   = true;
            }
          }
          if (m[i][j] == 'L')
          {
            int xa  = i - 1;
            int xb  = j;
            int xa2 = i;
            int xb2 = j + 1;

            if (checkInMap(xa, xb, nx, ny) == false || checkInMap(xa2, xb2, nx, ny) == false ||
                m[xa][xb] == '.' || m[xa][xb] == 'W' || m[xa2][xb2] == '.' || m[xa2][xb2] == 'W')
            {
              m[i][j] = 'W';
              check   = true;
              continue;
            }
            if ((m[xa][xb] != '7') && (m[xa][xb] != 'F') && (m[xa][xb] != '|'))
            {
              m[i][j] = 'W';
              check   = true;
            }
            if ((m[xa2][xb2] != 'J') && (m[xa2][xb2] != '7') && (m[xa2][xb2] != '-'))
            {
              m[i][j] = 'W';
              check   = true;
            }
          }
          if (m[i][j] == 'J')
          {
            int xa  = i - 1;
            int xb  = j;
            int xa2 = i;
            int xb2 = j - 1;

            if (checkInMap(xa, xb, nx, ny) == false || checkInMap(xa2, xb2, nx, ny) == false ||
                m[xa][xb] == '.' || m[xa][xb] == 'W' || m[xa2][xb2] == '.' || m[xa2][xb2] == 'W')
            {
              m[i][j] = 'W';
              check   = true;
              continue;
            }
            if ((m[xa][xb] != '7') && (m[xa][xb] != 'F') && (m[xa][xb] != '|'))
            {
              m[i][j] = 'W';
              check   = true;
            }
            if ((m[xa2][xb2] != 'L') && (m[xa2][xb2] != 'F') && (m[xa2][xb2] != '-'))
            {
              m[i][j] = 'W';
              check   = true;
            }
          }
          if (m[i][j] == '7')
          {
            int xa  = i + 1;
            int xb  = j;
            int xa2 = i;
            int xb2 = j - 1;

            if (checkInMap(xa, xb, nx, ny) == false || checkInMap(xa2, xb2, nx, ny) == false ||
                m[xa][xb] == '.' || m[xa][xb] == 'W' || m[xa2][xb2] == '.' || m[xa2][xb2] == 'W')
            {
              m[i][j] = 'W';
              check   = true;
              continue;
            }
            if ((m[xa][xb] != 'L') && (m[xa][xb] != 'J') && (m[xa][xb] != '|'))
            {
              m[i][j] = 'W';
              check   = true;
            }
            if ((m[xa2][xb2] != 'L') && (m[xa2][xb2] != 'F') && (m[xa2][xb2] != '-'))
            {
              m[i][j] = 'W';
              check   = true;
            }
          }
          if (m[i][j] == 'F')
          {
            int xa  = i + 1;
            int xb  = j;
            int xa2 = i;
            int xb2 = j + 1;

            if (checkInMap(xa, xb, nx, ny) == false || checkInMap(xa2, xb2, nx, ny) == false ||
                m[xa][xb] == '.' || m[xa][xb] == 'W' || m[xa2][xb2] == '.' || m[xa2][xb2] == 'W')
            {
              m[i][j] = 'W';
              check   = true;
              continue;
            }

            if ((m[xa][xb] != 'L') && (m[xa][xb] != 'J') && (m[xa][xb] != '|'))
            {
              m[i][j] = 'W';
              check   = true;
            }
            if ((m[xa2][xb2] != 'J') && (m[xa2][xb2] != '7') && (m[xa2][xb2] != '-'))
            {
              m[i][j] = 'W';
              check   = true;
            }
          }
        }
      }
    }
  }

  int stx  = x;
  int sty  = y;
  int maxx = x;
  int maxy = y;

  // m[x][y] = 'F';
  //  m[x][y] = '7';

  vector<vector<bool>> visit(m.size(), vector<bool>(m[0].size(), false));
  vector<vector<int>>  visit2(m.size(), vector<int>(m[0].size(), 0));

  vector<vector<string>> ssaa;

  queue<pair<int, int>> x1;
  x1.push({ x + 1, y });
  visit[x][y] = true;

  long long currSum = 0;

  map<pair<int, int>, vector<pair<int, int>>> mainLoopPoints;

  vector<pair<int, int>> t;

  t.push_back({ x, y });

  mainLoopPoints.insert({ { x, y }, t });
  mainLoopPoints.insert({ { x + 1, y }, t });
  visit[x + 1][y] = true;

  vector<pair<int, int>> astamerge;

  while (!x1.empty())
  {
    auto currX = x1.front();
    x1.pop();
    astamerge.push_back(currX);
    if (currX.first == 26 && currX.second == 131)
    {
      int i = 0;
      i++;
    }

    if (m[currX.first][currX.second] == '|')
    {
      int xa = currX.first - 1;
      int xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
      }

      xa = currX.first + 1;
      xb = currX.second;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
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
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
      }

      xa = currX.first;
      xb = currX.second + 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
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
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
      }

      xa = currX.first;
      xb = currX.second + 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
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
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
      }

      xa = currX.first;
      xb = currX.second - 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
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
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
      }

      xa = currX.first;
      xb = currX.second - 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
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
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
      }

      xa = currX.first;
      xb = currX.second + 1;

      if (checkInMap(xa, xb, m.size(), m[0].size()) && visit[xa][xb] == false && m[xa][xb] != '.')
      {
        x1.push({ xa, xb });
        visit[xa][xb]  = true;
        visit2[xa][xb] = visit2[currX.first][currX.second] + 1;
        auto getT      = mainLoopPoints[{ currX.first, currX.second }];
        getT.push_back({ xa, xb });
        mainLoopPoints.insert({ { xa, xb }, getT });
      }
    }
    if (x1.empty())
    {
      int i = 0;
      i++;
    }
  }

  cout << astamerge.size();

  vector<vector<int>> visit3(m.size(), vector<int>(m[0].size(), 0));

  int z = 1;

  for (int i = 0; i < m[0].size(); i++)
  {
    for (int j = 0; j < m.size(); j++)
    {
      visit3[i][j] = -1;
    }
  }

  int      totalresss = 0;
  set<int> s222;

  vector<int> dx{ 0, 1, 0, -1, -1, -1, +1, +1 };
  vector<int> dy{ -1, 0, 1, 0, -1, +1, -1, +1 };

  stx -= 1;
  //  sty += 1;
  auto                t5 = mainLoopPoints[{ stx, sty }];
  set<pair<int, int>> astae;

  // for (const auto & aaa : t5)
  {
    // astae.push_back(aaa);
  }
  // astae.push_back({ stx, sty });

  //  for (const auto & aaa : astamerge)
  {
    // out << aaa.first << " " << aaa.second << "\n";
  }

  int oaskpsaa  = 0;
  int oaskpsaa2 = 0;
  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      if (m[i][j] == '.')
        oaskpsaa++;
      if (m[i][j] != '.' && m[i][j] != 'W')
        oaskpsaa2++;
    }
  }
  std::cout << oaskpsaa2 << endl << oaskpsaa << endl;

  int totalCount = 0, totalCount2 = 0;
  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      if (m[i][j] == '.' || m[i][j] == 'W')
      {
        int countS = 0, countN = 0;
        for (int zz = 0; zz < j; zz++)
        {
          if (m[i][zz] == 'L')
          {
            countN++;
          }
          if (m[i][zz] == 'J')
          {
            countN++;
          }
          if (m[i][zz] == '7')
          {
            countS++;
          }
          if (m[i][zz] == 'F')
          {
            countS++;
          }
          if (m[i][zz] == '|')
          {
            countN++;
            countS++;
          }
        }

        if (countN + countS == 0)
          continue;

        if (std::min(countN, countS) % 2 == 1)
        {
          totalCount2++;
        }

        if ((countN + countS) % 2 == 0)
        {
          totalCount++;
          // cout << i << " " << j << " ";
          // cout << countN << " " << countS << endl;
        }
      }
    }
  }

  // AICI E REZULTATUL CORECT
  cout << totalCount2;

  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      int count = 1;
      int test2 = true;

      if (m[i][j] != '.')
        test2 = false;

      if (m[i][j] == '.')
      {
        queue<pair<int, int>> q;
        q.push({ i, j });
        visit3[i][j] = z;
        auto m2      = m;
        m[i][j]      = '=';
        while (!q.empty())
        {
          auto currX = q.front();
          q.pop();

          if ((currX.first == 0) || (currX.second == 0) || (currX.first >= nx) ||
              (currX.second >= ny))
            test2 = false;

          for (int k = 0; k < 8; k++)
          {
            if (checkInMap(currX.first + dx[k], currX.second + dy[k], m.size(), m[0].size()))
            {
              //  if (astae.find({ currX.first + dx[k], currX.second + dy[k] }) == astae.end())
              if ((m2[currX.first + dx[k]][currX.second + dy[k]] != '.'))
                test2 = false;
            }
          }

          for (int k = 0; k < 4; k++)
          {
            if (checkInMap(currX.first + dx[k], currX.second + dy[k], m.size(), m[0].size()))
            {
              if (m[currX.first + dx[k]][currX.second + dy[k]] == '.')
              {
                q.push({ currX.first + dx[k], currX.second + dy[k] });
                visit3[currX.first + dx[k]][currX.second + dy[k]] = z;
                m[currX.first + dx[k]][currX.second + dy[k]]      = '=';
                count++;
              }
            }
          }
        }
        if (test2)
        {
          totalresss += count;
          cout << i << " " << j << " " << count << endl;
        }

        z++;
        s222.insert(z);
      }
      //  cout << i << " " << j << "endl";
    }
  }
  cout << totalresss;
  /*
  int      count = 0;
  for (int i = 0; i <= nx; i++)
  {
    for (int j = 0; j <= ny; j++)
    {
      cout << visit3[i][j];
      if (visit3[i][j] != -1)
      {
        if (s222.find(visit3[i][j]) != s222.end())
        {
          s222.insert(visit3[i][j]);
          count++;
        }
      }
    }
    cout << endl;
  }
  */
  // cout << count;

  // cout << endl;
}
