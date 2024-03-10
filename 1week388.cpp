#include <iostream>
#include <vector>
#include <algorithm> // Include for sort function
#include <numeric>   // Include for accumulate function

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        
        std::sort(capacity.begin(), capacity.end());
        int sum = std::accumulate(apple.begin(), apple.end(), 0);
        int ans = 0;
        
        for (int i = m - 1; i >= 0; i--) {
            if (sum <= 0) break;
            ans++;
            sum -= capacity[i];
        }
        
        return ans;
    }
};

int main() {
    Solution solution;

    std::vector<int> apple1 = {1, 3, 2};
    std::vector<int> capacity1 = {4, 3, 1, 5, 2};
    std::cout << "Output for apple1: " << solution.minimumBoxes(apple1, capacity1) << std::endl;

    std::vector<int> apple2 = {5, 5, 5};
    std::vector<int> capacity2 = {2, 4, 2, 7};
    std::cout << "Output for apple2: " << solution.minimumBoxes(apple2, capacity2) << std::endl;

    return 0;
}
