#include "List.h"

int main() {
    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.print();

    list.pop_back();
    list.pop_front();

    list.print();

    std::cin.get();

    return 0;
}