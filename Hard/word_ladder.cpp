#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord,
                 string endWord,
                 vector<string>& wordList) {

    unordered_set<string> words(wordList.begin(), wordList.end());

    if (!words.count(endWord))
        return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord)
            return steps;

        for (int i = 0; i < word.length(); i++) {
            char original = word[i];

            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                if (words.count(word)) {
                    words.erase(word);
                    q.push({word, steps + 1});
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    cout << ladderLength(beginWord, endWord, wordList);

    return 0;
}
