#include <iostream>
#include <cstdio>

using namespace std;

const int ENGINE_SIZE = 150;
const int SYM_BLANK = -1;
const int SYM_MARK = -2;

int isDigit(char ch)
{
   int asciiCode = ch - '0';
   return (asciiCode >= 0 && asciiCode <= 9) ? asciiCode : -1; 
}

inline bool isSymNumber(int sym)
{
    return sym != SYM_BLANK && sym != SYM_MARK;
}

int main()
{
    int engine[ENGINE_SIZE][ENGINE_SIZE];
    int nRows = 0;
    int nCols = 0;

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

        engine[nRows][curCol++] = input == '.' ? SYM_BLANK : SYM_MARK;
    }
    nRows++;

    int result = 0;
    for (int i = 0; i != nRows; ++i)
    {
        for (int j = 0; j != nCols; ++j)
        {
            if (!isSymNumber(engine[i][j]))
            {
                continue;
            }

            if ((i != 0 && j != 0 && engine[i - 1][j - 1] == SYM_MARK) ||
                (i != 0 && engine[i - 1][j] == SYM_MARK) ||
                (i != 0 && j != nCols - 1 && engine[i - 1][j + 1] == SYM_MARK) ||
                (j != 0 && engine[i][j - 1] == SYM_MARK) ||
                (j != nCols - 1 && engine[i][j + 1] == SYM_MARK) ||
                (i != nRows - 1 && j != 0 && engine[i + 1][j - 1] == SYM_MARK) ||
                (i != nRows - 1 && engine[i + 1][j] == SYM_MARK) ||
                (i != nRows - 1 && j != nCols - 1 && engine[i + 1][j + 1] == SYM_MARK))
                {
                    curCol = j + 1;
                    while (curCol != nCols && engine[i][curCol] == engine[i][j])
                    {
                        engine[i][curCol++] = SYM_BLANK;
                    }

                    result += engine[i][j];
                    engine[i][j] = SYM_BLANK;
                }
        }
    }

    cout << result << endl;

    return 0;
}