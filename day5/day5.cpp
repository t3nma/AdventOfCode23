#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Mapping
{
    ll dest;
    ll src;
    ll len;
};

vector<Mapping> readCategoryMap()
{
    vector<Mapping> result;

    int c;
    while ((c = cin.peek()) != EOF && c != '\n')
    {
        Mapping m;
        cin >> m.dest >> m.src >> m.len;
        result.push_back(m);
        cin.get();
    }

    return result;
}

int main()
{
    vector<ll> seedsToLocation;

    cin.ignore(256, ' ');
    ll seed;
    do
    {
        cin >> seed;
        seedsToLocation.push_back(seed);
    } while (cin.get() != '\n');

    cin.ignore();

    while (cin.ignore(256, '\n'))
    {
        vector<Mapping> mappings = readCategoryMap();
        cin.ignore();
        
        for (ll& n: seedsToLocation)
        {
            ll mapTo = n;
            for (Mapping map: mappings)
            {
                if (map.src <= n && n <= map.src + map.len - 1)
                {
                    mapTo = map.dest + (n - map.src);
                    break;
                }
            }
            n = mapTo;
        }
    }

    ll result = seedsToLocation[0];
    for (ll n: seedsToLocation)
    {
        result = min(result, n);
    }

    cout << result << endl;

    return 0;
}