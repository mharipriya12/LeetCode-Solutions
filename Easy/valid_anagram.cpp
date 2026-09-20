#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> count;

    for (char c : s)
        count[c]++;

    for (char c : t) {
        count[c]--;

        if (count[c] < 0)
            return false;
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << (isAnagram(s, t) ? "true" : "false");

    return 0;
}
