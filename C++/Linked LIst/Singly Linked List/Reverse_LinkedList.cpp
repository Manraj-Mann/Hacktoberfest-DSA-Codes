#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	int val;
	struct node* next;
} node;

node* head = NULL;


int count(node* head)
{
	node* p = head;
	int k = 1;
	while (p != NULL) {
		p = p->next;
		k++;
	}
	return k;
}

node* ll_reverse(node* head) 
{
	node* p = head;
	long int i = count(head), j = 1;
	long int arr[i];
	while (i && p != NULL) {
		arr[j++] = p->val;
		p = p->next;
		i--;
	}
	j--;
	while (j) 
		cout << arr[j--] << " ";
	return head;
}


node* insert_end(node* head, int data)
{
	node *q = head, *p = (node*)malloc(sizeof(node));
	p->val = data;
	while (q->next != NULL)
		q = q->next;
	q->next = p;
	p->next = NULL;
	return head;
}

node* create_ll(node* head, int data) 
{
	node* p = (node*)malloc(sizeof(node));
	p->val = data;
	if (head == NULL) {
		head = p;
		p->next = NULL;
		return head;
	}
	else {
		head = insert_end(head, data);
		return head;
	}
}


int main()
{
	int i = 5, j = 1;
	while (i--)
		head = create_ll(head, j++);
	head = ll_reverse(head);
	return 0;
}


