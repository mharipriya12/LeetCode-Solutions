#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 2)
        return n;

    int first = 1;
    int second = 2;

    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }

    return second;
}

int main() {
    int n;
    cin >> n;

    cout << climbStairs(n);

    return 0;
}
