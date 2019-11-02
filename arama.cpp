// ogrenci.txt dosyasinda kayitli ogrencilerin;
// not ortalamasini alan
// notlari listeleyen
// Ogrenci numarasiyla arama yapan program


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
   FILE *aa;        // dosya isaretcisini belirledim.
   char Ad[10];     //gerekli olan degerleri atýyorum.
   int Not, No, eb, ek, n, top;
   int islem;
   int say=0;
   float ort;
   int nosu;
   int sonuc;

   menu: // daha iyi kullaným icin menu hazýrlýyorum
	printf(" \n ========= OGRENCI BILGI SISTEMINE HOSGELDINIZ! ========== \n\n");
	printf("\t \t [1] Ogrencilere ait notlar \n");
	printf("\t \t [2] Not ortalamalari \n");
	printf("\t \t [3] Ogrenci Arama\n");
	printf("\t \t [4] Cikis\n");
	printf("\t \t Lutfen secim yapiniz: ");
	islem=getch(); // burada menudeki tuslarla yapilacak isleri switch case islemiyle belirtiyorum. 
	switch(islem){
    case '1'  :
    	goto Notlar; // goto kullandim cunku her bir yapilacak isi ayri bir bolgeye ayirdim.
       printf("notlar");
       break; 
    case  '2':
    	goto ortalama;
       printf("ort");
       break; 
    case  '3':
    	goto arama;
       printf("arama");
       break; 
       
    case  '4':
    	goto cikis;
       printf("cikis");
       break; 
      default :
    	printf("\n \t \t Yanlis giris yaptiniz! \n)");
  break;
    }

 /********/

Notlar:

if((aa=fopen("ogrenci.txt","r"))==NULL){ // dosya bulunumaz ise otomatik olarak cikis yapip, uyari bildirecek.
 puts("Dosya bulunamadi !\n"), exit(1);
}
printf("\nOgrenci No \tIsim\t\tNot\n");
printf("-----------\t--------\t-------\n");
while(!feof(aa)){ // dosyanin sonuna kadar butun .txt dosyasini taratiyorum...
fscanf(aa,"%d %s %d",&No,Ad,&Not); // verileri okutuyorum
printf("%d\t\t",No);  // ve ekrana yazdiriyorum...
printf("%s\t\t",Ad);
printf("%d\n",Not);}
fclose(aa);
goto menu;
 
 /********/
 
ortalama:
   if( (aa=fopen("ogrenci.txt","r")) == NULL ) // ayni sekilde...
     puts("Dosya bulunamadi !\n"), exit(1);

   // baþlangýç deðerleri atýyorum 
   ek  =  1000;  // çok büyük olan deðeri atiyorum
   eb  = -1000;  // çok küçük olan degeri atiyorum 
   top = 0;      // notlarýn toplaminin baslangic degerini atiyorum
   n   = 0;      // notu 0'dan farklý öðrencilerin toplamýný atiyorum 

   while( !feof(aa) )                    // dosyanýn sonuna kadar taratiyorum
   {
      fscanf(aa,"%d %s %d",&No,Ad,&Not); // verileri okutuyorum

      if(Not>eb) eb = Not;               // en büyük ve en küçük bulunuyor... 
      if(Not<ek) ek = Not;

      if(Not) n++;                       // Not 0'dan farklý olup olmadýðýna bakýyorum..

      top += Not;                        // notlarin toplamini atiyorum.
   }

   fclose(aa);                           // dosyayi kapatiyorum

   ort = (float) top/n;                  // ortalama alýndý, 0 lar hariç

   printf("\nEn yuksek not = %2d\n",eb);   // ekrana yazdiriyorum.
   printf("En  dusuk not = %2d\n",ek);
   printf("Ortalama      = %4.1f\n",ort);

 goto menu;
 
 /********/
 
 arama:
 aa = fopen("ogrenci.txt", "r"); // dosyayi tekrar aciyorum.
 printf ("\n Ogrenci numarasini giriniz: "); // bilgi girisi istiyorum.
 scanf ("%d",&nosu); // bilgiler aliniyor.

	while (fscanf(aa,"%d %s %d",&No,Ad,&Not)) //while dongusu ile dosyayi tariyorum
{
if (nosu==No) // eger ogrenci numarasi, dosyadakine eþitse, aþaðýdaki iþlemleri yapiyor
{
say++; // sayaci arttiyor ve...
if (say>0) // büyü1k olduðu takdirde..
printf("\nOgrenci No \tIsim\t\tNot\n");
printf("-----------\t--------\t-------\n");
printf("%d\t\t",No);  // ogrenciyi .txt dosyasindaki bilgilere göre siraliyor...
printf("%s\t\t",Ad);
printf("%d\n",Not);}
}if (say==0) // eger eslesme olmazsa...
{
printf ("\n Kayit bulunamadi!"); // ...
}

goto menu;

 cikis:
 	printf("\n Iyi gunler!"); // ve cikis iþlemi için son döngü.
return 1;
}
