#ifndef LinkListDSSV_h
#define LinkListDSSV_h
#include <iostream>

struct Data {
	int mssv;
	std::string ten;
	std::string lop;
	double dtb;
	int hanhkiem;
};

struct Node
{
	Data data;
	Node* next;
};

struct LinkList
{
	Node* Head;
	Node* Tail;
};

Node* CreateNode(Data input);
void CreateList(LinkList& l);
void AddHead(LinkList& l, Node* node);
void AddTail(LinkList& l, Node* node);
void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch);
int RemoveHead(LinkList& l);
int RemoveTail(LinkList& l);
int RemoveInNodeSearch(LinkList& l, Node* head);
Node* SearchNode(LinkList l, int index);
void ArrangeList(LinkList& l);
void SwapNode(Node* node1, Node* node2);
void DeleteList(LinkList& l);
void PrintList(LinkList l);
void PrintListWithCondition(LinkList l, std::string input);
#endif // !LinkListDSSV_h

