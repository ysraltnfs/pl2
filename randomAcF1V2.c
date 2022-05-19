#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    double numara;
    char isim[20];
    char soyisim[20];
    char bolum[30];
};
typedef struct student ogrenci;


void temizle(char *fnp){


    printf("%s isimli dosyanin icerigi silinecektir. devam etmek istiyor musunuz(E/H) : ", fnp);
    char secim;
    secim = getchar();
    secim = getchar();
    if(secim == 'E'){
        ogrenci bos = {0,"", "", ""};
        int i;
        //char fn[20];
        FILE *p1;
        //printf("olusturulacak dosyanin adini giriniz.\n(Ayni isimli bir dosya varsa icerigi silinecektir)");
        //scanf("%s", fn);
        printf("\n");
        p1 = fopen(fnp,"w");
        if(p1 == NULL) printf("Hata!\nDosya icerigi temizlenemedi\n");
        else{
            for(i=1; i<=100; i++){
                fwrite(&bos, sizeof(ogrenci), 1, p1);    
            }
            fclose(p1);
            printf("Dosya icerigi temizlendi\n\n");
        }
    }
    else printf("\ntemizleme islemi iptal edildi\n");
    
}


void kayitEkle(char *fnp){
    //char fn[20];
    
    FILE *p2;
    ogrenci oBilgi = {0, "", "", ""};
    
    //printf("kayit eklemek istediginiz dosyanin adini giriniz: ");
    //scanf("%s", fn);

    printf("\n");
    p2 = fopen(fnp,"r+");
    if(p2 == NULL) printf("%s isimli dosya bulunamadi/erisilemedi\n\n" , fnp);
    
    else{
        double oID;
        printf("eklemek istediginiz ogrencinin numarasini girin: ");
        scanf("%lf", &oID);

        fseek(p2, (oID-1)*sizeof(ogrenci),SEEK_SET);
        fread(&oBilgi, sizeof(ogrenci), 1, p2);
        if(oBilgi.numara != 0) printf("Hata!\n%.0lf numarali kayitli bir ogrenci mevcut\n", oID);
        else{
            printf("ogrenci ismini giriniz: ");
            gets_s(oBilgi.isim, 21);
            gets_s(oBilgi.isim, 21);
            //scanf("%s", oBilgi.isim);
            printf("ogrenci soyismini giriniz: ");
            scanf("%s", oBilgi.soyisim);
            printf("ogrenci bolumunu giriniz: ");
            gets_s(oBilgi.bolum, 31);
            gets_s(oBilgi.bolum, 31);
            printf("\n");
            //scanf("%s", oBilgi.bolum);
            oBilgi.numara = oID;
            fseek(p2, (oID-1)*sizeof(ogrenci),SEEK_SET);
            fwrite(&oBilgi, sizeof(ogrenci), 1, p2);
            fclose(p2);  
        }
    }


}


void kayitSil(char *fnp){
    //char fn[20];
    FILE *p4;
    ogrenci oBilgi = {0, "", "", ""};
    ogrenci oBilgi2 = {0, "", "", ""};
    
    //printf("kayit silmek istediginiz dosyanin adini giriniz: ");
    //scanf("%s", fn);
    printf("\n");
    p4 = fopen(fnp,"r+");
    double oID;
    
    printf("kayit silmek icin ogrenci numarasi giriniz: ");
    scanf("%lf", &oID);
    fseek(p4, (oID-1)*sizeof(ogrenci),SEEK_SET);
    fread(&oBilgi, sizeof(ogrenci), 1, p4);
    if(oBilgi.numara == 0) printf("Hata!\n%.0lf numarali bir ogrenci bulunmamakta\n", oID);
    else{
        fseek(p4, (oID-1)*sizeof(ogrenci),SEEK_SET);
        fwrite(&oBilgi2, sizeof(ogrenci), 1, p4);
        fclose(p4);

    }



}


void ara(char *fnp){
    FILE *p3;
    //char fn[20];
    double oNO;
    ogrenci oBilgi = {0, "", "", ""};

    //printf("arama yapmak istediginiz dosyanin adini giriniz: ");
    //scanf("%s", fn);
    //printf("\n");
    p3 = fopen(fnp,"r");
    printf("arama yapmak icin ogrenci no giriniz: ");
    scanf("%lf", &oNO);
    printf("\n");
    fseek(p3, (oNO-1)*sizeof(ogrenci),SEEK_SET);
    fread(&oBilgi, sizeof(ogrenci), 1, p3);
    if(oBilgi.numara == oNO && oNO != 0){
        printf("%-6s %-18s %-18s %-18s\n","no", "isim", "soyisim", "bolum");
        printf("------------------------------------------------------------------\n");
        printf("%-6.0lf %-18s %-18s %-18s\n", oBilgi.numara, oBilgi.isim, oBilgi.soyisim, oBilgi.bolum);
    }
    else printf("kayit bulunamadi\n");
    printf("\n");

}


