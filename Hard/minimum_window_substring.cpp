#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty())
        return "";

    vector<int> count(128, 0);

    for (char c : t)
        count[c]++;

    int required = t.length();
    int left = 0;

    int minLength = INT_MAX;
    int start = 0;

    for (int right = 0; right < s.length(); right++) {
        if (count[s[right]] > 0)
            required--;

        count[s[right]]--;

        while (required == 0) {
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                start = left;
            }

            count[s[left]]++;

            if (count[s[left]] > 0)
                required++;

            left++;
        }
    }

    if (minLength == INT_MAX)
        return "";

    return s.substr(start, minLength);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s, t);

    return 0;
}
