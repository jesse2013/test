/*
 * =====================================================================================
 *
 *       Filename:  transver.cc
 *
 *    Description:  transverse main 
 *
 *        Version:  1.0
 *        Created:  10/15/2013 09:04:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jesse chen (jianglu), jianglu.chen@gmail.com
 *        Company:  sjtu
 *
 * =====================================================================================
 */

#include "BiTree.h"
#include <iostream>

using namespace std;

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


