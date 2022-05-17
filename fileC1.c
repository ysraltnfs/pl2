#include<stdio.h>


FILE * dosyaOlustur(){
    char fn[20];
    FILE * fp;
    printf("olusturulacak dosyanin adini giriniz.\n(Ayni isimli bir dosya varsa icerigi silinecektir)");
    scanf("%s", fn);
    fp = fopen(fn, "w");
    fclose(fp);
    return fp;

    
}

void veriEkle(){
    char ogrenciNo[12];
    char isim[20];
    char bolum[25];
    char fn[20];
    FILE *p1;


    printf("veri gireceginiz dosya adini yazin: ");
    gets_s(fn, 21);
    gets_s(fn, 21);
    printf("ogrenci no: ");
    gets_s(ogrenciNo, 13);
    printf("isim: ");
    gets_s(isim, 21);
    printf("bolum: ");
    gets_s(bolum, 26);

    p1 = fopen(fn, "a+");
    fprintf(p1, "%s, %s, %s\n", ogrenciNo, isim, bolum);
    fclose(p1);


}

void veriAra(){
    
    char satir[70];
    char fn[21];
    int secim2=0;
    
    FILE *p2;
    printf("arama yapmak istediginiz dosyanin adini girin: ");
    gets_s(fn, 21);
    gets_s(fn, 21);
    p2 = fopen(fn, "r");
    printf("1. numara ile arama\n2. isim ile arama\nsecim yapiniz: ");
    scanf("%d", &secim2);

    if(secim2 == 1){
        char ogrenciNo[12];
        printf("numarayi girin: ");
        gets_s(ogrenciNo, 13);
        
        while(1){
            //printf("feof= %d\n", feof(p2));
            int control = 0;
            fgets(satir, 70, p2);
            for(int i = 0; i<10; i++){
                if(ogrenciNo[i] != satir[i]){ 
                    control = 0; 
                    break;
                }
                control = 1;
            }
            //printf("control= %d\n", control);
            //printf("feof= %d\n", feof(p2));
            if(feof(p2)) break;
            if(control == 1) printf("%s", satir);
            printf("\n");
            
        }

    }

    else if(secim2 == 2){

        char isim[21];
        int hs=0, i=0, k=0;
        char c = ',';
        
    
        printf("isim giriniz: ");
        gets_s(isim, 22);
        gets_s(isim, 22);
        while(1){
            if(isim[i] == c) break;
            hs += 1;
            i += 1;
        }
        while(1){
            //printf("feof= %d\n", feof(p2));
            int control = 0;
            fgets(satir, 70, p2);
            if(satir == NULL) break;
            for(int i = 12; i <= 12+hs ; i++){
                //printf("isim[k] = %c satir[i] = %c\n", isim[k], satir[i]);
                if(isim[k]==satir[i]){
                    k+=1;
                    i+=1;
                    control=1;
                }
                else control = 0; k = 0; break;
            }
            //printf("control= %d\n", control);
            //printf("feof= %d\n", feof(p2));
            if(feof(p2)) break;
            if(control == 1) printf("%s", satir);
            printf("\n");
        }




    }
    fclose(p2);
    printf("\n");


}



int main(){
    /*
    double ogrenciNo;
    char isim[20];
    char bolum[25];
    FILE *dp1;
    dp1 = fopen("sinif1.txt","a");
    printf("ogrenci no: ");
    scanf("%lf", &ogrenciNo);

    printf("isim: ");
    scanf("%s", isim);
    printf("bolum: ");
    scanf("%s", bolum);
    fprintf(dp1,"%.0lf, %s, %s", ogrenciNo, isim, bolum);
    fclose(dp1);
    */
    
    
    int secim;
    while(1){
        printf("1. dosya olustur\n2. dosyaya veri yaz\n3. dosyada veri ara\n4. programi kapat\n\nislem seciniz: ");
        scanf("%d", &secim);
        if(secim==1) dosyaOlustur();
        else if(secim == 2) veriEkle();
        else if(secim == 3) veriAra();
        else if(secim == 4) break;
        else printf("\ngecersiz islem");
    
        
    }
    
    



    return 0;
}