//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_15_3SUM_H
#define ALGORITHM_CPP_15_3SUM_H

#include "leetcode.h"

class Problem15_3Sum : public Solution {
public:
    Problem15_3Sum() : Solution("15.txt") {}

private:
    void readInput(Input& input) override {
        readVec(input.firstVecInt);
    }

    void doSolve(Input input) override {
        auto ans = threeSum(input.firstVecInt);
        show(ans);
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        return threeSum_twoPointer(nums);
    }

    vector<vector<int>> threeSum_twoPointer(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const int size = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && (nums[i - 1] == nums[i])) {
                continue;
            }

            int l = i + 1;
            int r = size - 1;
            int target = -nums[i];

            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum == target) {
                    vector<int> res(0);
                    res.push_back(nums[i]);
                    res.push_back(nums[l]);
                    res.push_back(nums[r]);
                    ans.push_back(res);

                    while (l < nums.size() && nums[l] == res[1])
                        l++;
                    while (r >= 0 && nums[r] == nums[2])
                        r--;
                } else if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return ans;
    }

    // Time complexity: O(n^3) ==> TLE

    vector<vector<int>> threeSum_BruteForce(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        unordered_map<long, bool> m;
        const int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size - 1; ++j) {
                for (int k = j + 1; k < size; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        int h = hash(nums[i], nums[j], nums[k]);
                        if (m.count(h) == 0) {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            m.insert(make_pair(h, true));
                        }
                    }
                }
            }
        }
        return ans;
    }

    long hash(uint64_t a, uint64_t b, uint64_t c) {
        return a + (b << 21) + (c << 24);
    }
};

#endif //ALGORITHM_CPP_15_3SUM_H
