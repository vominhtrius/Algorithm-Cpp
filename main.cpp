#include "problems/leetcode/3_lengthOfLongestSubstring.h"
#include "problems/leetcode/167_twoSum_II.h"
#include "problems/leetcode/15_3Sum.h"
#include "problems/leetcode/242_isAnagram.h"
#include "problems/leetcode/54_spiralOrder.h"
#include "problems/leetcode/88_mergeSortedArray.h"

Solution *getSolution() {
    return new Problem88_mergeSortedArray();
}

int main() {
    Solution *solution = getSolution();

#ifdef LOCAL
    string filePath = solution->getInputPath();
    FILE *file = freopen(solution->getInputPath().c_str(), "r+", stdin);
    if (file == nullptr) {
        cout << filePath << " NOT FOUND" << endl;
    }

//    freopen("../OUTPUT.txt", "w", stdout);
#endif

    solution->solve();
    return 0;
}
