
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution{

public:
    Solution(){};
    bool isIsomorphic(string s, string t) {

        map<char,int> letterIndicesS1;
        map<char,int> letterIndicesS2;

        char str1cpy[s.length() + 1];
        char str2cpy[t.length() + 1];

        strcpy(str1cpy, s.c_str());
        strcpy(str2cpy, t.c_str());


        cout << "copy: " << str1cpy << endl;
        for(int i = 0; i < s.length(); i++){

            char letter = str1cpy[i];
            char second_letter = str2cpy[i];


            for(int y = 0; y < letterIndicesS1.size();y++){

                pair<char,int> keyVal = letterIndicesS1.;
                if(letter == key.first){
                    key.second++;
                }else{
                    cout << "here" << endl;
                    letterIndicesS1.insert(make_pair(letter,1));
                }
                cout << key.first <<endl;
            });


        }


        return true;
    }
};

int main(){


    Solution solution =  Solution{};
    solution.isIsomorphic("egg" , "add");

    return 0;
}