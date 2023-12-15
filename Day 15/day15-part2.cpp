#include "../AOCHeaders/stdafx.h"

using ll  = long long;
using VL  = vector<long long>;
using VLL = vector<vector<long long>>;
using VS  = vector<string>;

// Template
#define REP(n)     for (int _ = 0; _ < (n); _++)
#define FOR(i, a)  for (int i = 0; i < (a); i++)
#define FORd(i, a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()

int main()
{
  fstream in("input.in", fstream::in);

  string    s, s2, l;
  char      c{}, c1{}, c2{};

  getline(in, l);
  stringstream ss{ l };
  long long    totalSum = 0;

  unordered_map<int, vector<pair<string, long long>>> box;
  int                                                 currL = 0;
  while (ss >> c)
  {
    if (c == ',')
    {
      long long curr = 0;
      for (int i = 0; i < s2.size(); i++)
      {
        curr += (long long)s2[i];
        curr *= 17;
        curr %= 256;
      }

      if (currL == -2)
      {
        if (box.find(curr) != box.end())
        {
          int found = -1;
          for (int i = 0; i < box[curr].size(); i++)
          {
            if (box[curr][i].first == s2)
              found = i;
          }

          if (found != -1)
            box[curr].erase(box[curr].begin() + found);
        }
      }
      else
      {
        if (box.find(curr) != box.end())
        {
          bool found = false;
          for (int i = 0; i < box[curr].size(); i++)
          {
            if (box[curr][i].first == s2)
            {
              box[curr][i].second = currL;
              found               = true;
            }
          }
          if (!found)
            box[curr].push_back({ s2, currL });
        }
        else
        {
          vector<pair<string, long long>> aux;
          aux.push_back({ s2, currL });
          box[curr] = aux;
        }
      }

      s.clear();
      s2.clear();
      currL = -1;
      totalSum += curr;
    }
    else
    {
      if (c == '=')
      {
        ss >> c;
        currL = c - '0';
      }
      else if (c == '-')
        currL = -2;
      else
        s2.push_back(c);
      s.push_back(c);
    }
  }

  long long curr = 0;
  for (int i = 0; i < s2.size(); i++)
  {
    curr += (long long)s2[i];
    curr *= 17;
    curr %= 256;
  }

  if (currL == -2)
  {
    if (box.find(curr) != box.end())
    {
      int found = -1;
      for (int i = 0; i < box[curr].size(); i++)
      {
        if (box[curr][i].first == s2)
          found = i;
      }

      if (found != -1)
        box[curr].erase(box[curr].begin() + found);
    }
  }
  else
  {
    if (box.find(curr) != box.end())
    {
      bool found = false;
      for (int i = 0; i < box[curr].size(); i++)
      {
        if (box[curr][i].first == s2)
        {
          box[curr][i].second = currL;
          found               = true;
        }
      }
      if (!found)
        box[curr].push_back({ s2, currL });
    }
    else
    {
      vector<pair<string, long long>> aux;
      aux.push_back({ s2, currL });
      box[curr] = aux;
    }
  }

  long long len = 0;
  for (auto & boxes : box)
  {
    for (int i = 0; i < boxes.second.size(); i++)
    {
      auto t = ((boxes.first + 1) * (i + 1) * boxes.second[i].second);
      cout << t << " ";
      len += ((boxes.first + 1) * (i + 1) * boxes.second[i].second);
    }
  }
  cout << len;
  cout << endl;
}
