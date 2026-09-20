#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int index = 0;

    for (int num : nums) {
        if (num != 0) {
            nums[index] = num;
            index++;
        }
    }

    while (index < nums.size()) {
        nums[index] = 0;
        index++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    for (int num : nums)
        cout << num << " ";

    return 0;
}
