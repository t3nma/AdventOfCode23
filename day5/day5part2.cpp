#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Mapping
{
    ll diff;
    ll src;
    ll end;

    Mapping(ll dest, ll src, ll len)
    {
        this->diff = (src - dest) * -1;
        this->src = src;
        this->end = src + len - 1;
    }
};

vector<Mapping> readCategoryMap()
{
    vector<Mapping> result;

    int c;
    ll dest, src, len;
    while ((c = cin.peek()) != EOF && c != '\n')
    {
        cin >> dest >> src >> len;
        result.push_back(Mapping(dest, src, len));
        cin.get();
    }

    return result;
}

vector<Mapping> filterCategoryMap(pair<ll,ll> range, const vector<Mapping>& mappings)
{
    vector<Mapping> result;

    for (auto map: mappings)
    {
        if ((range.first >= map.src && range.first <= map.end) ||
            (range.second >= map.src && range.second <= map.end))
        {
            result.push_back(map);
        }
    }

    return result;
}

void generateNewRanges(pair<ll,ll> range, const vector<Mapping>& relevantMappings, vector< pair<ll,ll> >& newRanges)
{
    if (relevantMappings.empty())
    {
        newRanges.push_back(make_pair(range.first, range.second));
        return;
    }

    if (relevantMappings[0].src > range.first)
    {
        newRanges.push_back(make_pair(range.first, relevantMappings[0].src - 1));
    }

    for (auto it = relevantMappings.begin(); it != relevantMappings.end(); ++it)
    {
        newRanges.push_back(make_pair(max(it->src, range.first) + it->diff, min(it->end, range.second) + it->diff));

        if (it != relevantMappings.begin() && it->src - 1 > (it - 1)->end + 1)
        {
            newRanges.push_back(make_pair((it - 1)->end + 1, it->src - 1));
        }
    }

    if (relevantMappings.back().end < range.second)
    {
        newRanges.push_back(make_pair(relevantMappings.back().end + 1, range.second));
    }
}

int main()
{
    vector< pair<ll,ll> > seedsToLocation;

    cin.ignore(256, ' ');
    do
    {
        pair<ll,ll> seedRange;
        cin >> seedRange.first >> seedRange.second;
        seedRange.second += seedRange.first - 1;
        seedsToLocation.push_back(seedRange);
    } while (cin.get() != '\n');

    cin.ignore();

    while (cin.ignore(256, '\n'))
    {
        vector<Mapping> mappings = readCategoryMap();
        cin.ignore();

        vector< pair<ll,ll> > newPairs;
        for (auto p: seedsToLocation)
        {
            vector<Mapping> relevantMappings = filterCategoryMap(p, mappings);

            sort(relevantMappings.begin(), relevantMappings.end(), [](auto m1, auto m2)
            { 
                return m1.src < m2.src;
            });

            generateNewRanges(p, relevantMappings, newPairs);
        }

        seedsToLocation.clear();
        copy(newPairs.begin(), newPairs.end(), back_inserter(seedsToLocation));
    }

    ll result = seedsToLocation[0].first;
    for (auto n: seedsToLocation)
    {
        result = min(result, n.first);
    }

    cout << result << endl;

    return 0;
}