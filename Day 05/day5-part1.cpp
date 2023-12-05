#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int main()
{
  fstream in("input.in", fstream::in);

  string    s, l;
  long long sum = 0;
  char      c{}, c1{}, c2{};

  vector<vector<char>> m(10000, vector<char>(10000, '0'));

  long long   max = 0, min = 9223372036854775807;
  vector<int> v;
  // vector<int> v(istream_iterator<int>{ in }, {});

  in >> s;

  vector<long long> seeds;

  getline(in, l);
  long long    ffff = 0;
  stringstream sss{ l };
  while (sss >> ffff)
  {
    seeds.push_back(ffff);
  }
  long long         start = 0, fin = 0, num = 0;
  vector<long long> newsee = seeds;

  while (getline(in, l))
  {
    for (size_t i = 0; i < seeds.size(); i++)
    {
      if (l[0] >= '0' && (l[0] <= '9'))
      {
        if (l == "")
          break;
        stringstream ss{ l };
        ss >> fin >> start >> num;
        if (seeds[i] >= start && seeds[i] <= start + num - 1)
        {
          newsee[i] = fin + seeds[i] - start;
        }
      }
    }

    if (l[0] >= 'a' && l[0] <= 'z')
    {
      seeds = newsee;
    }
    // stringstream ss;
  }

  for (const auto zz : newsee)
  {
    if (min > zz)
      min = zz;
  }

  cout << min;
  cout << endl;
}
