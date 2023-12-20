#include "../AOCHeaders/stdafx.h"

using ll = long long;

int main()
{
  fstream in("input.in", fstream::in);

  unordered_map<string, tuple<string, bool, vector<string>>> pairs;
  unordered_map<string, unordered_map<string, string>>       remembers;

  string         a, b, c;
  vector<string> aux, aux2;
  string         l;

  // read input
  while (getline(in, l))
  {
    stringstream ss{ l };
    ss >> a >> b;

    aux.clear();
    while (ss >> c)
    {
      if (c[c.size() - 1] == ',')
        c.erase(c.end() - 1);
      aux.push_back(c);
    }

    b = a[0];
    a.erase(a.begin());
    pairs.insert({ a, { b, false, aux } });
    if (b[0] == '&')
    {
      aux2.push_back(a);
    }
  }

  // save input modules for each &
  for (const auto & bun : aux2)
  {
    unordered_map<string, string> copii;

    for (const auto & c : pairs)
    {
      for (const auto c1 : get<2>(c.second))
      {
        if (bun == c1)
        {
          copii[c.first] = "low";
        }
      }

      remembers[bun] = copii;
    }
  }

  unordered_map<string, vector<int>> rk;
  for (auto & c : remembers["kl"])
  {
    rk[c.first] = {};
  }

  // parse 1000 time
  ll high = 0, low = 0;
  for (long long i = 0; i < 10000; i++, low++)
  {
    queue<tuple<string, string, string>> q;
    for (const auto & c : get<2>(pairs["roadcaster"]))
      q.push({ "roadcaster", "low", c });

    while (!q.empty())
    {
      auto start  = get<0>(q.front());
      auto sig    = get<1>(q.front());
      auto finish = get<2>(q.front());
      auto curr   = pairs[get<2>(q.front())];

      sig == "low" ? low++ : high++;

      q.pop();

      if (get<0>(curr)[0] == '%')
      {
        if (sig == "low")
        {
          for (auto c : get<2>(pairs[finish]))
            q.push({ finish, get<1>(pairs[finish]) ? "low" : "high", c });

          get<1>(pairs[finish]) = !get<1>(pairs[finish]);
        }
      }
      else if (get<0>(curr)[0] == '&')
      {
        if (remembers.find(finish) != remembers.end())
        {
          remembers[finish][start] = sig;
          if ((finish == "kl") && (sig == "high"))
          {
            rk[start].push_back(i);
          }
        }

        bool allHigh = true;
        for (const auto & c2 : remembers[finish])
          if (c2.second == "low")
            allHigh = false;

        for (auto c : get<2>(pairs[finish]))
          q.push({ finish, allHigh ? "low" : "high", c });
      }
    }
  }

  for (const auto & r : rk)
    cout << r.second[1] - r.second[0] << ",";

  // calculate online cmmmdc
}
