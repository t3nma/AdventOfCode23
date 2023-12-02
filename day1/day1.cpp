#include <iostream>
#include <string>

using namespace std;

int extractCalibrationValue(string& line)
{
    int firstDigit = -1;
    int lastDigit = -1;

    for (int i = 0; i != line.length(); ++i)
    {
        int asciiCode = line[i] - '0';
        
        if (asciiCode > 9)
        {
            continue;
        }

        if (firstDigit == -1)
        {
            firstDigit = asciiCode;
        }
        
        lastDigit = asciiCode;
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