void listele(char *fnp){
    FILE *p3;
    //char fn[20];
    //printf("listelemek istediginiz dosyanin adini giriniz: ");
    //scanf("%s", fn);
    //printf("\n");
    p3 = fopen(fnp,"r");
    ogrenci oBilgi = {0, "", "", ""};
    printf("%-6s %-18s %-18s %-18s\n","no", "isim", "soyisim", "bolum");
    printf("-------------------------------------------------------------------------\n");
    while(!feof(p3)){
        fread(&oBilgi, sizeof(ogrenci), 1, p3);
        if(oBilgi.numara!=0){
            printf("%-6.0lf %-18s %-18s %-18s\n", oBilgi.numara, oBilgi.isim, oBilgi.soyisim, oBilgi.bolum);
        }
    }
    printf("\n");
    fclose(p3);
}

void baskaDosya(char *fnp){
    int secim;
    char nfn[20];
    printf("1. yeni bir dosya olustur\n2. var olan baska bir dosyayla devam et\nislem seciniz: ");
    scanf("%d", &secim);
    
    if(secim == 1){
        printf("\ndosya adini giriniz: ");
        scanf("%s", nfn);
        ogrenci bos = {0,"", "", ""};
        int i;
        
        FILE *p1;
       
        printf("\n");
        p1 = fopen(nfn,"w");
        if(p1 == NULL) printf("Hata!\nDosya olusturulamadi\n");
        else{
            for(i=1; i<=100; i++){
                fwrite(&bos, sizeof(ogrenci), 1, p1);    
            }
            fclose(p1);
            printf("Dosya olusturuldu\n");
            strcpy(fnp, nfn);
        }
    }
    else if(secim == 2){
        printf("\ndosya adini giriniz: ");
        scanf("%s", nfn);

        FILE *p1;
        p1 = fopen(nfn, "r");
        if(p1 == NULL) printf("\nHata!\ndosya bulunamadi\n");
        else{
            strcpy(fnp, nfn);
            printf("Dosyaya erisildi\n");
        }
    }
    else printf("\ngecersiz secim");

}

int main(){
    char fn[20];

    char *fnp = fn;

    int secim;
    char nfn[20];
    printf("1. yeni bir dosya olustur\n2. var olan bir dosyayla devam et\n3. cikis\nislem seciniz: ");
    scanf("%d", &secim);
    
    if(secim == 1){
        printf("\ndosya adini giriniz: ");
        scanf("%s", nfn);
        ogrenci bos = {0,"", "", ""};
        int i;
        
        FILE *p1;
       
        printf("\n");
        p1 = fopen(nfn,"w");
        if(p1 == NULL) printf("Hata!\nDosya olusturulamadi\n");
        else{
            for(i=1; i<=100; i++){
                fwrite(&bos, sizeof(ogrenci), 1, p1);    
            }
            fclose(p1);
            printf("Dosya olusturuldu\n");
            strcpy(fnp, nfn);
        }
    }
    else if(secim == 2){
        printf("\ndosya adini giriniz: ");
        scanf("%s", nfn);

        FILE *p1;
        p1 = fopen(nfn, "r");
        if(p1 == NULL){ 
            printf("\nHata! dosya bulunamadi\nlutfen menuden 6. islemi (isleme baska bir dosya ile devam et) seciniz\n\nmenuye gecis yapmak icin enter tusuna basin... ");
            getchar();
            getchar();
            printf("\n");

        }


        else{
            strcpy(fnp, nfn);
            printf("Dosyaya erisildi\n");
        }
    }
    else{
        printf("programdan cikis yapiliyor"); 
        return 0;
    }

        


    printf("\n1. dosya icerigini sil\n2. kayit ekleme\n3. kayit silme\n4. kayit arama\n5. kayitli ogrencileri listele\n6. isleme baska bir dosya ile devam et\n7. cikis\n\n");
    int secim2;
    while(secim2 != 7){
        printf("dosya adi: %s\n", fn);
        printf("islem seciniz: ");
        scanf("%d", &secim2);
        printf("\n");
        if(secim2 == 1) temizle(fnp);
        else if(secim2 == 2) kayitEkle(fnp);
        else if(secim2 == 3) kayitSil(fnp);
        else if(secim2 == 4) ara(fnp);
        else if(secim2 == 5) listele(fnp);
        else if(secim2 == 6) baskaDosya(fnp);
        else if(secim2 == 7) break;
        else printf("gecersiz secim\n\n");
    }
    

    


    return 0;
}