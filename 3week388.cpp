/*
You are given an array arr of size n consisting of non-empty strings.

Find a string array answer of size n such that:

answer[i] is the shortest substring of arr[i] that does not occur as a substring in any other string in arr. If multiple such substrings exist, answer[i] should be the lexicographically smallest. And if no such substring exists, answer[i] should be an empty string.
Return the array answer.

 

Example 1:

Input: arr = ["cab","ad","bad","c"]
Output: ["ab","","ba",""]
Explanation: We have the following:
- For the string "cab", the shortest substring that does not occur in any other string is either "ca" or "ab", we choose the lexicographically smaller substring, which is "ab".
- For the string "ad", there is no substring that does not occur in any other string.
- For the string "bad", the shortest substring that does not occur in any other string is "ba".
- For the string "c", there is no substring that does not occur in any other string.
Example 2:

Input: arr = ["abc","bcd","abcd"]
Output: ["","","abcd"]
Explanation: We have the following:
- For the string "abc", there is no substring that does not occur in any other string.
- For the string "bcd", there is no substring that does not occur in any other string.
- For the string "abcd", the shortest substring that does not occur in any other string is "abcd".
 

Constraints:

n == arr.length
2 <= n <= 100
1 <= arr[i].length <= 20
arr[i] consists only of lowercase English letters
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size(); // Number of strings in the input array

        // Initialize a map to store total counts of substrings across all strings
        map<string, int> total;

        // Initialize a vector of maps to store counts of substrings for each string
        vector<map<string, int>> strings(n);

        // Initialize the vector to store the answer substrings
        vector<string> ans(n);

        // Loop through each string in the input array
        for (int i = 0; i < n; i++) {
            string str = arr[i];
            int m = str.length();

            // Generate all possible substrings of the current string
            for (int j = 0; j < m; j++) {
                string s = "";
                for (int k = j; k < m; k++) {
                    s += str[k];
                    total[s]++; // Increment count of substring in total map
                    strings[i][s]++; // Increment count of substring for current string
                }
            }
        }

        // Loop through each string in the input array again
        // Loop through each string in the input array again
for (int i = 0; i < n; i++) {
    // Check each substring of the current string
    for (const auto& pair : strings[i]) {
        string str = pair.first;
        int cnt = pair.second;

        // If the count of the substring equals the total count,
        // it means the substring doesn't occur in any other string
        if (total.at(str) == cnt) {
            // Update answer string if it's empty or shorter than the current substring
            if (ans[i].empty() || ans[i].length() > str.length())
                ans[i] = str;
            // If the lengths are equal, update answer string if the current substring is lexicographically smaller
            else if (ans[i].length() == str.length() && ans[i] > str)
                ans[i] = str;
        }
    }
}


        // Return the vector of answer substrings
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<string> arr1 = {"cab", "ad", "bad", "c"};
    vector<string> answer1 = sol.shortestSubstrings(arr1);
    cout << "Test Case 1 Output: ";
    for (const string& str : answer1) {
        cout << str << " ";
    }
    cout << endl;

    // Test case 2
    vector<string> arr2 = {"abc", "bcd", "abcd"};
    vector<string> answer2 = sol.shortestSubstrings(arr2);
    cout << "Test Case 2 Output: ";
    for (const string& str : answer2) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}

