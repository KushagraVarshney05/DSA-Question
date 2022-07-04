#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int i)
    {
        data = i;
        next = 0;
    }
    node()
    {
        cout << "Enter the value : ";
        cin >> data;
        next = 0;
    }
};
void insert(node *&head, int i)
{
    node *n = new node(i);
    if (head == 0)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// By recursion
//  node *mergeTwoList(node *head1, node *head2)
//  {
//      // Base Case
//      if (head1 == 0)
//      {
//          return head2;
//      }
//      if (head2 == 0)
//      {
//          return head1;
//      }
//      node *res = 0;
//      if (head1->data <= head2->data)
//      {
//          res = head1;
//          res->next = mergeTwoList(head1->next, head2);
//      }
//      else
//      {
//          res = head2;
//          res->next = mergeTwoList(head1, head2->next);
//      }
//      return res;
//  }
node *mergeTwoList(node *head1, node *head2)
{
    if (head1 == 0)
    {
        return head2;
    }
    if (head2 == 0)
    {
        return head1;
    }
    node *ans = new node(0);
    node *temp = ans;
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            ans->next = head1;
            ans = ans->next;
            head1 = head1->next;
        }
        else
        {
            ans->next = head2;
            ans = ans->next;
            head2 = head2->next;
        }
    }
   if(head1)
   {
     ans->next = head1;
   }
   if(head2)
   {
     ans->next = head2;
   }
   return temp->next;
}
int main()
{
    node *head = 0;
    insert(head, 1);
    insert(head, 3);
    insert(head, 5);
    insert(head, 7);
    node *head1 = 0;
    insert(head1, 2);
    insert(head1, 4);
    insert(head1, 6);
    insert(head1, 8);
    node *ans = mergeTwoList(head, head1);
    display(ans);
    return 0;
}