#include <iostream>
#include <string>
#include <vector>

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

bool isValidGame(const string& game)
{
    size_t colonPos = game.find(':');
    vector<string> subsets = stringSplit(game.substr(colonPos + 2));

    for (const string& subset : subsets)
    {
        vector<string> draws = stringSplit(subset, ',');
        for (const string& draw : draws)
        {
            int nCubes = stoi(draw, nullptr);
            char color = draw[draw.find(' ') + 1];

            if ((color == 'r' && nCubes > 12) || (color == 'g' && nCubes > 13) || (color == 'b' && nCubes > 14))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string input;
    int gameId = 1;
    int result = 0;

    while (getline(cin, input))
    {
        if (isValidGame(input))
        {
            result += gameId;
        }

        gameId++;
    }

    cout << result << endl;

    return 0;
}