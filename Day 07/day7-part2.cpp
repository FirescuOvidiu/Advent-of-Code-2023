#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int find(vector<pair<char, int>> ceAre)
{
  int p = 0;

  for (const auto & a : ceAre)
  {
    if (a.second == 5)
    {
      p = 7;
      return p;
    }
  }

  for (const auto & a : ceAre)
  {
    if (a.second == 4)
    {
      p = 6;
      return p;
    }
  }

  for (const auto & a : ceAre)
  {
    if (a.second == 3)
    {
      p = 4;
      for (const auto & b : ceAre)
      {
        if (b.second == 2)
        {
          p = 5;
          break;
        }
      }

      return p;
    }
  }

  for (const auto & a : ceAre)
  {
    if (a.second == 2)
    {
      p = 2;
      for (const auto & b : ceAre)
      {
        if ((b.second == 2) && (a.first != b.first))
        {
          p = 3;
          break;
        }
      }
      return p;
    }
  }
  p = 1;
  return p;
}

void findBest(int & p1, int countJ, vector<char> cards, vector<int> count)
{
  if (countJ == 4)
  {
    p1 = 7;
  }

  if (count['J'] == 1)
  {
    count['J']--;
    for (const auto & car : cards)
    {
      count[car]++;

      vector<pair<char, int>> ceAre3;
      for (int k = 0; k < count.size(); k++)
        if (count[k] != 0)
          ceAre3.push_back({ k, count[k] });

      int p3 = find(ceAre3);
      if (p1 < p3)
        p1 = p3;

      count[car]--;
    }
  }

  if (count['J'] == 2)
  {
    count['J']--;
    count['J']--;
    for (const auto & car : cards)
    {
      count[car]++;
      for (const auto & car2 : cards)
      {
        count[car2]++;
        {
          vector<pair<char, int>> ceAre;
          for (int k = 0; k < count.size(); k++)
            if (count[k] != 0)
              ceAre.push_back({ k, count[k] });

          int p4 = find(ceAre);
          if (p1 < p4)
            p1 = p4;
        }
        count[car2]--;
      }
      count[car]--;
    }
  }

  if (count['J'] == 3)
  {
    count['J']--;
    count['J']--;
    count['J']--;

    for (const auto & car3 : cards)
    {
      count[car3]++;
      for (const auto & car : cards)
      {
        count[car]++;
        for (const auto & car2 : cards)
        {
          count[car2]++;
          {
            vector<pair<char, int>> ceAre;
            for (int k = 0; k < count.size(); k++)
              if (count[k] != 0)
                ceAre.push_back({ k, count[k] });

            int p4 = find(ceAre);
            if (p1 < p4)
              p1 = p4;
          }
          count[car2]--;
        }
        count[car]--;
      }
      count[car3]--;
    }
  }

  if (count['J'] == 4)
  {
    count['J']--;
    count['J']--;
    count['J']--;
    count['J']--;

    for (const auto & car4 : cards)
    {
      count[car4]++;
      for (const auto & car3 : cards)
      {
        count[car3]++;
        for (const auto & car : cards)
        {
          count[car]++;
          for (const auto & car2 : cards)
          {
            count[car2]++;
            {
              vector<pair<char, int>> ceAre;
              for (int k = 0; k < count.size(); k++)
                if (count[k] != 0)
                  ceAre.push_back({ k, count[k] });

              int p4 = find(ceAre);
              if (p1 < p4)
                p1 = p4;
            }
            count[car2]--;
          }
          count[car]--;
        }
        count[car3]--;
      }
      count[car4]--;
    }
  }
}

int main()
{
  fstream in("input.in", fstream::in);

  string    s, l;
  long long sum = 0, num = 0;
  char      c{}, c1{}, c2{};

  vector<vector<char>> m(10000, vector<char>(10000, '0'));

  long long         max = 0, min = numeric_limits<long long>::max();
  vector<long long> end;

  vector<string> st;

  while (in >> s >> num)
  {
    st.push_back(s);
    end.push_back(num);
  }

  vector<string>    newSt(st.size());
  vector<long long> newEnd(st.size());

  vector<char> cards{ 'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J' };

  for (size_t i = 0; i < st.size(); i++)
  {
    int wins = 0;

    for (size_t j = 0; j < st.size(); j++)
    {
      if (i == j)
        continue;

      string currX = st[i], currY = st[j];
      ranges::sort(currX);
      ranges::sort(currY);

      int s1, s2;

      vector<int> count(1000, 0);
      vector<int> count2(1000, 0);
      for (size_t z = 0; z < currX.size(); z++)
        count[currX[z]]++;
      for (size_t z = 0; z < currY.size(); z++)
        count2[currY[z]]++;

      vector<pair<char, int>> ceAre;
      for (int k = 0; k < count.size(); k++)
        if (count[k] != 0)
          ceAre.push_back({ k, count[k] });

      vector<pair<char, int>> ceAre2;
      for (int k = 0; k < count2.size(); k++)
        if (count2[k] != 0)
          ceAre2.push_back({ k, count2[k] });
      int p1 = find(ceAre), p2 = find(ceAre2);

      findBest(p1, count['J'], cards, count);
      findBest(p2, count2['J'], cards, count2);

      if (p1 > p2)
      {
        wins++;
      }
      else
      {
        if (p1 == p2)
        {
          for (int t = 0; t < st[i].size(); t++)
          {
            int pos1 = 0, pos2 = 0;

            for (int h = 0; h < cards.size(); h++)
            {
              if (st[i][t] == cards[h])
                pos1 = h;
              if (st[j][t] == cards[h])
                pos2 = h;
            }
            if (pos1 < pos2)
            {
              wins++;
              break;
            }
            if (pos1 > pos2)
              break;
          }
        }
      }
    }

    newSt[wins]  = (st[i]);
    newEnd[wins] = (end[i]);

    cout << i << endl;
  }

  long long res = 0;
  for (size_t z = 0; z < newEnd.size(); z++)
  {
    res += (z + 1) * newEnd[z];
  }
  cout << res;

  cout << endl;
}
