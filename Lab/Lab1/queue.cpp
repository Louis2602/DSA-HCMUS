
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
// add tail
void enqueue(NODE *&head, int data)
{
    NODE *p = createNode(data);
    if (head == NULL)
    {
        head = p;
        return;
    }
    NODE *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = p;
}
// remove head
void dequeue(NODE *&head)
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
    cout << "Queue: ";
    while (p)
    {
        cout << p->key << " -> ";
        p = p->next;
    }
    cout << '\n';
}
int main()
{
    int n;
    NODE *head = NULL;
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        enqueue(head, i);
    }
    print(head);
    dequeue(head);
    dequeue(head);
    print(head);
    return 0;
}