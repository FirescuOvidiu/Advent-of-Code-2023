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
  char      c{}, c1{}, c2{};

  vector<vector<int>> m(10000, vector<int>(10000, 0));

  long long   max = 0, min = 9223372036854775807;
  vector<int> v;
  // vector<int> v(istream_iterator<int>{ in }, {});

  vector<string> t{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
  vector<int>    t1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int            result = 0;
  while (getline(in, l))
  {
    int totalsum = 0;
    sum          = 0;
    for (size_t i = 0; i < l.size(); i++)
    {
      if ((l[i] >= '0') && (l[i] <= '9'))
      {
        sum += sum * 10 + (l[i] - '0');
        break;
      }
    }
    for (size_t i = l.size(); i >= 0; i--)
    {
      if ((l[i] >= '0') && (l[i] <= '9'))
      {
        sum = sum * 10 + (l[i] - '0');
        break;
      }
    }
    result += sum;
  }
  // stringstream ss;

  cout << endl;
}
