#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int _data){
        data = _data;
        next = NULL;
    }
};

pair<node*, node*> helper(node* head, node* tail) {
	if (!head or !head->next)
		return{head, head};

	node *curr = head, *prev = NULL;

	while (curr != tail) {
		if (curr->data > tail->data) {
			if (curr == head) {
				node *nextToTail = tail->next;
				head = head->next;
				tail->next = curr;
				if (prev)
					prev->next = head;
				curr->next = nextToTail;
				curr = head;
			} else {
				node *next = tail->next;
				prev->next = curr->next;
				tail->next = curr;
				curr->next = next;
				curr = prev->next;
			}

		} else {
			prev = curr;
			curr = curr->next;
		}
	}
	node *newHead, *newTail;

	if (head == tail) {
		newHead = tail;
	} else {
		//prev is tail of first half
		prev->next = NULL;
		auto firstHalf = helper(head, prev);
		newHead = firstHalf.first;
		firstHalf.second->next = tail;
	}

	if (!tail->next) {
		newTail = tail;
	} else {
		curr = tail->next;
		while (curr->next) {
			curr = curr->next;
		}
		auto secondHalf = helper(tail->next, curr);
		tail->next = secondHalf.first;
		newTail = secondHalf.second;
	}

	return {newHead, newTail};
}

void quickSort(node **headRef) {
	node *head, *tail, *curr;
	curr = head = *headRef;

	if (!head or !head->next)
		return;

	while (curr->next) {
		curr = curr->next;
	}
	tail = curr;

	auto node = helper(head, tail);

	*headRef = node.first;
}