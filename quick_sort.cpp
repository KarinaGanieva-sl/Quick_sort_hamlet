#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>

void quick_sort(char** text, int left, int right)
{
    assert(text);
    assert(std::isfinite(left));
    assert(std::isfinite(right));
    if(left >= right)
        return;
    char* pivot = text[(left + right) / 2];
    int i = left;
    int j = right;
    while(i <= j)
    {
        while(strcmp(text[i], pivot) < 0)
            i++;
        while(strcmp(text[j], pivot) > 0)
            j--;
        if (i <= j)
        {
            char* a = text[i];
            text[i] = text[j];
            text[j] = a;
            i++;
            j--;
        }
    }
    quick_sort(text, left, j);
    quick_sort(text, i, right);
}


void quick_sort(char** text, int array_size)
{
    assert(text);
    assert(std::isfinite(array_size));
    quick_sort(text, 0, array_size - 1);
}

static int string_compare(char* a, char* b)
{
    assert(a);
    assert(b);
    size_t a_length = strlen(a);
    size_t b_length = strlen(b);
    bool key = false;
    int length = a_length;
    if(a_length > b_length)
    {
        key = true;
        length = b_length;
    }
    for(int i = 1; i <= length; ++i)
    {
        if(a[a_length - i] < b[b_length - i])
            return -1;
        if(a[a_length - i] > b[b_length - i])
            return 1;
    }
    if(a_length == b_length)
        return 1;
    return key ? 1 : -1;
}

void quick_sort_rev(char** text, int left, int right)
{
    assert(text);
    assert(std::isfinite(left));
    assert(std::isfinite(right));
    if(left >= right)
        return;
    char* pivot = text[(left + right) / 2];
    int i = left;
    int j = right;
    while(i <= j)
    {
        while(string_compare(text[i], pivot) < 0)
            i++;
        while(string_compare(text[j], pivot) > 0)
            j--;
        if (i <= j)
        {
            char* a = text[i];
            text[i] = text[j];
            text[j] = a;
            i++;
            j--;
        }
    }
    quick_sort(text, left, j);
    quick_sort(text, i, right);
}

void quick_sort_rev(char** text, int array_size)
{
    assert(text);
    assert(std::isfinite(array_size));
    quick_sort_rev(text, 0, array_size - 1);
}


