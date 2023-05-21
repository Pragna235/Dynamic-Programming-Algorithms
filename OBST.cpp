#include <iostream>
using namespace std;
#define MAX_SIZE 6

void printArray(int arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void optimalBST(int n, int p[], int q[]) {
    int c[MAX_SIZE][MAX_SIZE] = {0};
    int w[MAX_SIZE][MAX_SIZE] = {0};
    int r[MAX_SIZE][MAX_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;

        w[i][i + 1] = q[i] + p[i + 1] + q[i + 1];
        r[i][i + 1] = i + 1;
        c[i][i + 1] = q[i] + p[i + 1] + q[i + 1];
    }

    for (int m = 2; m <= n; m++) {
        for (int i = 0; i <= n - m; i++) {
            int j = i + m;
            w[i][j] = p[j] + q[j] + w[i][j - 1];
            int minimum = 9999;
            for (int l = i + 1; l <= j; l++) {
                if ((c[i][l - 1] + c[l][j]) < minimum) {
                    minimum = c[i][l - 1] + c[l][j];
                    r[i][j] = l;
                }
            }
            c[i][j] = w[i][j] + c[i][r[i][j] - 1] + c[r[i][j]][j];
        }
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            int k = j + i;
            cout << "w[" << j << "][" << k << "] = " << w[j][k] << " | ";
        }
        cout << endl;
        for (int j = 0; j < n - i + 1; j++) {
            int k = j + i;
            cout << "c[" << j << "][" << k << "] = " << c[j][k] << " | ";
        }
        cout << endl;
        for (int j = 0; j < n - i + 1; j++) {
            int k = j + i;
            cout << "r[" << j << "][" << k << "] = " << r[j][k] << " | ";
        }
        cout << endl;
        cout << string((n - i + 1) * 15, '-') << endl;
    }
}

int main() {
    int n = 4;
    int p[MAX_SIZE] = {0, 3, 3, 1, 1};
    int q[MAX_SIZE] = {2, 3, 1, 1, 1};

    optimalBST(n, p, q);

    return 0;
}
