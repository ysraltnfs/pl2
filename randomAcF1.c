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


void dosyaOlustur(){

    ogrenci bos = {0,"", "", ""};
    int i;
    char fn[20];
    FILE *p1;
    printf("olusturulacak dosyanin adini giriniz.\n(Ayni isimli bir dosya varsa icerigi silinecektir)");
    scanf("%s", fn);
    printf("\n");
    p1 = fopen(fn,"w");
    for(i=1; i<=100; i++){
        fwrite(&bos, sizeof(ogrenci), 1, p1);    
    }
    fclose(p1);
    
}


void kayitEkle(){
    char fn[20];
    FILE *p2;
    ogrenci oBilgi = {0, "", "", ""};
    
    printf("kayit eklemek istediginiz dosyanin adini giriniz: ");
    scanf("%s", fn);
    printf("\n");
    p2 = fopen(fn,"r+");
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


void kayitSil(){
    char fn[20];
    FILE *p4;
    ogrenci oBilgi = {0, "", "", ""};
    ogrenci oBilgi2 = {0, "", "", ""};
    
    printf("kayit silmek istediginiz dosyanin adini giriniz: ");
    scanf("%s", fn);
    printf("\n");
    p4 = fopen(fn,"r+");
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


void ara(){
    FILE *p3;
    char fn[20];
    double oNO;
    ogrenci oBilgi = {0, "", "", ""};

    printf("arama yapmak istediginiz dosyanin adini giriniz: ");
    scanf("%s", fn);
    printf("\n");
    p3 = fopen(fn,"r");
    printf("arama yapmak icin ogrenci no giriniz: ");
    scanf("%lf", &oNO);
    printf("\n");
    fseek(p3, (oNO-1)*sizeof(ogrenci),SEEK_SET);
    fread(&oBilgi, sizeof(ogrenci), 1, p3);
    if(oBilgi.numara == oNO && oNO != 0){
        printf("%.0lf %s %s %s\n", oBilgi.numara, oBilgi.isim, oBilgi.soyisim, oBilgi.bolum);
    }
    else printf("kayit bulunamadi\n");


}


void listele(){
    FILE *p3;
    char fn[20];
    printf("listelemek istediginiz dosyanin adini giriniz: ");
    scanf("%s", fn);
    printf("\n");
    p3 = fopen(fn,"r");
    ogrenci oBilgi = {0, "", "", ""};
    while(!feof(p3)){
        fread(&oBilgi, sizeof(ogrenci), 1, p3);
        if(oBilgi.numara!=0){
            printf("%.0lf %s %s %s\n", oBilgi.numara, oBilgi.isim, oBilgi.soyisim, oBilgi.bolum);
        }
    }
    printf("\n");
    fclose(p3);
}

int main(){
    printf("1. dosya olusturma\n2. kayit ekleme\n3. kayit silme\n4. kayit arama\n5. kayitli ogrencileri listele\n6. cikis\n\n");
    int secim;
    while(secim != 6){
        printf("islem seciniz: ");
        scanf("%d", &secim);
        printf("\n");
        if(secim == 1) dosyaOlustur();
        else if(secim == 2) kayitEkle();
        else if(secim == 3) kayitSil();
        else if(secim == 4) ara();
        else if(secim == 5) listele();
    }
    

    


    return 0;
}