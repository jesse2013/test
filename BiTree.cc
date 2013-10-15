/*
 * =====================================================================================
 *
 *       Filename:  BiTree.c
 *
 *    Description:  BiTree source file
 *
 *        Version:  1.0
 *        Created:  10/15/2013 06:47:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jesse chen (jianglu), jianglu.chen@gmail.com
 *        Company:  sjtu
 *
 * =====================================================================================
 */
#include <stack>
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;


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

template <class DataType>
void BiTree<DataType>::CreateBiTree(){            // 创建根节点 --主过程
	cout<<"请输入代表元素为空的符号";
	cin>>temp;
	CreateBiTree(root);
}
template <class DataType>
void BiTree<DataType>::CreateBiTree(TreeNode<DataType>* &p){   //创建根节点 --主过程
	DataType tmpdata;
	cout<<"请输入数据:"<<endl;
	cin>>tmpdata;
	if(tmpdata==temp){p = NULL;
	}else{
		if(!(p=(TreeNode<DataType>*)malloc(sizeof(TreeNode<DataType>)))) 
			exit(-1);
		else{
			p->data = tmpdata;
			CreateBiTree(p->lchild);
			CreateBiTree(p->rchild);
		}
	}
}
template <class DataType>
void BiTree<DataType>::PreROrderTraverse(){  //递归 -- 先序遍历二叉树 --主过程
	PreROrderTraverse(root);
}
template <class DataType>
void BiTree<DataType>::PreROrderTraverse(TreeNode<DataType>* p){  //递归 -- 先序遍历二叉树 --子过程
	if(p!=NULL){
		cout<<p->data<<" ";
		PreROrderTraverse(p->lchild);
		PreROrderTraverse(p->rchild);
	}
}
template <class DataType>
void BiTree<DataType>::InROrderTraverse(){  //递归 -- 中序遍历二叉树 --主过程
	InROrderTraverse(root);
}

template <class DataType>
void BiTree<DataType>::InROrderTraverse(TreeNode<DataType>* p){  //递归 -- 中序遍历二叉树 --子过程
	if(p!=NULL){
		InROrderTraverse(p->lchild);
		cout<<p->data<<" ";
		InROrderTraverse(p->rchild);
	}
}
template <class DataType>
void BiTree<DataType>::PosROrderTraverse(){  //递归 -- 后序遍历二叉树 --主过程
	PosROrderTraverse(root);
}
template <class DataType>
void BiTree<DataType>::PosROrderTraverse(TreeNode<DataType>* p){  //递归 -- 后序遍历二叉树 --子过程
	if(p!=NULL){
		PostOrderTraverse(p->lchild);
		PostOrderTraverse(p->rchild);
		cout<<p->data<<" ";
	}
}
template <class DataType>
void BiTree<DataType>::PreOrderTraverse(){  //非递归 -- 前序遍历二叉树 
	stack<TreeNode<DataType>* > st;
	TreeNode<DataType>* p;
	p = root;
	while(p || !st.empty()){
		if(p){
			cout<<p->data<<" ";
			st.push(p);
			p = p->lchild;
		}else{
			p = st.top();
			st.pop();
			p = p->rchild;
		}
	}
}
template <class DataType>
void BiTree<DataType>::InOrderTraverse(){  //非递归 -- 中序遍历二叉树
	stack<TreeNode<DataType>* > st;
	TreeNode<DataType>* p;
	p = root;
	while(p || !st.empty()){
		if(p){
			st.push(p);
			p = p->lchild;
		}else{
			p = st.top();
			st.pop();
			cout<<p->data<<" ";
			p = p->rchild;
		}
	}
}
template <class DataType>
void BiTree<DataType>::PostOrderTraverse(){  //非递归 -- 后序遍历二叉树
	stack<TreeNode<DataType>* > st;
	TreeNode<DataType>* p;
	TreeNode<DataType>* r;
	p = root;
	while(p || !st.empty()){
		if(p){
			st.push(p);
			p = p->lchild;
		}else{
			p = st.top();
			if(p){
				if(!p->rchild || p->rchild ==r){
					cout<<p->data;
					r = p;
					p = NULL;
					st.pop();
				}else{
					p = p->rchild;
				}
			}

		}
	}
}
template <class DataType>
void BiTree<DataType>::levelOrderTraverse(){  //非递归 -- 后序遍历二叉树
	queue<TreeNode<DataType> *> qu;
	TreeNode<DataType> * p;
	qu.push(root);
	while(!qu.empty()){
		p = qu.front();
		qu.pop(); 
		cout<<p->data<<" ";
		qu.push(p->lchild);
		qu.push(p->rchild);
	}
	return;
}

int main(void){
	BiTree<char> my;
	my.CreateBiTree();
	my.PreROrderTraverse();
	cout<<endl;
	my.PreOrderTraverse();
	cout<<endl;
	my.InROrderTraverse();
	cout<<endl;
	my.InOrderTraverse();
	cout<<endl;
	my.PosROrderTraverse();
	cout<<endl;
	my.PostOrderTraverse();

	cout<<endl;
	my.levelOrderTraverse();
	return 0;
}

