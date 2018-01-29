// MinNumberInRotatedArray.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include<exception>

int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        throw new std::exception("Invalid parameters");
 
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while(numbers[index1] >= numbers[index2])
    {
        // ���index1��index2ָ�����ڵ���������
        // ��index1ָ���һ����������������һ�����֣�
        // index2ָ��ڶ���������ĵ�һ�����֣�Ҳ���������е���С����
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
 
        // ����±�Ϊindex1��index2��indexMidָ�������������ȣ�
        // ��ֻ��˳�����
        indexMid = (index1 + index2) / 2;
        if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
            return MinInOrder(numbers, index1, index2);

        // ��С���ҷ�Χ
        if(numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }
 
    return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
    int result = numbers[index1];
    for(int i = index1 + 1; i <= index2; ++i)
    {
        if(result > numbers[i])
            result = numbers[i];
    }

    return result;
}

// ====================���Դ���====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == NULL)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    // �������룬��������������һ����ת
    int array1[] = {3, 4, 5, 1, 2};
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // ���ظ����֣������ظ������ָպõ���С������
    int array2[] = {3, 4, 5, 1, 1, 2};
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
    int array3[] = {3, 4, 5, 1, 2, 2};
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
    int array4[] = {1, 0, 1, 1, 1};
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
    int array5[] = {1, 2, 3, 4, 5};
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // ������ֻ��һ������
    int array6[] = {2};
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // ����NULL
    Test(NULL, 0, 0);

    return 0;
}

