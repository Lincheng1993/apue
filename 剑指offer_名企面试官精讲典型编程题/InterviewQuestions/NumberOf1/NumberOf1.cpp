// NumberOf1.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

// ====================����һ====================
int NumberOf1(unsigned int n);

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
    int number = 0;

    for(unsigned int i = 1; i <= n; ++ i)
        number += NumberOf1(i);

    return number;
}

int NumberOf1(unsigned int n)
{
    int number = 0;
    while(n)
    {
        if(n % 10 == 1)
            number ++;

        n = n / 10;
    }

    return number;
}

// ====================������====================
int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int NumberOf1Between1AndN_Solution2(int n)
{
    if(n <= 0)
        return 0;

    char strN[50];
    sprintf(strN, "%d", n);

    return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
    if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;

    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));

    if(length == 1 && first == 0)
        return 0;

    if(length == 1 && first > 0)
        return 1;

    // ����strN��"21345"
    // numFirstDigit������10000-19999�ĵ�һ��λ��1����Ŀ
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = PowerBase10(length - 1);
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;

    // numOtherDigits��01346-21345���˵�һλ֮�����λ��1����Ŀ
    int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
    // numRecursive��1-1345��1����Ŀ
    int numRecursive = NumberOf1(strN + 1);

    return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n)
{
    int result = 1;
    for(unsigned int i = 0; i < n; ++ i)
        result *= 10;

    return result;
}

// ====================���Դ���====================
void Test(char* testName, int n, int expected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);
    
    if(NumberOf1Between1AndN_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n"); 
    
    if(NumberOf1Between1AndN_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n"); 

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test();

    return 0;
}

