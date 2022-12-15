#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {

        int index = -1;
        vector<int> leftSums;
        vector<int> rightSums;

        for (int i = 0; i < nums.size() ; i++) {

            //int leftSum = 0;
            // int rightSum = 0;

            int leftSum = i == 0 ? nums[i] : leftSums[i - 1] + nums[i];
            int rightSum = i == 0 ? nums[nums.size() - 1] : rightSums[i - 1] + nums[nums.size() - (i) - 1];

            leftSums.push_back(leftSum);
            rightSums.push_back(rightSum);

            cout << "nums[i]: " << nums[i] << " right: " << rightSums[i] << endl;
            for_each(leftSums.begin(), leftSums.end(), [](int each) mutable -> void { cout << each << ", "; });
            cout << "\n" ;
                 for_each(rightSums.begin(), rightSums.end(), [](int each) mutable -> void { cout << each << ", "; });
               cout << "\n";


            for (int y = 0; y < i; y++) {


            }

        }

//        for_each(leftSums.begin(), leftSums.end(), [](int each) mutable -> void { cout << each << ", "; });
//        cout << "\n";
//        for_each(rightSums.begin(), rightSums.end(), [](int each) mutable -> void { cout << each << ", "; });
//        cout << "\n";


        return index;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> test{1, 7, 3, 6, 5, 6};
    int one = solution.pivotIndex(test);
    cout << "index is :" << one << endl;

//    vector<int> test2{1, 2, 3};
//    int two = solution.pivotIndex(test2);
//    cout << "index is :" << two << endl;
//
//    vector<int> test3{2, 1, -1};
//    int three = solution.pivotIndex(test3);
//    cout << "index is :" << three << endl;
    return 0;
}
