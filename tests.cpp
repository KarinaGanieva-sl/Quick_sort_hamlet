//
// Created by user on 07.10.2020.
//

#include "quick_sort.h"
#include <cstring>
#include <iostream>
using namespace std;

void test_quick_sort()
{
    string a = "Claudius, King of Denmark";
    string b = "Marcellus, Officer";
    string c = "Hamlet, son to the former, and nephew to the present king.";
    string d = "Polonius, Lord Chamberlain.";
    char ** text = new char*[4];
    text[0] = &a[0];
    text[1] = &b[0];
    text[2] = &c[0];
    text[3] = &d[0];
    quick_sort(text, 4);
    for(int i = 0; i < 4; ++i)
        std::cout << text[i] <<'\n';
    //text = get_strings_2();

    a = "aaaaaaa";
    b = "bbbbbb";
    c = "ddddddddd";
    d = "uu";
    text = new char*[4];
    text[0] = &a[0];
    text[1] = &b[0];
    text[2] = &c[0];
    text[3] = &d[0];
    quick_sort(text, 4);
    for(int i = 0; i < 4; ++i)
        std::cout << text[i] <<'\n';
}

void test_quick_sort_rev()
{
    string a = "Claudius, King of Denmark";
    string b = "Marcellus, Officer";
    string c = "Hamlet, son to the former, and nephew to the present king.";
    string d = "Polonius, Lord Chamberlain.";
    char ** text = new char*[4];
    text[0] = &a[0];
    text[1] = &b[0];
    text[2] = &c[0];
    text[3] = &d[0];
    quick_sort_rev(text, 4);
    for(int i = 0; i < 4; ++i)
        std::cout << text[i] <<'\n';
    //text = get_strings_2();

    a = "aaaaaaa";
    b = "bbbbbb";
    c = "ddddddddd";
    d = "uu";
    text = new char*[4];
    text[0] = &a[0];
    text[1] = &b[0];
    text[2] = &c[0];
    text[3] = &d[0];
    quick_sort_rev(text, 4);
    for(int i = 0; i < 4; ++i)
        std::cout << text[i] <<'\n';
}
