#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "linked.h"


void init (BigInt *p) {

	p->head = NULL;
}
int is_empty(BigInt b) {

	return b.head == NULL;
}
void print (BigInt p) {

	if (is_empty(p)) {

		printf("%d", 0);

	} else {
		BigInt temp;
		init(&temp);
		node *i;
		for (i = p.head; i != NULL; i = i->next) {
			prepend_digit(&temp, i->data);
		}
		for (i = temp.head; i != NULL; i = i->next) {
			printf("%d", i->data);
		}
	}
}
void append_digit (BigInt *d, int x) {

	node *iter = NULL;
	for (iter = d->head; iter != NULL && iter->next != NULL; iter = iter->next);

	if (iter == NULL ) {
		node*temp;
		temp = (node*)malloc(sizeof(node));
		temp->data = x;
		d->head = temp;
		temp->next = NULL;

	} else {
		node *temp;
		temp = (node *)malloc(sizeof(node));
		temp->data = x;
		iter->next = temp;
		temp->next = NULL;
	}
}
void prepend_digit (BigInt *p, int x) {

	node * temp;
	temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->next = p->head;
	p->head = temp;
}
void add (BigInt d, BigInt p, BigInt *x) {

	init(x);
	int carry = 0;
	node *iter1 = p.head;
	node *iter2 = d.head;
	int x1 = 0;
	int x2 = 0;
	while(1) {
		if (iter1 == NULL && iter2 == NULL) {
			if (carry != 0) {
				append_digit(x, carry);
			}
			break;
		}
		x1 = (iter1 != NULL ) ? iter1->data : 0 ; //iter1 null değil ise değerini x1 e ata;
		x2 = (iter2 != NULL ) ? iter2->data : 0 ; //iter2 null değil ise değerinin x2 ye ata; conditional operator;

		int x3 = x1 + x2 + carry;
		carry = x3 / 10;
		int x4 = x3 % 10;
		append_digit(x, x4);

		iter1 = (iter1 != NULL) ? iter1->next : NULL;
		iter2 = (iter2 != NULL) ? iter2->next : NULL;
	}
}
