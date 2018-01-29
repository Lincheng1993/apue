// ReverseWordsInSentence.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include "..\Utilities\StringUtil.h"
#include <string>

char* ReverseSentence(char *pData)
{
    if(pData == NULL)
        return NULL;

    char *pBegin = pData;

    char *pEnd = pData;
    while(*pEnd != '\0')
        pEnd ++;
    pEnd--;

    // ��ת��������
    Reverse(pBegin, pEnd);

    // ��ת�����е�ÿ������
    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')
        {
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
        {
            pEnd ++;
        }
    }

    return pData;
}

// ====================���Դ���====================
void Test(char* testName, char* input, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ���ܲ��ԣ��������ж������
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// ³���Բ���
void Test3()
{
    Test("Test3", NULL, NULL);
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
    Test("Test4", "", "");
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

