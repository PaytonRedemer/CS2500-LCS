#include <iostream>

using std::string;

void lcs_length(string x, string y)
{
    int m = x.length();
    int n = y.length();

    char b[m+1][n+1];
    int c[m+1][n+1];

    for(int i = 1; i <= m; i++)
        c[i][0] = 0;
    for(int j = 0; j <= n; j++)
        c[0][j] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D';
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }
    }
}

void print_lcs()
{

}


int main()
{


    return 0;
}