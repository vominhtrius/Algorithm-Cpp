//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_LEETCODE_H
#define ALGORITHM_CPP_LEETCODE_H

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace  std;

struct Input {
    int firstInt;
    int secondInt;
    int thirdInt;
    int fourthInt;
    int fifthInt;

    long firstLong;
    long secondLong;
    long thirdLong;
    long fourthLong;
    long fifthLong;

    int first;
    int second;
    int third;
    int fourth;
    int fifth;

    string firstStr;
    string secondStr;
    string thirdStr;
    string fourthStr;
    string fifthStr;

    vector<int> firstVec;
    vector<int> secondVec;
    vector<int> thirdVec;
    vector<int> fourthVec;
    vector<int> fifthVec;

    vector<vector<int>> firstVec2;
    vector<vector<int>> secondVec2;
    vector<vector<int>> thirdVec2;
    vector<vector<int>> fourthVec2;
    vector<vector<int>> fifthVec2;

    vector<vector<int>> firstVec2Int;
    vector<vector<int>> secondVec2Int;
    vector<vector<int>> thirdVec2Int;
    vector<vector<int>> fourthVec2Int;
    vector<vector<int>> fifthVec2Int;

    vector<char> firstVecChar;
    vector<char> secondVecChar;
    vector<char> thirdVecChar;
    vector<char> fourthVecChar;
    vector<char> fifthVecChar;

    vector<int> firstVecInt;
    vector<int> secondVecInt;
    vector<int> thirdVecInt;
    vector<int> fourthVecInt;
    vector<int> fifthVecInt;

    vector<long> firstVecLong;
    vector<long> secondVecLong;
    vector<long> thirdVecLong;
    vector<long> fourthVecLong;
    vector<long> fifthVecLong;

    vector<string> firstVecStr;
    vector<string> secondVecStr;
    vector<string> thirdVecStr;
    vector<string> fourthVecStr;
    vector<string> fifthVecStr;
};

class Solution {
public:

    void solve() {
        Input input;
        readInput(input);
        doSolve(input);
    }

    string getInputPath() {
        return "../inputs/leetcode/" + fileInputName;
    }

private:

    string fileInputName;
    virtual void readInput(Input& input) = 0;

    virtual void doSolve(Input input) = 0;

protected:
    Solution(string fileInputName) : fileInputName(std::move(fileInputName)) {}

    template <typename T>
    void show(const vector<vector<T>>& ans) {
        for (auto v : ans) {
            for (auto q : v) {
                cout << q << " " ;
            }
            cout << endl;
        }
    }

    template <typename T>
    void show(const vector<T>& ans) {
        for (auto v : ans) {
            cout << v << " ";
        }
    }

    template <typename T>
    void show(T ans) {
        cout << ans;
    }

    template <typename T>
    void readVec(vector<T>& a) {
        int n;
        cin >> n;
        T t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            a.push_back(t);
        }
    }

    template <typename T>
    void readVec2(vector<vector<T>>& a) {
        int n, m;
        cin >> n >> m;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            a[i].resize(m);
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

};


//https://leetcode.com/problems/longest-substring-without-repeating-characters/solution/
int leetcode_lengthOfLongestSubstring(string s);

//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
vector<int> leetcode_twoSum_II();

//https://leetcode.com/problems/3sum/
vector<vector<int>> leetcode_threeSum(vector<int>& nums);
#endif //ALGORITHM_CPP_LEETCODE_H


