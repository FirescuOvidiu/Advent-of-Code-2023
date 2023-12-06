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


    long long         max = 0, min = numeric_limits<long long>::max();
    long long st, fin;

    getline(in, l);
    {
        stringstream ss{ l };
        ss >> s;
        ss >> st;
    }

    getline(in, l);
    {
        stringstream ss{ l };
        ss >> s;
        ss >> fin;
    }

    long long res = 1;


        int count = 0;

        long long ll = 1;
        long long rr = st;

        while ((ll <= rr) && (ll + 2 < rr))
        {
            long long m  = (ll + rr) / 2;
            
            long long total = m * (st - m);
            if (total < fin)
                ll = m + 1;
            else
                rr = m + 1;
        }

        int found = ll;

        ll = 1;
        rr = st;

        while ((ll <= rr) && (ll + 2 < rr))
        {
            long long m = (ll + rr) / 2;

            long long total = m * (st - m);
            if (total > fin)
                ll = m + 1;
            else
                rr = m + 1;
        }

        found = found - 10;
        long long found2 = ll + 10;

        long long total = found * (st - found);
        while (total < fin)
        {
            found++;
            total = found * (st - found);
        }

        total = found2 * (st - found2);
        while (total < fin)
        {
            found2--;
            total = found2 * (st - found2);
        }

        cout<<found2-found+1;

    cout << res;
    cout << endl;
}
