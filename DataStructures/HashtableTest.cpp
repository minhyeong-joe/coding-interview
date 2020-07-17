#include "Hashtable.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    HashTable<int, string> ht;
    ht.insert(1, "A");
    ht.insert(2, "B");
    ht.insert(11, "C");
    ht.insert(6, "D");
    ht.insert(14, "E");
    ht.insert(22, "F");
    ht.insert(21, "G");
    try
    {
        ht.insert(11, "H");
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    ht.print();
    try
    {
        cout << ht.get(5);
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    cout << ht.get(11) << endl;

    cout << endl;

    ht.remove(11);

    ht.print();

    try
    {
        ht.remove(11);
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    
    return 0;
}
