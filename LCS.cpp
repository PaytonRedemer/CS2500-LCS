// Author: Payton Redemer
// File: LCS.cpp
// Purpose: Implement the Longest Common Subsequence
#include <iostream>

// Purpose: Create b table and return the length for the Longest Common Subsequence algorithm
// Precondition: m = x.length, n = y.length, b is a mxn array
// Postcondition: Filled out b table
int lcs_length(std::string x, std::string y, int m, int n, char** b);

// Purpose: Print out Longest Common Subsequence
// Precondition: b was created with lcs_length() using the x and y, i = x.length, j = y.length
// Postcondition: Print out Longest Common Subsequence
void print_lcs(char** b, std::string x, int i, int j);

int main()
{
    std::string x = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

    // Inserting space at beginning of each string to make algorithm easier to convert
    x.insert(0," ");
    y.insert(0," ");

    int m = x.length();
    int n = y.length();


    // create dynamic array b[m+1][n+1] to pass to function
    char **b = new char*[m+1];
    for(int i = 0; i <= m; i++)
        b[i] = new char[n+1];

    // create b table and save length of LCS
    int length = lcs_length(x, y, m, n, b);

    std::cout << "The longest common subsequence is \"";
    print_lcs(b, x, m, n);
    std::cout << "\" and the length is " << length-1 << std::endl;

    // Freeing memory
    for(int i = 0; i <= m; i++)
        delete[] b[i];
    delete[] b;

    return 0;
}


int lcs_length(std::string x, std::string y, int m, int n, char** b)
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
            if(x[i] == y[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D'; // Diagonal arrow
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U'; // Up arrow
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L'; // Left arrow
            }
        }
    }

    return c[m][n];
}

void print_lcs(char** b, std::string x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    
    // Diagonal arrow
    if(b[i][j] == 'D')
    {
        print_lcs(b, x, i-1, j-1);
        std::cout << x[i];
    }
    // Up arrow
    else if(b[i][j] == 'U')
        print_lcs(b, x, i-1, j);
    // Left arrow
    else
        print_lcs(b, x, i, j-1);
}