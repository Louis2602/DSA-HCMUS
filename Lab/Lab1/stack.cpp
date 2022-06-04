#include <iostream>
using namespace std;

struct NODE
{
    int key;
    NODE *next;
};

NODE *createNode(int data)
{
    NODE *p = new NODE;
    p->key = data;
    p->next = NULL;
    return p;
}
// add head
void push(NODE *&head, int data)
{
    NODE *p = createNode(data);
    if (head == NULL)
    {
        head = p;
        return;
    }
    p->next = head;
    head = p;
}
// remove head
void pop(NODE *&head)
{
    NODE *p = head;
    if (head == NULL)
        return;
    head = p->next;
    delete p;
}
bool isempty(NODE *head)
{
    if (head == NULL)
        return true;
    return false;
}
void print(NODE *head)
{
    NODE *p = head;
    cout << "Stack:\n";
    while (p)
    {
        cout << p->key << '\n';
        p = p->next;
    }
}
int main()
{
    int n;
    NODE *head = NULL;
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        push(head, i);
    }
    print(head);
    pop(head);
    pop(head);
    print(head);
    return 0;
}