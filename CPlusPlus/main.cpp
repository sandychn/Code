#include "../LeetCode/leetcode_header.hpp"

struct Test {
    ~Test() {
        cout << "deconstructor\n";
    }
};

void foo(Test& test) {
    cout << "foo\n";
}

int main() {
    foo(*unique_ptr<Test>(new Test));
}