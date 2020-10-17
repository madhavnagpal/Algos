// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

class node
{
public:
  int data;
  node *next;
  node(int data)
  {
    this->data = data;
    next = NULL;
  }
};

void insertAtEnd(node *&head, int data)
{
  if (!head)
  {
    head = new node(data);
    return;
  }
  node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = new node(data);
}

void printLL(node *head)
{
  cout << "List is:";
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

node *reverse_in_groups(node *head, int k)
{
  node *curr = head, *prev = NULL, *n;
  int temp = k;
  while (temp-- and curr)
  {
    n = curr->next;
    curr->next = prev;
    prev = curr;
    curr = n;
  }

  if (n)
  {
    head->next = reverse_in_groups(curr, k);
  }
  return prev;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  node *head = NULL;
  int n, data;
  cin >> n;

  while (n--)
  {
    cin >> data;
    insertAtEnd(head, data);
  }

  int k;
  cin >> k;
  printLL(head);
  head = reverse_in_groups(head, k);
  printLL(head);
  return 0;
}
