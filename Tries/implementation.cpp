#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

class node {
public:
	char data;
	unordered_map<char, node*> children;
	bool isTerminal;
	node(char ch) {
		data = ch;
		isTerminal = false;
	}
};

class Trie {
	node* root;
	int number_of_words;
public:
	Trie() {
		root = new node('\0');
		number_of_words = 0;
	}

	void insert(string str) {
		node* curr = root;
		for (char ch : str) {
			if (curr->children.count(ch)) {
				curr = curr->children[ch];
			} else {
				node* temp = new node(ch);
				curr->children[ch] = temp;
				curr = temp;
			}
		}
		curr->isTerminal = true;
		number_of_words++;
	}

	bool find(string str) {
		node* curr = root;
		for (char ch : str) {
			if (curr->children.count(ch)) {
				curr = curr->children[ch];
			} else {
				return false;
			}
		}
		return curr->isTerminal;
	}

};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string> names = {"apple", "mango", "pears", "banana", "app"};
	Trie phonebook;

	for (auto str : names) {
		phonebook.insert(str);
	}

	if (phonebook.find("apple"))
		cout << "apple Present" << endl;

	if (phonebook.find("app"))
		cout << "app Present" << endl;

	if (phonebook.find("guvava"))
		cout << "guvava present" << endl;
	else
		cout << "guvava not present" << endl;



	return 0;
}