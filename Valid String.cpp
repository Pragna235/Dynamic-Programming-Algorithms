/*
*********************************************************************************************************************
Write an algorithm and implement in C++ for the following problem.
You are given a string of n characters s[1:n], which you believe to be a corrupted text document in which
 all punctuation has vanished (so that it looks something like "itwasthebestoftimes...").
 You wish to reconstruct the document using a dictionary, which is available in the form of a Boolean
 function dict(.): for any string w,

 dict(w) = {true    if w is a valid word
           {false   otherwise

(a) Give a dynamic programming algorithm that determines whether the string s[.] can be
reconstructed as a sequence of valid words. The running time should be at most O(n^2), assuming calls
 to dict take unit time.
 (b) In the event that the string is valid, make your algorithm output the corresponding sequence of words.
*********************************************************************************************************************
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dict(const string& word) {
    // Implementation of the dictionary function
    // Replace with your own dictionary function implementation
    // Returns true if word is a valid word, false otherwise
    // Assumes it takes constant time
    // Example implementation:
    vector<string> validWords = {"it", "was", "the", "best", "night", "ever"};
    return find(validWords.begin(), validWords.end(), word) != validWords.end();
}

bool isValidReconstruction(const string& s) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j] && dict(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

vector<string> getWordSequence(const string& s) {
    vector<string> words;
    int n = s.length();
    int end = n;

    for (int start = n - 1; start >= 0; start--) {
        if (dict(s.substr(start, end - start))) {
            words.push_back(s.substr(start, end - start));
            end = start;
        }
    }

    reverse(words.begin(), words.end());
    return words;
}

int main() {
    string s = "itwasthebestnightever";

    if (isValidReconstruction(s)) {
        vector<string> wordSequence = getWordSequence(s);
        cout << "Valid word sequence: ";
        for (const string& word : wordSequence) {
            cout << word << " ";
        }
        cout << endl;
    } else {
        cout << "No valid reconstruction possible." << endl;
    }

    return 0;
}
