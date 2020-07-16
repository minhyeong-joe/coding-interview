#include "Stack.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Stack<int> s;
    s.push(3);
    s.push(5);
    s.push(1);
    while (!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    s.push(8);
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.size() << endl;
    s.pop();
    cout << s.size() << endl;
    try
    {
        s.pop();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}
