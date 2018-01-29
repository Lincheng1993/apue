// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#pragma once

#include <vector>

struct TreeNode 
{
    int                    m_nValue;    
    std::vector<TreeNode*>    m_vChildren;    
};

__declspec( dllexport ) TreeNode* CreateTreeNode(int value);
__declspec( dllexport ) void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
__declspec( dllexport ) void PrintTreeNode(TreeNode* pNode);
__declspec( dllexport ) void PrintTree(TreeNode* pRoot);
__declspec( dllexport ) void DestroyTree(TreeNode* pRoot);
