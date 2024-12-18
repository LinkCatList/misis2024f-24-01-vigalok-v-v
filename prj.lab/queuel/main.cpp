#include <iostream>
#include "queuel.hpp"

int main () {
    QueueL q;
    q.Push(1);
    q.Push(2);
    std::cout << q.Pop() << std::endl;
    std::cout << q.Pop() << std::endl;
    for (int i = 0; i < 30; ++i) {
        q.Push(i);
    }
    std::cout << q.Empty() << std::endl;
    while (!q.Empty()) {
        auto val = q.Pop();
        std::cout << val << std::endl;
    }
}
