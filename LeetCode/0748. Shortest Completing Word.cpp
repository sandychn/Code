// Time  : 12 ms (98.95%)
// Memory: 10.4 MB (89.06%)

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int licensePlateMap[26] = {};
        int wordMap[26];
        int ans = -1;
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ++licensePlateMap[tolower(ch) - 'a'];
            }
        }
        for (size_t i = 0; i < words.size(); ++i) {
            const string &word = words[i];
            memset(wordMap, 0, sizeof(wordMap));
            for (char ch : word) {
                if (isalpha(ch)) {
                    ++wordMap[tolower(ch) - 'a'];
                }
            }
            bool ok = true;
            for (int j = 0; j < 26; ++j) {
                if (licensePlateMap[j] > wordMap[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && (ans == -1 || words[ans].size() > word.size())) {
                ans = i;
            }
        }
        return ans == -1 ? "" : words[ans];
    }
};
