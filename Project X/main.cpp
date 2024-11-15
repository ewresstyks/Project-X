#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List list;
    list.push_front(3);
    list.push_back(24);
    cout << "First list: ";
    list.show();
    list.reverse();
    cout << "New list: ";
    list.show();
    list.pop_back();
    cout << "New2: ";
    list.show();
    list.pop_front();
    cout << "New3: ";
    list.show();
    list.push_back(24);
    list.push_back(47);
    list.push_back(72);
    cout << "New: ";
    list.show();
    List list2 = list;
    cout << "Copy: ";
    list2.show();
    list.clear();
    cout << "Clear: ";
    list.show();
    return 0;
}