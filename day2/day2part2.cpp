#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> stringSplit(const string& str, char delim = ';')
{
    vector<string> result;

    auto startPtr = str.begin();
    auto curPtr = startPtr;

    while (curPtr != str.end())
    {
        if (*curPtr == delim)
        {
            result.push_back(string(startPtr, curPtr));
            startPtr = curPtr + 2;
            curPtr++;
        }

        curPtr++;
    }

    result.push_back(string(startPtr, str.end()));

    return result;
}

int getMinimumSetPower(const string& game)
{
    size_t colonPos = game.find(':');
    vector<string> subsets = stringSplit(game.substr(colonPos + 2));

    int minR = 0;
    int minG = 0;
    int minB = 0;

    for (const string& subset : subsets)
    {
        vector<string> draws = stringSplit(subset, ',');
        for (const string& draw : draws)
        {
            int nCubes = stoi(draw, nullptr);
            char color = draw[draw.find(' ') + 1];

            if (color == 'r')
            {
                minR = max(minR, nCubes);
            }
            else if (color == 'g')
            {
                minG = max(minG, nCubes);
            }
            else
            {
                minB = max(minB, nCubes);
            }
        }
    }

    return minR * minG * minB;
}

int main()
{
    string input;
    int result = 0;

    while (getline(cin, input))
    {
        result += getMinimumSetPower(input);
    }

    cout << result << endl;

    return 0;
}