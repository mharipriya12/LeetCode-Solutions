#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int current = nums[0];
    int maximum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        current = max(nums[i], current + nums[i]);
        maximum = max(maximum, current);
    }

    return maximum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(nums);

    return 0;
}
