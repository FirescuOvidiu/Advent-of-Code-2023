#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

long long recursive(string &                            m,
                    vector<long long> &                 nums,
                    vector<vector<vector<long long>>> & freq,
                    int                                 st,
                    int                                 fn,
                    int                                 pos)
{
  if ((st == m.size()) && (fn == nums.size()))
    return 1;
  if ((st == m.size()) && (fn != nums.size()))
    return 0;

  // we already found this match before?
  if (freq[st][fn][pos] != -1)
    return freq[st][fn][pos];

  long long & sum = freq[st][fn][pos];
  sum             = 0;

  if ((m[st] == '.' || m[st] == '?'))
  {
    if (pos == 0)
      freq[st][fn][pos] += recursive(m, nums, freq, st + 1, fn, pos);
  }

  if (fn == nums.size() && m[st] == '#')
    return 0;

  if ((m[st] == '#' || m[st] == '?') && (fn < nums.size()))
  {
    // move to next element
    st++;
    // check group
    if (pos + 1 == nums[fn])
    {
      // check next element
      if ((m[st] == '.'))
        sum += recursive(m, nums, freq, st, fn + 1, 0);
      else if (m[st] == '?')
        sum += recursive(m, nums, freq, st + 1, fn + 1, 0);
    }
    else
    {
      sum += recursive(m, nums, freq, st, fn, pos + 1);
    }
  }
  return sum;
}

long long problem2(string & m, vector<long long> & nums)
{
  vector<vector<vector<long long>>> freq(
    200, vector<vector<long long>>(200, vector<long long>(200, -1)));

  auto sum = recursive(m, nums, freq, 0, 0, 0);
  cout << sum << " ";
  return sum;
}

vector<string> getMatrix(fstream & in, long long & nx, long long & ny)
{
  vector<string>            m;
  string                    l;
  char                      c;
  long long                 num = 0;
  vector<vector<long long>> nums;
  vector<long long>         count;

  while (getline(in, l))
  {
    string            ma;
    vector<long long> nu;
    stringstream      ss{ l };
    ss >> ma;
    while (ss >> num)
    {
      nu.push_back(num);
      ss >> c;
    }
    nums.push_back(nu);
    m.push_back(ma);

    long long nus = 0;
    for (const auto & ll : ma)
      if (ll == '?')
        nus++;
    count.push_back(nus);
  }

  long long totalsum = 0;

  long long pas = 0;
  long long sum = 0, tsum = 0;
  for (const auto & line : m)
  {
    sum = 0;

    std::vector<char> perm(count[pas], '.');

    std::vector<char> perm2(count[pas], '#');

    long long didonce = false;
    long long number  = 0;
    long long sum     = 0;

    string currString = line;

    vector<vector<char>> perms1;
    vector<vector<char>> perms2;

    while (number < count[pas])
    {
      do
      {
        perms1.push_back(perm);
      } while (std::next_permutation(perm.begin(), perm.end()));

      perm[number] = '#';
      number++;
      if ((number == count[pas]) && (didonce == false))
      {
        perm    = perm2;
        didonce = true;
        number--;
      }
    }

    for (int ip = 0; ip < perms1.size(); ip++)
    {
      long long it   = 0;
      long long it2  = 0;
      bool      ebun = true;
      for (size_t i = 0; i < currString.size(); i++)
      {
        while (currString[i] == '.')
          i++;

        if ((currString[i] == '?') && (perms1[ip][it2] == '.'))
        {
          it2++;
          continue;
        }

        if (i == currString.size())
          break;

        long long count2 = 0;
        while (i < currString.size() && (currString[i] == '#' || currString[i] == '?'))
        {
          if (currString[i] == '?')
          {
            if (perms1[ip][it2++] == '.')
              break;
          }
          count2++;
          i++;
        }

        if (it <= nums[pas].size() - 1 && count2 != nums[pas][it])
        {
          ebun = false;
          break;
        }
        it++;
      }

      if (ebun && (it == nums[pas].size()))
        sum++;
    }
    cout << sum << endl;
    tsum += sum;
    pas++;
  }

  cout << endl;
  cout << tsum;
  nx = m.size();
  ny = m[0].size();

  return m;
}

int main()
{
  fstream in("input.in", fstream::in);

  string    s, l;
  long long sum = 0, num = 0, nx = 0, ny = 0;
  char      c{};

  vector<vector<char>> m1(10000, vector<char>(10000, '0'));

  long long         max = 0, min = numeric_limits<long long>::max();
  vector<long long> v;

  getMatrix(in, nx, ny);

  // while(in>>s)
  while (getline(in, l))
  {
    stringstream ss{ l };
  }

  /*
  for (long long i = 0; i < nx; i++)
  {
    for (long long j = 0; j < ny; j++)
    {
    }
  }
  */

  cout << endl;
}
