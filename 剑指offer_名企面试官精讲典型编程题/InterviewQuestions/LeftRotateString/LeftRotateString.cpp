// LeftRotateString.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include "..\Utilities\StringUtil.h"
#include <string.h>

char* LeftRotateString(char* pStr, int n)
{
    if(pStr != NULL)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 && n > 0 && n < nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;

            // ��ת�ַ�����ǰ��n���ַ�
            Reverse(pFirstStart, pFirstEnd);
            // ��ת�ַ����ĺ��沿��
            Reverse(pSecondStart, pSecondEnd);
            // ��ת�����ַ���
            Reverse(pFirstStart, pSecondEnd);
        }
    }

    return pStr;
}

// ====================���Դ���====================
void Test(char* testName, char* input, int num, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ���ܲ���
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// �߽�ֵ����
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// �߽�ֵ����
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// ³���Բ���
void Test4()
{
    Test("Test4", NULL, 6, NULL);
}

// ³���Բ���
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// ³���Բ���
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

