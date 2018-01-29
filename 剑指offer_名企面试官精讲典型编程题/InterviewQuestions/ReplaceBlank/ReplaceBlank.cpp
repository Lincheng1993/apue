// ReplaceBlank.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include <string>

/*length Ϊ�ַ�����string��������*/
void ReplaceBlank(char string[], int length)
{
    if(string == NULL && length <= 0)
        return;

    /*originalLength Ϊ�ַ���string��ʵ�ʳ���*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        ++ originalLength;

        if(string[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfNew --] = '0';
            string[indexOfNew --] = '2';
            string[indexOfNew --] = '%';
        }
        else
        {
            string[indexOfNew --] = string[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}

void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        printf("passed.\n");
    else if(expected == NULL && string != NULL)
        printf("failed.\n");
    else if(strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// ����NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}

