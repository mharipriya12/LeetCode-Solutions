#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,
                   vector<ListNode*>,
                   Compare> pq;

    for (ListNode* head : lists) {
        if (head != nullptr)
            pq.push(head);
    }

    ListNode dummy(0);
    ListNode* current = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();

        current->next = node;
        current = current->next;

        if (node->next != nullptr)
            pq.push(node->next);
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    ListNode* result = mergeKLists(lists);

    printList(result);

    return 0;
}
