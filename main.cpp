#include <iostream>
#include <cassert>
#include <sys\stat.h>
#include <fstream>
#include <cmath>
#include "quick_sort.h"
#include "tests.h"

using namespace std;

char** readText(char* filename, int &length)
{
    assert(filename != NULL);
    assert(isfinite(length));
    string str = "";
    ifstream file(filename, ifstream::in);
    if(!file)
    {
        cerr << "Can't open input file";
        exit(-1);
    }
    int ind = 0;
    char** text = new char*[50];
    while (ind < 50 && getline(file, str))
    {
        text[ind] = new char[strlen(str.c_str())];
        if(!strcpy(text[ind], str.c_str()))
        {
            cerr << "Can't convert c_str to char *";
            exit(-1);
        }
        ind++;
    }
    file.close();
    length = ind;
    return text;
}

void writeText(string filename, char** text, size_t length)
{
    assert(text);
    assert(isfinite(length));
    ofstream fout;
    fout.open(filename);
    if(!fout)
    {
        cerr << "Can't open output file";
        exit(-1);
    }
    for(size_t i = 0; i < length; ++i)
        fout << text[i] << '\n';
    fout.close();
}

void test_all()
{
    test_quick_sort();
    test_quick_sort_rev();
}

char** init_text_copy(char** text, size_t length)
{
    assert(text);
    assert(isfinite(length));
    char** text_copy = new char*[length];
    for(size_t i = 0; i < length; ++i)
        text_copy[i] = text[i];
    return text_copy;
}

int main(int argc, char * argv[]) {
    if(argc != 2)
    {
        cout << "Wrong number of input arguments. Check if you entered input filename!";
        return 1;
    }
    int length = 0;
    char** text = readText(argv[1], length);
    char** copy_1 = init_text_copy(text, length);
    quick_sort(copy_1, length);
    writeText("../output.txt", copy_1, length);
    for(size_t i = 0; i < length; ++i)
        delete[] copy_1[i];
    delete[] copy_1;
    char** copy_2 = init_text_copy(text, length);
    quick_sort_rev(copy_2, length);
    writeText("../output_rev.txt", copy_2, length);
    for(size_t i = 0; i < length; ++i)
        delete[] copy_2[i];
    delete[] copy_2;
    writeText("../output_origin.txt", text, length);
    for(size_t i = 0; i < length; ++i)
        delete[] text[i];
    delete[] text;
    return 0;
}
