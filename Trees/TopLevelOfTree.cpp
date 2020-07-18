// I am Nothing, You Are Nothing!
// Krishna is Everything ...
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

vector<int> tree;
int i = 0;

class node
{
public:
  int val;
  node *left, *right;
  node(int _val)
  {
    val = _val;
    left = right = NULL;
  }
};

node *buildTree(node *root)
{
  int val = tree[i++];
  if (val < 1)
  {
    return NULL;
  }
  root = new node(val);
  root->left = buildTree(root->left);
  root->right = buildTree(root->right);
  return root;
}

void topLevel(node *root)
{
  if (!root)
    return;
  map<int, int> h;
  queue<pair<int, node *>> q;
  q.push({0, root});

  while (!q.empty())
  {
    pair<int, node *> p = q.front();
    q.pop();
    node *curr = p.second;

    if (h.find(p.first) == h.end())
    {
      h[p.first] = curr->val;
    }
    if (curr->left)
      q.push({p.first - 1, curr->left});
    if (curr->right)
      q.push({p.first + 1, curr->right});
  }
  for (auto node : h)
  {
    cout << node.second << " ";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int data;
  while (cin >> data)
  {
    tree.push_back(data);
  }

  node *root = NULL;
  root = buildTree(root);

  topLevel(root);
  return 0;
}
