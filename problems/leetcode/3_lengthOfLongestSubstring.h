//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_3_LENGTHOFLONGESTSUBSTRING_H
#define ALGORITHM_CPP_3_LENGTHOFLONGESTSUBSTRING_H
#include "leetcode.h"

//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Problem3_LengthOfLongestSubstring : public Solution{
public:
    Problem3_LengthOfLongestSubstring() : Solution("3.txt") {}

private:
    void readInput(Input& input) override {
        cin >> input.firstStr;
    }

    void doSolve(Input input) override {
        int ans = lengthOfLongestSubstring(input.firstStr);
        show(ans);
    }

private:
    int lengthOfLongestSubstring(string s) {
        char c[256] = {0};

        int i = 0, j = 0;
        int ans = 0;

        const int len = s.length();
        // nếu c[s[j]] = 0 => tang c[s[j]]
        // Nguọcw lại:
        // Tính kết quả:
        // di chuyển i và giảm c[s[i]] cho đến khi c[s[j]] = 0

        while (j < len) {
            if (c[s[j]] == 0) {
                c[s[j]]++;
                j++;
            } else {
                ans = std::max(ans, j - i);
                while (c[s[j]] > 0) {
                    c[s[i]]--;
                    i++;
                }
            }
        }

        if (len > 0 && c[s[len - 1]] == 1) {
            ans = std::max(ans, len - i);
        }

        return ans;
    }
};
#endif //ALGORITHM_CPP_3_LENGTHOFLONGESTSUBSTRING_H
