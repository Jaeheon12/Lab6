//
// Created by jaeheon on 2019-02-26.
//

#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

class Dictionary {
private:
    map<string, string> dictionary;
    string directory;

    void printDict();
    bool findDef(string word);
    void enterNewDef(string word, string def);
    void writeDict(string path);

public:
    Dictionary();
    Dictionary(string path);
    virtual ~Dictionary();

    int menu();
};


#endif //LAB6_DICTIONARY_HPP
