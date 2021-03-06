#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct kisi{
	int no;
	int yas;
	char isim[30];
	struct kisi *next;
};

typedef struct kisi node;
node *head;

node *liste_olustur();
void iki_topla_bir_olustur(node *);
node *liste_swap(node *);
void liste_goster(node *);


int kayit=0;


int main(){
	int secim;
	head = NULL;
	
	while(1){
		if(kayit > 0){
			printf("\n\nBir tusa basana kadar ekranda kalacaktir..");
			getch();
			system("cls");
			printf("*** ISLEM TAMAMLANDI ***\n\n");
		}
	
		printf("1 ==> Liste olustur\n2 ==> 2 elemanin numara ve yas toplamlariyla yeni bir eleman olustur");
		printf("\n3 ==> Elemanlari yer degistir\n4 ==> Listeyi goster\n5 ==> Cikis\n");
		printf("\nSecimini Yap : "); scanf("%d",&secim);
		
		switch(secim){
			case 1:
				head = liste_olustur();
				break;
			
			case 2:
				iki_topla_bir_olustur(head);
				break;
				
			case 3:
				head = liste_swap(head);
				break;
				
			case 4:
				liste_goster(head);
				break;
				
			case 5:
				free(head);
				return 0;
			
			default:
				printf("\n*** HATALI GIRIS ***");
				break;
	
		}
	
	}
	
}


node *liste_olustur(){
	int n,k;
	node *root,*iter;
	kayit = 0;
	printf("\nListede kac ogrenci olacak ? : "); scanf("%d",&n);
	kayit += n;
	
	for(k=0; k<n; k++){
		if(k == 0){
			root = (node *) malloc(sizeof(node));
			iter = root;
		}
	
		else{
			iter->next = (node *) malloc(sizeof(node));
			iter = iter->next;
		}
	
		printf("\n\n%d. ogrencinin numarasi : ",k+1); scanf("%d",&iter->no);
		printf("%d. ogrencinin ismi : ",k+1); scanf("%s",iter->isim);
		printf("%d. ogrencinin yasi : ",k+1); scanf("%d",&iter->yas);
	
	}
	
	iter->next = NULL;	
	return root;
}


void iki_topla_bir_olustur(node *root){
	int sayac=0, gecici_no=0, gecici_yas=0,i=1;
	node *iter,*temp;
	iter = root;
	
	printf("\nHer iki elemandan sonra yeni bir eleman eklenecektir\n");
	
	while(iter != NULL){
		gecici_no += iter->no;
		gecici_yas += iter->yas;
		sayac++;
		
		if(sayac == 2){
			printf("\nYeni olusacak %d. kisi icin\n",i);
			temp = (node *) malloc(sizeof(node));
			temp->no = gecici_no;
			temp->yas = gecici_yas;
			printf("Isim gir : "); scanf("%s",temp->isim);
			
			temp->next = iter->next;
			iter-> next = temp;
			iter = iter->next;	
	
			gecici_no = 0;
			gecici_yas = 0;
			sayac = 0;
			kayit++;
			i++;
		}
		iter = iter->next;
	
	}
	
}


node *liste_swap(node *root){
	int no1, no2;
	node *iter, *iter2, *temp, *iter_sonrasi, *iter2_sonrasi;
	iter = root;
	
	printf("\nHangi elemanlar yer degistirecek ? (no gir)");
	printf("\nBirinci no : "); scanf("%d",&no1);
	printf("Ikinci no : "); scanf("%d",&no2);
	
	while(iter != NULL){
		if(iter->no == no1){
			iter2 = iter;
			iter2_sonrasi = iter2->next;	
			break;
		}
		iter = iter->next;
		
	}
	
	iter=root;
	
	while(iter != NULL){
		if(iter->no == no2){
			temp = (node *) malloc(sizeof(node));
			temp->next = NULL;
			
			*temp = *iter;
			iter_sonrasi = iter->next;
			*iter = *iter2;
			*iter2 = *temp;
			iter2->next = iter2_sonrasi;
			iter->next = iter_sonrasi;
			
			return root;
		}	
		iter = iter->next;
			
	}
	
	printf("\n*** NO BULUNAMADI ***");
	return root;
}


void liste_goster(node *root){
	int i=1;
	
	node *iter;
	printf("\nToplam %d adet kayit bulundu",kayit);
	iter = root;
	
	while(iter != NULL){
		printf("\n%d. Kisi \t Isim => %s \t No => %d \t Yas => %d",i,iter->isim,iter->no,iter->yas);
		iter = iter->next;
		i++;
	}
}
