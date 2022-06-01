//
// Created by trivm2 on 6/1/22.
//
#include "leetcode.h"

#ifndef ALGORITHM_CPP_33_SEARCHINROTATEDSORTEDARRAY_H
#define ALGORITHM_CPP_33_SEARCHINROTATEDSORTEDARRAY_H
class Problem33_searchInRotatedSortedArray : public Solution {
public:
    Problem33_searchInRotatedSortedArray() : Solution("33.txt") {

    }

private:
    void readInput(Input &input) override {
        int n, t;
        cin >> n >>  input.secondInt;
        for (int i = 0; i < n; i++) {
            cin >> t;
            input.firstVecInt.push_back(t);
        }
    }

    void doSolve(Input input) override {
        show(search(input.firstVecInt, input.secondInt));
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
#endif //ALGORITHM_CPP_33_SEARCHINROTATEDSORTEDARRAY_H
