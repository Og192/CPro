#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int type;

typedef struct node {
	type data;
	struct node *next;
	struct node *pre;
}node;
node *delete(node *head, type d)
{
	node *index = head;

	while(index != NULL) {
		if(index->data == d) {
			if(index == head) {
				head = index->next;
				head->pre = NULL;
				free(index);
				return head;
			}
			if(index->next == NULL) {
				index->pre->next == NULL;
				free(index);
				return head;
			}
			index->pre->next = index->next;
			index->next->pre = index->pre;
			free(index);
			return head;
		}
		index = index->next;
	}

}

node *link(node *head, type d)
{
	node *tmp;
	if(head == NULL) {
		tmp = malloc(sizeof(node));
		tmp->data = d;
		tmp->next = NULL;
		tmp->pre = NULL;

		head = tmp;
		return head;
	}
	
	tmp = malloc(sizeof(node));
	tmp->data = d;

	tmp->next = head;
	tmp->pre = NULL;

	head->pre = tmp;
	head = tmp;

	return head;
}

node *insertA(node *head, type x, type y)
{
	node *index = head;
	node *new = malloc(sizeof(node));
	new->data = x;

	while(index != NULL) {
		if(index->data == y) {
			head = delete(head, x);
			if(index == head) {
				index->pre = new;
				new->next = index;
				new->pre = NULL;
				head = new;
				return head;
			}
			index->pre->next = new;
			new->pre = index->pre;

			new->next = index;
			index->pre = new;
			return head;
		}
		index = index->next;
	}

}

node *insertB(node *head, type x, type y)
{
	node *index = head;
	node *new = malloc(sizeof(node));
	new->data = x;

	while(index != NULL) {
		if(index->data == y) {
			head = delete(head, x);
			if(index->next == NULL) {
				index->next = new;
				new->pre = index;
				new->next = NULL;
				return head;
			}

			index->next->pre = new;
			new->next = index->next;
			new->pre = index;
			index->next = new;
			return head;
		}
		index = index->next;
	}

	return head;
}

int main()
{
	node *head = NULL;
	node *index;
	char cmd;
	int n, m, i, x, y;


	scanf("%d %d", &n, &m);
	for(i = n - 1; i >= 0; i--)
		head = link(head, i + 1);

	for(i = 0; i < m; i++) {
		while(getchar() != '\n') {}
		scanf("%c %d %d", &cmd, &x, &y);
		if(cmd == 'A') head = insertA(head, x, y);
		if(cmd == 'B') head = insertB(head, x, y);
	}

	index = head;
	while(index != NULL) {
		printf("%d ", index->data);
		index = index->next;
	}
	printf("\n");
	return 0;
}
