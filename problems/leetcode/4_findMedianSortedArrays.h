//
// Created by trivm2 on 6/2/22.
//

#ifndef ALGORITHM_CPP_4_FINDMEDIANSORTEDARRAYS_H
#define ALGORITHM_CPP_4_FINDMEDIANSORTEDARRAYS_H

#include "leetcode.h"

class Problem4_findMedianSortedArrays : public Solution {
public:
    Problem4_findMedianSortedArrays() : Solution("4.txt") {

    }

private:
    void readInput(Input &input) override {
        readVec(input.firstVecInt);
        readVec(input.secondVecInt);
    }

    void doSolve(Input input) override {
        show(findMedianSortedArrays(input.firstVecInt, input.secondVecInt));
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

        int nm = nums1.size() + nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;
        int count = 0;
        while (count <= nm / 2) {
            m1 = m2;
            if (i == nums1.size()) {
                m2 = nums2[j];
                j++;
            } else if (j == nums2.size()) {
                m2 = nums1[i];
                i++;
            } else if (nums1[i] < nums2[j]) {
                m2 = nums1[i];
                i++;
            } else {
                m2 = nums2[j];
                j++;
            }
            count++;
        }
        if (nm % 2 == 0) {
            return (m1 + m2) / 2.0;
        }
        return m2;
    }
};

#endif //ALGORITHM_CPP_4_FINDMEDIANSORTEDARRAYS_H
