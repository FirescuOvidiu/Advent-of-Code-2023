#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

struct hash_pair
{
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> & p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);

    if (hash1 != hash2)
    {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

int main()
{
  fstream in("input.in", fstream::in);

  string    s, l;
  long long sum = 0, num = 0;
  char      c{}, c1{}, c2{};

  vector<vector<char>> m(10000, vector<char>(10000, '.'));

  long long   max = 0, min = 9223372036854775807;
  vector<int> v;
  // vector<int> v(istream_iterator<int>{ in }, {});

  int i = 0, j = 0;
  int n = 0, m1 = 0;
  while (getline(in, l))
  {
    for (j = 0; j < l.size(); j++)
    {
      m[i][j] = l[j];
    }
    m1 = (int)l.size();
    n++;
    i++;
    // stringstream ss;
  }

  vector<int> dx{ -1, -1, -1, 0, 0, 1, 1, 1 };
  vector<int> dy{ -1, 0, 1, -1, 1, -1, 0, 1 };

  unordered_map<pair<int, int>, vector<int>, hash_pair> vv;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m1; j++)
    {
      if (m[i][j] >= '0' && m[i][j] <= '9')
      {
        int    save = j;
        string t;
        bool   good = false;
        int    posx = 0, posy = 0;
        while (m[i][save] >= '0' && m[i][save] <= '9')
        {
          t += m[i][save];

          for (size_t z = 0; z < dx.size(); z++)
          {
            int newX = i + dx[z];
            int newY = save + dy[z];
            if (checkInMap(newX, newY, n, m1))
            {
              if ((m[newX][newY] == '*'))
              {
                good = true;
                posx = newX, posy = newY;
              }
            }
          }

          save++;
          if (!checkInMap(i, save, n, m1))
            break;
        }

        if (good)
        {
          sum = stoi(t);
          j   = save;
          if (vv.find({ posx, posy }) != vv.end())
          {
            vv[{ posx, posy }].push_back((int)sum);
          }
          else
          {
            vector<int> tttt{ (int)sum };

            vv[{ posx, posy }] = tttt;
          }
        }
      }
    }
  }
  long long total = 0;
  for (const auto & c5 : vv)
  {
    if (c5.second.size() == 2)
    {
      total += c5.second[0] * c5.second[1];
    }
  }

  cout << total;
  cout << endl;
}
