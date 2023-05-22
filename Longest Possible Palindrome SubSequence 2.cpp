#include <iostream>
#include <cstring>
using namespace std;

int max(int x, int y) {
    return (x > y) ? x : y;
}

int lps(char seq[], int n) {
    int table[n][n];

    // Base cases: LPS length is 1 for each individual character
    for (int i = 0; i < n; i++) {
        table[i][i] = 1;
    }

    // Build the table bottom-up
    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;

            if (seq[i] == seq[j] && cl == 2) {
                table[i][j] = 2;
            }
            else if (seq[i] == seq[j]) {
                table[i][j] = table[i + 1][j - 1] + 2;
            }
            else {
                table[i][j] = max(table[i][j - 1], table[i + 1][j]);
            }
        }
    }

    // Return the length of the LPS for the entire string
    return table[0][n - 1];
}

int main() {
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    cout << "The length of the LPS is: " << lps(seq, n) <<endl;
    return 0;
}

