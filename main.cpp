#include <iostream>
#include <map>
#include <iterator>

using namespace std;

#include "dictionary.hpp"

int main()
{
    Dictionary *d = new Dictionary("../dictionary.txt");

    while (d->menu() != 4) {
    }

    delete d;

    return 0;

}