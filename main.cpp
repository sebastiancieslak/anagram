//Written by
//Sebastian Cieslak
//09.2017

#include <iostream>
#include <fstream>

using namespace std;

bool compare(string input, string line, int length);

int main()
{
    ifstream dictionary("slowa.txt");

    if(dictionary.is_open()) cout << "Ready..." << endl;
    else return 1;

    string input;

    cout << "Input your anagram (max 15 letters):" << endl;
    cin >> input;

    cout << endl;
    cout << "Found words are:" << endl;

    short int length;
    length = input.length();

    if(length > 15) return 2;

    string line;

    while(getline(dictionary,line))
    {
        if(length == line.length())
        {
            if(compare(input, line, length)) cout << line << endl;
        }
    }

    cout << endl;
    cout << "Thanks for use!" << endl;

    dictionary.close();

    return 0;
}

bool compare(string input, string line, int length)
{
    int tab[length];
    for(int k = 0; k < length; k++) tab[k] = 16;
    bool flag = false;
    int index = 0;

    for(int i = 0; i < length; i++)             //loop on inputed anagram
    {
        for(int j = 0; j < length; j++)         //loop on line for every letter of anagram
        {
            flag = false;
            for(int l = 0; l < index; l++)     //checking
                if(tab[l] == j) flag = true;

            if(flag == false && input[i] == line[j])
            {
                tab[index] = j;
                ++index;
                break;
            }
        }
    }

    if(tab[length-1] != 16) return true;
    else return false;
}
