// NumberOf1InBinary.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"

int NumberOf1_Solution1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            count ++;

        flag = flag << 1;
    }

    return count;
}

int NumberOf1_Solution2(int n)
{
    int count = 0;

    while (n)
    {
        ++ count;
        n = (n - 1) & n;
    }

    return count;
}

void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);
    if(actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if(actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
    // ����0���ڴ��������0
    Test(0, 0);

    // ����1���ڴ��������1
    Test(1, 1);

    // ����10���ڴ��������2
    Test(10, 2);

    // ����0x7FFFFFFF���ڴ��������31
    Test(0x7FFFFFFF, 31);

    // ����0xFFFFFFFF�����������ڴ��������32
    Test(0xFFFFFFFF, 32);

    // ����0x80000000�����������ڴ��������1
    Test(0x80000000, 1);

    return 0;
}

