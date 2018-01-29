// TwoNumbersWithSum.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"

bool FindNumbersWithSum(int data[], int length, int sum, 
                        int* num1, int* num2)
{
    bool found = false;
    if(length < 1 || num1 == NULL || num2 == NULL)
        return found;

    int ahead = length - 1;
    int behind = 0;

    while(ahead > behind)
    {
        long long curSum = data[ahead] + data[behind];

        if(curSum == sum)
        {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        }
        else if(curSum > sum)
            ahead --;
        else
            behind ++;
    }

    return found;
}

// ====================���Դ���====================
void Test(char* testName, int data[], int length, int sum, bool expectedReturn)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    int num1, num2;
    int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
    if(result == expectedReturn)
    {
        if(result)
        {
            if(num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("Failed. \n");
        }
        else
            printf("Passed. \n");
    }
    else
        printf("Failed. \n");
}

// ���ں�Ϊs���������֣�����������λ��������м�
void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// ���ں�Ϊs���������֣�����������λ�����������
void Test2()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// �����ں�Ϊs����������
void Test3()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// ³���Բ���
void Test4()
{
    Test("Test4", NULL, 0, 0, false);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

