// clock.cpp : 定义控制台应用程序的入口点。
//
// clock.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct node
{
	node* parent;
	node** child;
	short sign;//记录是第几种拨法
	short status[9];//记录加到改点时的状态

} Node;

void add(short* a,short* operation)
{
	for(short i = 0;i<9;i++)
	{
		a[i]+=operation[i];
		a[i] = a[i]%4;
	}
}
bool judge(short* a)
{
	for(short i=0;i<9;i++)
		if(a[i]!=0)
			return false;
	return true;
}
void copy(short* a,short* b)
{
	for(short i = 0;i<9;i++)
		a[i] = b[i];
}
Node* BFSTraverse(Node* node)//广度遍历
{
	//9种操作对应数组
	short operations[9][9] = 
	{
		// A  B  C D  E F  G  H  I
		{ 1, 1, 0, 1, 1, 0, 0, 0, 0},  //op1: ABDE
		{ 1, 1, 1, 0, 0, 0, 0, 0, 0},  //op2: ABC
		{ 0, 1, 1, 0, 1, 1, 0, 0, 0},  //op3: BCEF
		{ 1, 0, 0, 1, 0, 0, 1, 0, 0},  //op4: ADG
		{ 0, 1, 0, 1, 1, 1, 0, 1, 0},  //op5: BDEFH
		{ 0, 0, 1, 0, 0, 1, 0, 0, 1},  //op6: CFI
		{ 0, 0, 0, 1, 1, 0, 1, 1, 0},  //op7: DEGH
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1},  //op8: GHI
		{ 0, 0, 0, 0, 1, 1, 0, 1, 1}  //op9: EFHI
	};

	queue<Node*>q; //定义一个存放node 型元素的空队q
	q.empty();
	node->child = new Node*[9];
	short i,j;
	for(i = 0;i<9;i++)
	{
		node->child[i] = new Node();
		node->child[i]->parent = node;
		copy(node->child[i]->status,node->status); 
		node->child[i]->sign = i;
		q.push(node->child[i]);
	}
	while(q.size()>0)
	{
		Node* currentnode = q.front();
		q.pop();
		currentnode->child = new Node*[9];
		add(currentnode->status,operations[currentnode->sign]);
		for(i = 0;i<9;i++)
		{
			currentnode->child[i] = new Node();
			currentnode->child[i]->parent = currentnode;
			currentnode->child[i]->sign = i;
			copy(currentnode->child[i]->status,currentnode->status);
			q.push(currentnode->child[i]);
		}
		
		if(judge(currentnode->status))
			return currentnode;
	}
	return 0;
}
//BFSTraverse

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	short a[9];//a 输入

	for(short i = 0;i<9;i++)
		cin>>a[i];

	Node* root = new Node();
	root->parent = 0;
	for(short i = 0;i<9;i++)
		root->status[i] = a[i];

	//for(int i = 0;i<9;i++)
	//{
	//	cout<<root->status[i]<<"  ";
	//}
	//cout<<endl;

	Node* result = BFSTraverse(root);
	stack<short> s;
	while(result->parent!=0)
	{
		//cout<<result->sign+1<<"  ";
		s.push(result->sign+1);
		result = result->parent;
	}
	while(s.size()>0)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
