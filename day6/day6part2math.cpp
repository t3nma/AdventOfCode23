#include <iostream>
#include <vector>
#include <cmath>

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

    int root1 = ceil((time - sqrt(time * time - 4 * (distance + 1))) / 2);
    int root2 = floor((time + sqrt(time * time - 4 * (distance + 1))) / 2);

    cout << root2 - root1 + 1 << endl;

    return 0;
}