#include<stdio.h>
#include<stdlib.h>

struct n{
    int number;
    struct n *next;
};
typedef struct n node;

node * cutheadaddlast(node *head){
    node *p;
    p = head;

    while(1){
        if(p->next == NULL) break;
        p = p->next;

    }
    p->next = head;
    head = p->next->next;
    p->next->next = NULL;

}