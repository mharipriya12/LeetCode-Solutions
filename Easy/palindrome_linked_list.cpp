#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

bool isPalindrome(ListNode* head) {
    vector<int> values;

    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }

    int left = 0;
    int right = values.size() - 1;

    while (left < right) {
        if (values[left] != values[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << (isPalindrome(head) ? "true" : "false");

    return 0;
}
