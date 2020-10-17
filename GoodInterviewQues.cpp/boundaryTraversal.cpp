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
  node *left, *right;
  node(int _data)
  {
    data = _data;
    left = right = NULL;
  }
};

node *buildTree(node *root)
{
  int data;
  cin >> data;
  if (data == -1)
    return NULL;
  root = new node(data);
  root->left = buildTree(root->left);
  root->right = buildTree(root->right);
  return root;
}

void print_left(node *root)
{
  if (!root)
    return;
  if (root and root->left)
    cout << root->data << " ";
  print_left(root->left);
}

void print_right(node *root)
{
  if (!root)
    return;
  if (root and root->right)
    cout << root->data << " ";
  print_right(root->right);
}

void print_leaf_nodes(node *root)
{
  if (!root)
    return;
  print_leaf_nodes(root->left);
  if (!root->left and !root->right)
    cout << root->data << " ";
  print_leaf_nodes(root->right);
}

void boundary_traversal(node *root)
{
  if (!root)
    return;
  cout << root->data << " ";
  print_left(root->left);
  print_leaf_nodes(root->left);
  print_leaf_nodes(root->right);
  print_right(root->right);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  node *root = NULL;
  root = buildTree(root);
  boundary_traversal(root);
  return 0;
}
