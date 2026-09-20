#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int result = n;

    for (int i = 0; i < n; i++)
        result ^= i ^ nums[i];

    return result;
}

int main() {
    vector<int> nums = {3, 0, 1};

    cout << missingNumber(nums);

    return 0;
}
