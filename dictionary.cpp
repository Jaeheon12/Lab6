#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#include "dictionary.hpp"

Dictionary::Dictionary() {

}

Dictionary::Dictionary(string path) {
    ifstream fin{path};
    if (!fin.is_open()) {
        cout << "Failed to open a file : \"" << path << "\"" << endl;
        exit(1);
    }
    directory = path;

    string word = "";
    string def = "";
    string wordInDef = "";

    while (fin >> word) {
        getline(fin, def);
        dictionary.insert(make_pair(word, def));
    }

    fin.close();
}

Dictionary::~Dictionary() {

}

int Dictionary::menu() {

    cout << "Menu: " << endl;
    cout << "1. Print dictionary" << endl;
    cout << "2. Find word definition" << endl;
    cout << "3. Enter new word and definition" << endl;
    cout << "4. Exit" << endl;

    int choice = 0;
    cin.clear();
    cin >> choice;
    if (choice == 1) {
        printDict();
        return 1;
    }
    else if (choice == 2) {
        cout << "Enter a word to be found : ";
        string str = "";
        cin >> str;
        findDef(str);
        return 2;
    }
    else if (choice == 3) {
        cout << "Enter a new word : ";
        string str = "";
        cin >> str;
        if (!findDef(str)) {
            string wordDef = "";
            cout << "enter a defnition : " << endl;
            //cin >> wordDef;
            cin.ignore();
            getline(cin, wordDef);
            enterNewDef(str, wordDef);
        }
        return 3;
    }
    else if (choice == 4) {
        writeDict(directory);
        cout << "Terminate Program" << endl;
        return 4;
    }
    return 5;
}

void Dictionary::printDict() {
    for(map<string, string>::const_iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
        cout << it->first << ":"<< it->second << "\n";
    }
}

bool Dictionary::findDef(string word) {
    if (dictionary[word] == "") {
        cout << "The word [" << word << "] doesn't exist." << endl;
        return false;
    }
    else {
        cout << dictionary[word] << endl;
        return true;
    }
}

void Dictionary::enterNewDef(string word, string def) {
    dictionary.insert(dictionary.begin() , map<string, string>::value_type(word, def));
    dictionary[word] = def;
    cout << "The new word and defnition has been added to the dictionary." << endl;
}

void Dictionary::writeDict(string path) {
    ofstream fout{path};
    if (!fout.is_open()) {
        cout << "Failed to open a file : \"" << path << "\"" << endl;
        exit(1);
    }
    cout << "writing dictionary.." << path << endl;

    for(map<string, string>::const_iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
        fout << it->first << " "<< it->second << "\n";
    }

    fout.close();
}