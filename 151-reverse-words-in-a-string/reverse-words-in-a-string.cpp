class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        int i = s.size() - 1;

        while (i >= 0) {
            // Skip extra spaces
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            if (i < 0)
                break;

            // Extract a word
            int j = i;
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            // Add the word to the answer
            if (!ans.empty()) {
                ans += ' ';
            }

            ans += s.substr(i + 1, j - i);
        }

        return ans;
    }
};