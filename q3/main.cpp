
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <vector>;

using namespace std;

class Solution {

public:
    Solution() {};

    bool isIsomorphic(string s, string t) {

        //map<char, int> letterIndicesS1, letterIndicesS2;
        vector<pair<char, int>> letterIndicesS1, letterIndicesS2;
        char str1cpy[s.length() + 1], str2cpy[t.length() + 1];
        bool isomorphic = true;

        strcpy(str1cpy, s.c_str());
        strcpy(str2cpy, t.c_str());

        for (int i = 0; i < s.length(); i++) {

            char letter = str1cpy[i];
            char second_letter = str2cpy[i];

            bool found1 = false;
            bool found2 = false;

            if (letterIndicesS1.empty() && letterIndicesS2.empty()) {
                letterIndicesS1.emplace_back(letter, 1);
                letterIndicesS2.emplace_back(second_letter, 1);
            } else {
                if (letter == letterIndicesS1[letterIndicesS1.size() - 1].first) {
                    found1 = true;
                    letterIndicesS1[letterIndicesS1.size() - 1].second++;
                }

                if (second_letter == letterIndicesS2[letterIndicesS2.size() - 1].first) {
                    found2 = true;
                    letterIndicesS2[letterIndicesS2.size() - 1].second++;
                }

                if (!found1) {
                    letterIndicesS1.emplace_back(letter, 1);
                }

                if (!found2) {
                    letterIndicesS2.emplace_back(second_letter, 1);
                }
            }
        }


        cout << "Map 1" << endl;
        for_each(letterIndicesS1.begin(), letterIndicesS1.end(), [&](pair<const char, int> key) mutable -> void {
            cout << "KEY: " << key.first << " VAL: " << key.second << endl;
        });

        cout << "Map 2" << endl;
        for_each(letterIndicesS2.begin(), letterIndicesS2.end(), [&](pair<const char, int> key) mutable -> void {
            cout << "KEY: " << key.first << " VAL: " << key.second << endl;
        });

        auto it2 = letterIndicesS2.begin();
        for (auto it1 = letterIndicesS1.begin(); it1 != letterIndicesS1.end(); it1++) {

            for (it2; it2 != letterIndicesS2.end(); it2++) {

                if (it1->second == it2->second) {
                    break;
                } else {
                    cout << "WRONG: " << it1->first << " :" << it1->second << endl;
                    cout << "WRONG: " << it2->first << " :" << it2->second << endl;
                    isomorphic = false;
                    break;
                }
            }

            it2++;
            if (!isomorphic) {
                break;
            }

        }

        return isomorphic;
    }
};

int main() {


    Solution solution = Solution{};
    cout << solution.isIsomorphic("foo", "bar") << endl;

    Solution solution2 = Solution{};
    cout << solution2.isIsomorphic("egg", "add") << endl;

    return 0;
}