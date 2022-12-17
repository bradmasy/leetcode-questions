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

        vector<int> tempLeftSums;
        vector<int> tempRightSums;

        for (int i = 0; i < nums.size(); i++) {


            int leftSum = 0;
            int rightSum = 0;

            tempLeftSums.push_back(nums[i]);
            tempRightSums.push_back(nums[nums.size() - i - 1]);

//            for_each(tempLeftSums.begin(),tempLeftSums.end(),[](int each)mutable -> void { cout << each << ", " ;});
//            cout << "\nLEFT\n";
//           for_each(tempRightSums.begin(),tempRightSums.end(),[](int each)mutable -> void { cout << each << ", " ;});
//            cout << "\nRIGHT\n";
            for_each(tempLeftSums.begin(),tempLeftSums.end(),[&](int &each)mutable -> void { leftSum += each;});
            for_each(tempRightSums.begin(),tempRightSums.end(),[&](int &each)mutable -> void { rightSum += each;});

      //      cout << "LEFT SUM: " << leftSum<<endl;
      //      cout << "RIGHT SUM: " << rightSum <<endl;

            leftSums.push_back(leftSum);
            rightSums.insert(rightSums.begin(),rightSum);
            cout << "\nLEFT\n";

            for_each(leftSums.begin(),leftSums.end(),[](int each)mutable -> void { cout << each << ", " ;});
            cout << "\nRIGHT\n";
            for_each(rightSums.begin(),rightSums.end(),[](int each)mutable -> void { cout << each << ", " ;});

            rightSum = 0;
            leftSum = 0;


          //  int rightSum = i == 0 ? nums[nums.size() - 1] : rightSums[i - 1] + nums[nums.size() - (i) - 1];
        }

        for (int y = 0; y < leftSums.size(); y++) {
            for(int x = 0 ; x < rightSums.size(); x++){
                if(leftSums[y] == rightSums[x]){
                    cout << "X = " << x << " Y = " << y <<endl;
                    if(y - x > 1){
                        return y + 1;
                    }
                }
            }

        }


        return index;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> test{1, 7, 3, 6, 5, 6};
    int one = solution.pivotIndex(test);
    cout << "index is :" << one << endl;

    vector<int> test2{1, 2, 3};
    int two = solution.pivotIndex(test2);
    cout << "index is :" << two << endl;
//
//    vector<int> test3{2, 1, -1};
//    int three = solution.pivotIndex(test3);
//    cout << "index is :" << three << endl;

//    vector<int> test4{-1, -1, -1, -1, -1, 0};
//    int four = solution.pivotIndex(test4);
//    cout << "index is :" << four << endl;

    return 0;
}
