//
// Created by trivm2 on 5/29/22.
//

#ifndef ALGORITHM_CPP_560_SUBARRAYSUMEQUALK_H
#define ALGORITHM_CPP_560_SUBARRAYSUMEQUALK_H
#include "leetcode.h"

class Problem560_subarraySumEqualsK : public Solution {
public:
    Problem560_subarraySumEqualsK() : Solution("560.txt") {

    }

private:
    void readInput(Input &input) override {
        readVec(input.firstVecInt);
        cin >> input.secondInt;
    }

    void doSolve(Input input) override {
        show(subarraySum(input.firstVecInt, input.secondInt));
    }

    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        unordered_map<int, int> sumOccurrencesMap;
        sumOccurrencesMap[0] = 1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            auto it = sumOccurrencesMap.find(sum - k);
            if (it != sumOccurrencesMap.end()) {
                ans += it->second;
            }
            sumOccurrencesMap[sum]++;
        }

        return ans;
    }

    int subarraySum_BruteForce(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
#endif //ALGORITHM_CPP_560_SUBARRAYSUMEQUALK_H
