#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct n{
    int number;
    struct n *next;
};
typedef struct n node;



void veriEkle(node *head, int sayi){
    if(sayi%2==1){
        //printf("0. calisti");
        node *t;
        //printf("1. calisti");
        t = (node *)malloc(sizeof(node));
        //printf("2. calisti");
        t->next = head;
        //printf("3. calisti");
        t->number = sayi;
        //printf("4. calisti");
        //printf("%d\n", t->number);
        //printf("5. calisti");
        head = t;
        //printf("6. calisti");
    
    }

    if(sayi%2==0){
        
        //printf("0. calisti");
        node *t;
        //printf("1. calisti");
        t = (node *)malloc(sizeof(node));
        //printf("2. calisti");
        t = head;
        //printf("3. calisti");
        while((t->next) != NULL){
            //printf("while a girdi");
            t = t->next;
        }
        //printf("4. calisti");
        t->next = (node *)malloc(sizeof(node));
        //printf("5. calisti");
        t->next->number = sayi;
        //printf("6. calisti");
        t->next->next = NULL;
        //printf("7. calisti");
    }
    
    
    


}




int main(){
    node *head;
    head = (node *) malloc(sizeof(node));
    head->number = 3;
    head->next=NULL;
    //printf("%d\n", head->number);

    int sayi;
    while(1){
        //printf("sayi giriniz (cikmak icin -1): ");
        scanf("%d", &sayi);
        if(sayi == -1) break;
        veriEkle(head, sayi);
        
    }

    node *p3 = head;

    while((p3->next)!=NULL){
        printf("%d\n",p3->number);
        p3 = p3->next;

    }
    
}