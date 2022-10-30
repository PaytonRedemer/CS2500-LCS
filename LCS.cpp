#include <iostream>

void lcs_length(std::string x, std::string y, int m, int n, char** b);
void print_lcs(char** b, std::string x, int i, int j);

int main()
{
    std::string x = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

    int m = x.length();
    int n = y.length();

    // char b[m+1][n+1];
    char **b = new char*[m+1];
    for(int i = 0; i <= m; i++)
        b[i] = new char[n+1];

    lcs_length(x, y, m, n, b);

    std::cout << "The longest common subsequence is \"";
    print_lcs(b, x, m, n);
    std::cout << "\"" << std::endl;

    return 0;
}


void lcs_length(std::string x, std::string y, int m, int n, char** b)
{
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

void print_lcs(char** b, std::string x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    
    if(b[i][j] == 'D')
    {
        print_lcs(b, x, i-1, j-1);
        std::cout << x[i];
    }
    else if(b[i][j] == 'U')
        print_lcs(b, x, i-1, j);
    else
        print_lcs(b, x, i, j-1);
}