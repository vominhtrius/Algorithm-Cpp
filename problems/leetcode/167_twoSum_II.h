//
// Created by trivm2 on 5/28/22.
//
#include "leetcode.h"
/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that
they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.
*/


class Problem167_TwoSum_II : public Solution {
public:
    Problem167_TwoSum_II() : Solution("167.txt") {}

private:
    void readInput(Input& input) override {
        int n,t ;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            input.firstVecInt.push_back(t);
        }
        cin >> input.secondInt;
    }

    void doSolve(Input input) override {
        vector<int> ans = twoSum(input.firstVecInt, input.secondInt);
        show(ans);
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        const int size = numbers.size();
        int i = 0, j = size - 1;
        while (i < j) {
            int s = numbers[i] + numbers[j];
            if (s > target) {
                j--;
            } else if (s < target) {
                i++;
            } else {
                break;
            }
        }

        vector<int> res;
        res.push_back(i + 1);
        res.push_back(j + 1);

        return res;
    }


};