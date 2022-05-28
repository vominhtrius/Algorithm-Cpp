//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_88_MERGESORTEDARRAY_H
#define ALGORITHM_CPP_88_MERGESORTEDARRAY_H

#include "leetcode.h"

class Problem88_mergeSortedArray : public Solution {
public:
    Problem88_mergeSortedArray() : Solution("88.txt") {}

private:
    void readInput(Input &input) override {
        int m, n;
        cin >> m >> n;

        input.firstInt = m;
        input.secondInt = n;
        input.firstVecInt.resize(m + n);
        input.secondVecInt.resize(n);

        for (int i = 0; i < m; i++) {
            cin >> input.firstVecInt[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> input.secondVecInt[i];
        }
    }

    void doSolve(Input input) override {
        merge(input.firstVecInt, input.firstInt, input.secondVecInt, input.secondInt);
        show(input.firstVecInt);
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        merge_withOMN(nums1, m, nums2, n);
    }

    void merge_withOMN(vector<int> &nums1, int m, vector<int> &nums2, int n) {

        int i = m - 1, j = n -1;
        int k = n + m - 1;

        while (k >= 0) {
            if (j < 0) {
                break;
            }
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }

    void merge_withSort(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        for (int i = n, j = 0; i < n + m && j < n; i++, j++) {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};

#endif //ALGORITHM_CPP_88_MERGESORTEDARRAY_H
