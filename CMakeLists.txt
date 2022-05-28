cmake_minimum_required(VERSION 3.20)
project(Algorithm_Cpp)

set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(LOCAL=1)


add_executable(Algorithm_Cpp main.cpp problems/leetcode/leetcode.h problems/leetcode/threeSum.cpp problems/leetcode/167_twoSum_II.h problems/leetcode/3_lengthOfLongestSubstring.h problems/leetcode/15_3Sum.h problems/leetcode/242_isAnagram.h problems/leetcode/54_spiralOrder.h problems/leetcode/88_mergeSortedArray.h problems/leetcode/template.h)
