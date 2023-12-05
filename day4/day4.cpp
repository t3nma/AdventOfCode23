#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mstoi(const string& sequence, size_t begin, size_t& postIdx)
{
    int result = 0;

    while (sequence[begin] == ' ')
    {
        begin++;
    }

    size_t curPos = begin;
    while (sequence[curPos] != ' ' && curPos != sequence.length())
    {
        result = result * 10 + (sequence[curPos] - '0');
        curPos++;
    }

    postIdx = curPos;
    return result;
}

vector<int> readNumbers(const string& sequence, size_t begin, size_t end)
{
    vector<int> result;

    size_t curPos = begin;
    size_t nextPos;
    while (curPos != end)
    {
        result.push_back(mstoi(sequence, curPos, nextPos));
        curPos = nextPos;
    };

    return result;
}

int calculatePoints(const vector<int>& winningNumbers, const vector<int>& ownNumbers)
{
    int result = 0;

    for (int number: winningNumbers)
    {
        if (find(ownNumbers.begin(), ownNumbers.end(), number) != ownNumbers.end())
        {
            result = result == 0 ? 1 : result * 2;
        }
    }

    return result;
}

int main()
{
    int result = 0;

    string input;
    while (getline(cin, input))
    {
        size_t firstDiscardPos = input.find(':');
        size_t secondDiscardPos = input.find('|');
        vector<int> winningNumbers = readNumbers(input, firstDiscardPos + 2, secondDiscardPos - 1);
        vector<int> ownNumbers = readNumbers(input, secondDiscardPos + 2, input.size());
        result += calculatePoints(winningNumbers, ownNumbers);
    }

    cout << result << endl;

    return 0;
}