#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll readNumber()
{
    ll result = 0;

    char c;
    while ((c = cin.get()) && c != '\n' && c != EOF)
    {
        int digit = c - '0';

        if (digit < 0 || digit > 9)
        {
            continue;
        }

        result = result * 10 + digit;
    }

    return result;
}

int main()
{
    ll time = readNumber();
    ll distance = readNumber();

    int result = 0;
    for (int h = 1; h != time; ++h)
    {
        if ((time - h) * h > distance)
        {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}