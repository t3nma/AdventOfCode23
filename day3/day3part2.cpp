#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int ENGINE_SIZE = 150;
const int SYM_BLANK = -1;
const int SYM_MARK = -2;

int engine[ENGINE_SIZE][ENGINE_SIZE];
int nRows = 0;
int nCols = 0;

int isDigit(char ch)
{
   int asciiCode = ch - '0';
   return (asciiCode >= 0 && asciiCode <= 9) ? asciiCode : -1; 
}

inline bool isSymNumber(int sym)
{
    return sym != SYM_BLANK && sym != SYM_MARK;
}

vector<int> findPartNumbers(int row, int col)
{
    vector<int> result;

    if (row != 0)
    {
        if (isSymNumber(engine[row - 1][col]))
        {
            result.push_back(engine[row - 1][col]);
        }
        else
        {
            if (col != 0 && isSymNumber(engine[row - 1][col - 1]))
            {
                result.push_back(engine[row - 1][col - 1]);
            }

            if (col != nCols - 1 && isSymNumber(engine[row - 1][col + 1]))
            {
                result.push_back(engine[row - 1][col + 1]);
            }
        }
    }

    if (row != nRows - 1)
    {
        if (isSymNumber(engine[row + 1][col]))
        {
            result.push_back(engine[row + 1][col]);
        }
        else
        {
            if (col != 0 && isSymNumber(engine[row + 1][col - 1]))
            {
                result.push_back(engine[row + 1][col - 1]);
            }

            if (col != nCols - 1 && isSymNumber(engine[row + 1][col + 1]))
            {
                result.push_back(engine[row + 1][col + 1]);
            }
        }
    }

    if (col != 0 && isSymNumber(engine[row][col - 1]))
    {
        result.push_back(engine[row][col - 1]);
    }

    if (col != nCols - 1 && isSymNumber(engine[row][col + 1]))
    {
        result.push_back(engine[row][col + 1]);
    }

    return result;
}

int main()
{
    char input;
    int curCol = 0;
    while ((input = getchar()) != EOF)
    {
        int digit = isDigit(input);
        if (digit != -1)
        {
            int number = digit;
            int len = 1;

            while ((input = getchar()) != '\n' && (digit = isDigit(input)) != -1)
            {
                number = number * 10 + digit;
                len++;
            }

            while (len-- > 0)
            {
                engine[nRows][curCol++] = number;
            }
        }

        if (input == '\n')
        {
            nRows++;
            nCols = curCol + 1;
            curCol = 0;
            continue;
        }

        engine[nRows][curCol++] = input == '*' ? SYM_MARK : SYM_BLANK;
    }
    nRows++;

    long long result = 0;
    for (int i = 0; i != nRows; ++i)
    {
        for (int j = 0; j != nCols; ++j)
        {
            if (engine[i][j] != SYM_MARK)
            {
                continue;
            }

            vector<int> contactParts = findPartNumbers(i, j);
            if (contactParts.size() == 2)
            {
                result += contactParts[0] * contactParts[1];
            }
        }
    }

    cout << result << endl;

    return 0;
}