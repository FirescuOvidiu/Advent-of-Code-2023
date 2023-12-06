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

  long long                          ffff = 0;
  stringstream                       sss{ l };
  long long                          a, b;
  vector<pair<long long, long long>> seeds;

  getline(in, l);

  stringstream ssss{ l };

  while (ssss >> a >> b)
  {
    seeds.push_back({ a, a + b - 1 });
  }

  long long                          start = 0, fin = 0, num = 0;
  vector<pair<long long, long long>> newsee;

  vector<bool> test(seeds.size(), false);

  while (getline(in, l))
  {
    if (l[0] >= '0' && (l[0] <= '9'))
    {
      if (l == "")
        break;
      stringstream ss{ l };
      ss >> fin >> start >> num;

      pair<long long, long long> numToBemod = { -1, -1 };

      for (size_t i = 0; i < seeds.size(); i++)
      {
        long long st  = seeds[i].first;
        long long end = seeds[i].second;

        if ((end <= start + num - 1) && (end >= start))
        {
          if ((st >= start) && (st <= start + num - 1))
          {
            newsee.push_back({ fin + st - start, fin + end - start });
            seeds[i] = { -1, -1 };
            // test[i] = true;
          }
          else
          {
            if (st < start)
            {
              newsee.push_back({ fin, fin + end - start });
              seeds[i] = { st, start - 1 };
              //  newsee.push_back({ st,start - 1 });
              //   test[i] = true;
            }
          }
        }
        else
        {
          if ((end > start + num - 1))
          {
            if (st >= start && st <= start + num - 1)
            {
              newsee.push_back({ fin + st - start, fin + num - 1 });
              seeds[i] = { start + num, end };
              //  newsee.push_back({ start + num,end });
              // test[i] = true;
            }
            else
            {
              if (st < start)
              {
                newsee.push_back({ fin, fin + num - 1 });
                seeds[i]   = { st, start - 1 };
                numToBemod = { start + num, end };
                //  newsee.push_back({ st ,start - 1 });
                // newsee.push_back({ start + num,end });
                // test[i] = true;
              }
            }
          }
        }
      }

      if (numToBemod.first != -1 && numToBemod.second != -1)
      {
        seeds.push_back(numToBemod);
      }
    }

    if (l[0] >= 'a' && l[0] <= 'z')
    {
      //   for (size_t k= 0; k < test.size(); k++)
      //   {
      //       if (test[k] == false)
      //           newsee.push_back(seeds[k]);
      //   }
      //     test.clear();

      for (auto & c : seeds)
      {
        if (c.first != -1)
          newsee.push_back(c);
      }

      seeds = newsee;
      for (auto & c : seeds)
      {
        if (c.first > c.second)
          swap(c.first, c.second);
        // test.push_back(false);
      }

      newsee.clear();

      cout << l << endl;
    }
    // stringstream ss;
  }

  for (auto & c : seeds)
  {
    if (c.first != -1)
      newsee.push_back(c);
  }

  seeds = newsee;
  for (auto & c : seeds)
  {
    if (c.first > c.second)
      swap(c.first, c.second);
    // test.push_back(false);
  }

  for (const auto zz : seeds)
  {
    if ((min > zz.first))
      min = zz.first;
  }

  cout << min;
  cout << endl;
}
