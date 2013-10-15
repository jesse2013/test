/*
 * =====================================================================================
 *
 *       Filename:  BiTree.h
 *
 *    Description:  BiTree transver implementation
 *
 *        Version:  1.0
 *        Created:  10/12/2013 04:35:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jesse chen (jianglu), jianglu.chen@gmail.com
 *        Company:  sjtu
 *
 * =====================================================================================
 */

#ifndef _BITTREE_H
#define _BITREE_H

template <class DataType>
class BiTree;

template <class DataType>
class TreeNode{
public:
	TreeNode():lchild(),rchild(){}
	friend class BiTree<DataType>;
private:
	DataType data;
	TreeNode *lchild,*rchild;
};

template <class DataType>
class BiTree{
public:
	void CreateBiTree();            // 创建根节点 --主过程
	void CreateBiTree(TreeNode<DataType>* &p);   //创建根节点 --主过程
	void PreROrderTraverse();  //递归 -- 先序遍历二叉树 --主过程
	void PreROrderTraverse(TreeNode<DataType>* p);  //递归 -- 先序遍历二叉树 --子过程
	void InROrderTraverse();  //递归 -- 中序遍历二叉树 --主过程
	void InROrderTraverse(TreeNode<DataType>* p);  //递归 -- 中序遍历二叉树 --子过程
	void PosROrderTraverse();  //递归 -- 后序遍历二叉树 --主过程
	void PosROrderTraverse(TreeNode<DataType>* p);  //递归 -- 后序遍历二叉树 --子过程
	void PreOrderTraverse();  //非递归 -- 前序遍历二叉树 
	void InOrderTraverse();  //非递归 -- 中序遍历二叉树
	void PostOrderTraverse();  //非递归 -- 后序遍历二叉树
	void levelOrderTraverse();  //非递归 -- 后序遍历二叉树
private:
	TreeNode<DataType>* root;   //树根
	DataType temp;   //代表元素为空的符号

};

#endif
