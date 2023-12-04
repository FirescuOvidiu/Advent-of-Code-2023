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
  string col;
  int    id;
  while (getline(in, l))
  {
    stringstream ss{ l };
    ss >> s >> id >> c;
    int  cr = 0, cb = 0, cg = 0;
    bool test = true;
    while (ss >> num >> col)
    {
      if (col[col.size() - 1] == ';')
      {
        col.erase(col.end() - 1);
        if (col == "blue")
          cb += num;
        if (col == "red")
          cr += num;
        if (col == "green")
          cg += num;

        if (!((cr <= 12) && (cg <= 13) && (cb <= 14)))
          test = false;
        cr = 0, cb = 0, cg = 0;
        continue;
      }
      if (col[col.size() - 1] == ',')
        col.erase(col.end() - 1);
      if (col == "blue")
        cb += num;
      if (col == "red")
        cr += num;
      if (col == "green")
        cg += num;
    }
    if (test && ((cr <= 12) && (cg <= 13) && (cb <= 14)))
      sum += id;
  }

  cout << sum;
  cout << endl;
}
