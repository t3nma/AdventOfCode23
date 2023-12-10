#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> times;
    vector<int> distances;

    cin.ignore(265, ' ');
    int in;
    bool firstLine = true;
    while (cin >> in)
    {
        if (firstLine)
        {
            times.push_back(in);
        }
        else
        {
            distances.push_back(in);
        }
        
        if(cin.peek() == '\n')
        {
            firstLine = false;
            cin.ignore(265, ' ');
        }
    }

    int result = 1;
    for (int t = 0; t != times.size(); ++t)
    {
        int validHolds = 0;
        for (int h = 1; h != times[t]; ++h)
        {
            if ((times[t] - h) * h > distances[t])
            {
                validHolds++;
            }
        }

        if (validHolds > 0)
        {
            result *= validHolds;
        }
    }

    cout << result << endl;

    return 0;
}