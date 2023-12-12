#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

char & getEl(long long              it2,
             long long              a,
             long long              b,
             long long              c,
             long long              d,
             long long              e,
             long long              permS,
             long long              permS2,
             long long              permS3,
             long long              permS4,
             long long              permS5,
             vector<vector<char>> & perm,
             vector<vector<char>> & perm2)
{
  if (it2 < permS)
    return perm[a][it2];
  if (it2 < permS2)
    return perm2[b][it2 - permS];
  if (it2 < permS3)
    return perm2[c][it2 - permS2];
  if (it2 < permS4)
    return perm2[d][it2 - permS3];
  if (it2 < permS5)
    return perm2[e][it2 - permS4];

  cout << 1;
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

  for (size_t i = 0; i < m.size(); i++)
  {
    auto aux  = "?" + m[i];
    auto aux2 = nums[i];
    for (size_t j = 0; j < 4; j++)
    {
      for (const auto & sa : aux)
        m[i].push_back(sa);

      for (const auto & sa : aux2)
        nums[i].push_back(sa);
    }
    m[i].push_back('.');

    totalsum += problem2(m[i], nums[i]);
  }

  cout << totalsum;

  // part 1 solution doesnt work for part 2 starting from 0
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

    std::vector<char> perm3(count[pas] + 1, '.');

    std::vector<char> perm4(count[pas] + 1, '#');

    number  = 0;
    didonce = false;
    while (number < count[pas] + 1)
    {
      do
      {
        perms2.push_back(perm3);
      } while (std::next_permutation(perm3.begin(), perm3.end()));

      perm3[number] = '#';
      number++;
      if ((number == count[pas] + 1) && (didonce == false))
      {
        perm3   = perm4;
        didonce = true;
        number--;
      }
    }

    long long sP1    = perm.size();
    long long sPerm2 = perm.size() + perm3.size();
    long long sPerm3 = perm.size() + 2 * perm3.size();
    long long sPerm4 = perm.size() + 3 * perm3.size();
    long long sPerm5 = perm.size() + 4 * perm3.size();

    ranges::sort(perms1);
    ranges::sort(perms2);

    for (int ip = 0; ip < perms1.size(); ip++)
    {
      for (int j = 0; j < perms2.size(); j++)
      {
        for (int k = 0; k < perms2.size(); k++)
        {
          for (int o = 0; o < perms2.size(); o++)
          {
            for (int u = 0; u < perms2.size(); u++)
            {
              long long it   = 0;
              long long it2  = 0;
              bool      ebun = true;
              for (size_t i = 0; i < currString.size(); i++)
              {
                while (currString[i] == '.')
                  i++;

                if ((currString[i] == '?') && (getEl(it2, ip, j, k, o, u, sP1, sPerm2, sPerm3,
                                                     sPerm4, sPerm5, perms1, perms2) == '.'))
                {
                  it2++;
                  continue;
                }

                if (i == currString.size())
                  break;

                long long count2 = 0;
                while (i < currString.size() && (currString[i] == '#' || currString[i] == '?'))
                {
                  if ((currString[i] == '?') && (getEl(it2++, ip, j, k, o, u, sP1, sPerm2, sPerm3,
                                                       sPerm4, sPerm5, perms1, perms2) != '#'))
                    break;

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

              // if (it2 < sP1)
              if (it < nums[pas].size() / 5)
              {
                ip++;
                j = 0;
                k = 0;
                o = 0;
                u = -1;
                if (ip == perms1.size())
                  j = k = o = u = perms2.size();
              }

              else if (it < nums[pas].size() / 5 * 2)  // if (it2 < sPerm2)
              {
                j++;
                k = 0;
                o = 0;
                u = -1;
                if (j == perms2.size())
                  k = o = u = perms2.size();
              }

              else if (it < nums[pas].size() / 5 *
                              3)  // if (it2 < sPerm3)  // if (it < nums[pas].size() / 5 * 3)
              {
                k++;
                o = 0;
                u = -1;
                if (k == perms2.size())
                  o = u = perms2.size();
              }

              else if (it < nums[pas].size() / 5 * 4)
              //   if (it2 < sPerm3)
              {
                o++;
                u = -1;
                if (o == perms2.size())
                  u = perms2.size();
              }
            }
          }
        }
      }
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
