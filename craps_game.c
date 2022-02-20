#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    printf("\n\n\n      1. el\n\niki zar atiliyor...\n\n");
    
    int bz = (rand() % 6) + 1;
    int iz = (rand() % 6) + 1;
    int zt = bz + iz;
    
    printf("1. zar = %3d\n",bz);
    printf("2. zar = %3d\n\n",iz);
    printf("toplam = %3d\n",zt);
   
    if(zt == 7 || zt == 11){
        
        printf("\noyuncu kazandi\n\n\n");
        return EXIT_SUCCESS;
    }

    if(zt == 2 || zt == 3 || zt == 12){
        
        printf("\noyuncu kaybetti\n\n\n");
        return EXIT_SUCCESS;
    }
    
    int zt2;
    
    for(int i = 0;;i++){
        printf("\n\n\n%7d. el\n\niki zar atiliyor...\n\n",i+2);
        
        bz = (rand() % 6) + 1;
        iz = (rand() % 6) + 1;
        zt2 = bz + iz;
        
        printf("1. zar = %3d\n",bz);
        printf("2. zar = %3d\n\n",iz);
        printf("toplam = %3d\n",zt2);
        
        if(zt2 == 7){
            printf("\noyuncu kaybetti\n\n\n");
            break;
        }
        
        else if(zt2 == zt){
            printf("\noyuncu kazandi\n\n\n");
            break;
        }

    }

    return 0;
}