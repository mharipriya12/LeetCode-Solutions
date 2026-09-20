#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> characters;

    int left = 0;
    int maximum = 0;

    for (int right = 0; right < s.length(); right++) {
        while (characters.count(s[right])) {
            characters.erase(s[left]);
            left++;
        }

        characters.insert(s[right]);
        maximum = max(maximum, right - left + 1);
    }

    return maximum;
}

int main() {
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s);

    return 0;
}
