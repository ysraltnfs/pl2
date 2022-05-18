#include<stdio.h>
#include<stdlib.h>

struct n{
    int number;
    struct n *next;
};
typedef struct n node;

node * cutMiddle(node *head){
    node *p;
    p = head;
    int counter = 0;
    int mid;

    while(1){
        counter += 1;
        if(p->next==NULL){
            break;
        }
        p = p->next;

    }
    mid = counter/2;
    p = head;
    for(int i = 1; i < mid-1; i++){
        p = p->next;
    }
    node *t;
    t=p;
    p->next = p->next->next;
    free(t->next);
    return head;

}


