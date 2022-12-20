
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class Solution {

public:
    Solution() {};

    bool isSubsequence(string s, string t) {

        bool sequence = false;
        vector<int> indices, actual_indices;
        int index = 0;

        if (s.empty()) {
            return true;

        }

        for (char i : s) {

            for (int y = index; y < t.size(); y++) {

                if (i == t[y]) {
                    indices.push_back(y);
                    sequence = true;
                    index = y + 1;
                    break;
                } else {
                    sequence = false;
                }
            }

            if (!sequence) {
                return false;
            }
        }

        if (indices.size() < s.size()) {
            sequence = false;
        } else {
            for (int i = 0; i < indices.size() - 1; i++) {
                if (indices[i] > indices[i + 1]) {
                    sequence = false;
                    break;
                }
            }
        }

        return sequence;
    }
};


int main() {

    Solution solution = Solution{};
    string s = "abc";
    string t = "ahbgdc";

    int g = solution.isSubsequence(s, t);
    cout << (g ? "true" : "false") << endl;


    int v = solution.isSubsequence("aaaaaa", "bbaaaa");
    cout << (v ? "true" : "false") << endl;


    return 0;
}