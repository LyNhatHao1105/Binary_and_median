#include <iostream>
#include "Header.h"

using namespace std;

void Choose(int32_t &n, int32_t* a)
{
    int8_t choose;
    cout << "Choose 1 to enters an array of integers then save that array to a binary file";
    cout << "Choose 2 to loads an array of integers from a binary file then finding the median and output to console.";
    cout << "Choose 3 to exit this program";
    cout << "Your choice: ";
    cin >> choose;

    switch (choose)
    {
    case 1:
        fread(n, a);
        fsave(n, a);
        break;
    case 2:
        fload(n, a);
        Sort_arr(n, a);
        Median(n, a);
        break;
    default:
        exit;
        break;
     }
}

void fread(int32_t& n, int32_t* a)
{
    cin >> n;
    a = new int32_t[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void fsave(int32_t n, int32_t* a)
{
    FILE* file = fopen("input.bin", "wb");
    int32_t* temp = &n;

    fwrite(temp, sizeof(n), 1, file);
    n = *temp;
    for (int i = 0; i < n; i++)
    {
        temp = &a[i];
        fread(temp, 4, 1, file);
    }
}

void fload(int32_t& n, int32_t* a)
{
    FILE* file = fopen("input.bin", "rb");
    int32_t* temp;

    fread(temp, sizeof(n), 1, file);
    n = *temp;
    for (int i = 0; i < n; i++)
    {
        fread(temp, 4, 1, file);
        a[i] = *temp;
    }
}

void Sort_arr(int32_t* a, int32_t n)
{
    int32_t temp;
    for (int i=0; i<n;i++)
        for (int j=i+1; j<n;j++)
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void Median(int32_t* a, int32_t n)
{
    if (n & 2 != 0)
        cout<< double(a[n / 2 + 1]);
    else
        cout<< (double(a[n / 2]) + a[n / 2 + 1]) / 2;
}

