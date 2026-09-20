#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for (string word : strs) {
        string key = word;
        sort(key.begin(), key.end());

        groups[key].push_back(word);
    }

    vector<vector<string>> result;

    for (auto& group : groups)
        result.push_back(group.second);

    return result;
}

int main() {
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    vector<vector<string>> result = groupAnagrams(strs);

    for (auto group : result) {
        for (string word : group)
            cout << word << " ";

        cout << endl;
    }

    return 0;
}
