#include <iostream>
#include <string>
#include <vector>

using namespace std;

int readDigit(string& line, int startPos)
{
    static vector<string> searchWords { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i != 9; ++i)
    {
        if (line.length() - startPos < searchWords[i].length())
        {
            continue;
        }

        int len = 0;
        string& word = searchWords[i];

        while (line[startPos+len] == word[len] && len != word.length())
        {
            len++;
        }

        if (len == word.length())
        {
            return i + 1;
        }
    }

    return -1;
}

int extractCalibrationValue(string& line)
{
    int firstDigit = -1;
    int lastDigit = -1;

    for (int i = 0; i != line.length(); ++i)
    {
        int digit = line[i] - '0';
        
        if (digit > 9)
        {
            digit = readDigit(line, i);
        }

        if (digit == -1)
        {
            continue;
        }

        if (firstDigit == -1)
        {
            firstDigit = digit;
        }

        lastDigit = digit;
    }

    return firstDigit * 10 + lastDigit;
}

int main()
{
    int result = 0;
    string line;

    while (cin >> line)
    {
        result += extractCalibrationValue(line);
    }

    cout << result << endl;

    return 0;
}