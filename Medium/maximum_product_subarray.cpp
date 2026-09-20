#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int currentMax = nums[0];
    int currentMin = nums[0];
    int answer = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(currentMax, currentMin);

        currentMax = max(nums[i], currentMax * nums[i]);
        currentMin = min(nums[i], currentMin * nums[i]);

        answer = max(answer, currentMax);
    }

    return answer;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};

    cout << maxProduct(nums);

    return 0;
}
