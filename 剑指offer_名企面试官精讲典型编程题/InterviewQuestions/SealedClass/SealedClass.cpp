// SealedClass.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"

// ====================����һ====================
class SealedClass1
{
public:
    static SealedClass1* GetInstance() 
    {
        return new SealedClass1();
    }
 
    static void DeleteInstance( SealedClass1* pInstance)
    {
        delete pInstance;
    }
 
private:
    SealedClass1() {}
    ~SealedClass1() {}
};

// �����ͼ��SealedClass1�̳г��µ����ͣ�
// ���ᵼ�±������
/*
class Try1 : public SealedClass1
{
public:
    Try1() {}
    ~Try1() {}
};
*/

// ====================������====================
template <typename T> class MakeSealed
{
    friend T;
 
private:
    MakeSealed() {}
    ~MakeSealed() {}
};
 
class SealedClass2 : virtual public MakeSealed<SealedClass2>
{
public:
    SealedClass2() {}
    ~SealedClass2() {}
};

// �����ͼ��SealedClass1�̳г��µ����ͣ�
// ���ᵼ�±������
/*
class Try2 : public SealedClass2
{
public:
    Try2() {}
    ~Try2() {}
};
*/

int _tmain(int argc, _TCHAR* argv[])
{
    return 0;
}

