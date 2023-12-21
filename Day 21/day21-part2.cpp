#include "../AOCHeaders/stdafx.h"

using ll  = long long;
using VL  = vector<long long>;
using VLL = vector<vector<long long>>;
using VS  = vector<string>;

// Template
#define REP(n)     for (long long _ = 0; _ < (n); _++)
#define FOR(i, a)  for (long long i = 0; i < (a); i++)
#define FORd(i, a) for (long long i = (a)-1; i >= 0; i--)

#define sz(x) (long long)(x).size()

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

  vector<long long> dx{ 0, +1, 0, -1 };
  vector<long long> dy{ +1, 0, -1, 0 };

  long long max = 0, min = numeric_limits<long long>::max();

  vector<string> mAux(10000, string(10000, '.'));

  auto m = getMatrix(in, nx, ny);

  long long st, end;
  for (long long i = 0; i < nx; i++)
  {
    for (long long j = 0; j < ny; j++)
    {
      if (m[i][j] == 'S')
      {
        st = i, end = j;
      }
    }
  }

  m[st][end] = '.';

  mAux = m;

  for (size_t j = 0; j < 3 + 2 * 10; j++)
  {
    for (long long i = 0; i < nx; i++)
      m[i].insert(m[i].size(), mAux[i]);
  }

  mAux = m;

  for (size_t j = 0; j < 3 + 2 * 10; j++)
  {
    for (long long i = 0; i < mAux.size(); i++)
      m.push_back(mAux[i]);
  }

  st  = st + nx * 11;
  end = end + ny * 11;

  queue<pair<long long, long long>> q2;
  q2.push({ st, end });
  // while(in>>s)

  vector<long long> diff;

  for (size_t ji = 0; ji < 500; ji++)
  {
    long long                         first = q2.size();
    queue<pair<long long, long long>> q     = q2;
    set<pair<long long, long long>>   alread;
    while (!q2.empty())
      q2.pop();
    alread.clear();
    while (!q.empty())
    {
      auto curr = q.front();
      q.pop();

      for (size_t i = 0; i < 4; i++)
      {
        long long newX = curr.first + dx[i];
        long long newY = curr.second + dy[i];
        if (checkInMap(newX, newY, 10000, 10000) && m[newX][newY] != '#')
        {
          if (alread.find({ newX, newY }) == alread.end())
          {
            q2.push({ newX, newY });
            alread.insert({ newX, newY });
          }
        }
      }
    }
    diff.push_back(q2.size() - first);
    //  cout << q2.size() << " " << ji + 1 << endl;
  }

  // calculated on paper everything
  // leaving comments 

  long long i2 = 0;
  for (const auto & c5 : diff)
    cout << c5 << " " << ++i2 << " " << diff[i2] - c5 << endl;

  vector<pair<long long, long long>> fi;
  ll                                 total = 1;
  long long                          step  = 3;
  for (long long i = 0; i < 195; i++, step++)
    total += diff[i];
  cout << endl << total << endl;

  for (long long i = 195; i < 195 + 131; i++)
  {
    fi.push_back({ diff[i], diff[i + 131] - diff[i] });
    // cout << diff[i] << " " << diff[i + 11] - diff[i] << endl;
  }

  long long j = 0;

  for (int i = 195; i < 26501365; i++)
  {
    total += fi[j].first;
    fi[j].first += fi[j].second;
    // if (i == 499)
    // cout << total;
    j++;
    j = j % fi.size();
  }

  cout << total;

  /*
  for (long long i = 0; i < nx; i++)
  {
    for (long long j = 0; j < ny; j++)
    {
    }
  }
  */
  // ll two   = 1;
  // ll start = 3;
  // ll res   = 0;

  // ll sum = for (long long i = 0; i < 26501365 - 1; i++)
  {
    // res = start + two;
    // start += 2;
    //  two = res;

    // if (i == 6)
    // cout << res;
  }
  // cout << endl << res << endl;
  // long long res  = 3 + 2 * 1;
  // long long res1 = 3 + 2 + 2 * 2;
  // long long res2 = 3 + 2 + 2 + 2 * 3;
  cout << endl;
}
