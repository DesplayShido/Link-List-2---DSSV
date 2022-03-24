#include "LinkListDSSV.h"
#include <iostream>

using namespace std;

Node* CreateNode(Data input)
{
    Node* node = new Node;
    node->data.mssv = input.mssv;
    node->data.ten = input.ten;
    node->data.lop = input.lop;
    node->data.dtb = input.dtb;
    node->data.hanhkiem = input.hanhkiem;
    node->next = NULL;
    return node;
}

void CreateList(LinkList& l)
{
    l.Head = l.Tail = NULL;
}

void AddHead(LinkList& l, Node* node)
{
    if (l.Head == NULL) {
        l.Head = l.Tail = node;
    }
    else {
        node->next = l.Head;
        l.Head = node;
    }
}

void AddTail(LinkList& l, Node* node)
{
    if (l.Head == NULL) {
        l.Head = node;
        l.Tail = node;
    }
    else {
        l.Tail->next = node;
        l.Tail = node;
    }
}

void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch)
{
    if (nodesearch != NULL) {
        head->next = nodesearch->next;
        nodesearch->next = head;
        if (l.Tail == nodesearch)
            l.Tail = head;
    }
    else
        AddHead(l, head);
}

int RemoveHead(LinkList& l)
{
    if (l.Head != NULL) {
        Node* node = l.Head;
        l.Head = node->next;
        node = NULL;
        if (l.Head == NULL)
            l.Tail = NULL;
        return 1;
    }
    return 0;
}

int RemoveTail(LinkList& l)
{
    if (l.Head != NULL) {
        Node* node = l.Head->next;
        Node* NodeNext = node;
        while (node->next != NULL)
        {
            NodeNext = node;
            node = node->next;
        }
        l.Tail = NodeNext;
        l.Tail->next = NULL;
        return 1;
    }
    return 0;
}

int RemoveInNodeSearch(LinkList& l, Node* nodeseach)
{
    Node* node = l.Head;
    Node* NodeNext = NULL;
    while (node != NULL) {
        if (node->data.mssv == nodeseach->data.mssv)
            break;
        NodeNext = node;
        node = node->next;
    }
    if (node == NULL)
        return 0;
    if (NodeNext != NULL) {
        if (node == l.Tail)
            l.Tail = NodeNext;
        NodeNext->next = node->next;
        delete node;
    }
    else {
        l.Head = node->next;
        if (l.Head == NULL)
            l.Tail = NULL;
    }
    return 1;
}

Node* SearchNode(LinkList l, int index)
{
    Node* node = l.Head;
    while (node != NULL && node->data.mssv != index)
        node = node->next;
    if (node != NULL)
        return node;
    return NULL;
}

void ArrangeList(LinkList& l)
{
    for (Node* node1 = l.Head; node1 != NULL; node1 = node1->next)
        for (Node* node2 = node1->next; node2 != NULL; node2 = node2->next)
            if (node1->data.mssv > node2->data.mssv)
                SwapNode(node1, node2);
}

void SwapNode(Node* node1, Node* node2)
{
    Data Mid;
    Mid = node1->data;
    node1->data = node2->data;
    node2->data = Mid;
}
void PrintList(LinkList l)
{
    if (l.Head != NULL) {
        for (Node* node = l.Head; node != NULL; node = node->next) {
            cout << "MSSV: " << node->data.mssv << endl;
            cout << "Ten: " << node->data.ten << endl;
            cout << "Lop: " << node->data.lop << endl;
            cout << "Diem Tong Ket: " << node->data.dtb << endl;
            cout << "Hanh Kiem: ";
            switch (node->data.hanhkiem) {
            case 1:
            {
                cout << "Tot" << endl;
                break;
            }
            case 2:
            {
                cout << "Kha" << endl;
                break;
            }
            case 3:
            {
                cout << "Trung binh" << endl;
                break;
            }
            case 4:
            {
                cout << "Yeu" << endl;
                break;
            }
            }
            cout << "--------------------------" << endl;
        }
    }
}

void PrintListWithCondition(LinkList l, string input)
{
    if (l.Head != NULL) {
        for (Node* node = l.Head;node != NULL;node = node->next) {
            if (node->data.lop != input)
                continue;
            cout << "MSSV: " << node->data.mssv << endl;
            cout << "Ten: " << node->data.ten << endl;
            cout << "Lop: " << node->data.lop << endl;
            cout << "Diem Tong Ket: " << node->data.dtb << endl;
            cout << "Hanh Kiem: ";
            switch (node->data.hanhkiem) {
            case 1:
            {
                cout << "Tot" << endl;
                break;
            }
            case 2:
            {
                cout << "Kha" << endl;
                break;
            }
            case 3:
            {
                cout << "Trung binh" << endl;
                break;
            }
            case 4:
            {
                cout << "Yeu" << endl;
                break;
            }
            }
            cout << "--------------------------" << endl;
        }
    }
}
