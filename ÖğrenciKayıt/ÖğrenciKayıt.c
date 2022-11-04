#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ogrenci{
 int no;
 char isim[20];
 char soyad[20];
 struct ogrenci* next;	
};
	typedef struct ogrenci node;

node* ekle (node * head)
{
	node * ogr = (node *)malloc(sizeof(node));
	printf("Ogrenci no: ");
	scanf("%d",&ogr->no);
	printf("Ogrencinin adi: ");
	scanf("%s",&ogr->isim);
	printf("Ogrencinin soyadi: ");
	scanf("%s",&ogr->soyad);
	if(head==NULL){
		head = ogr;
		head -> next = NULL;
		printf("Listenin ilk ogrencisi kayit edildi.\n");
	}
	else{
		ogr -> next = head;
		head = ogr;
		printf("Ogrenci kayit edildi.\n");
	}
	return head;	
}

node * sil(node * head){
	if (head == NULL){
		printf("Liste bos");
	}
	else{
		int ogrno;
		printf("Ogrenci no: "); scanf("%d",&ogrno);
		if(head->no == ogrno && head->next ==NULL){
			free(head);
			head =NULL;
			printf("Ogrenci silindi\n");
		}
		else if(head->no == ogrno && head->next !=NULL){
			node *temp = head->next;
			free(head);
			head = temp;
			printf("%d numarali ogrenci silindi\n",ogrno);
		}
		else{
			node *temp2 = head;
			node *temp3 = head;
			while(temp2->next != NULL){
				if(temp2-> no == ogrno){
					temp3->next = temp2->next;
					printf("%d numarali Ogrenci silindi\n");
					free(temp2);

					break;
				}
				temp3 = temp2;
				temp2 = temp2->next;
			}
			if(temp2-> no == ogrno){
					temp3->next = NULL;
					printf("%d numarali Ogrenci silindi\n");
					free(temp2);

				}
		}
	}
	return head;	
}

node * print(node*head){
	system("cls");
	if(head == NULL){
		printf("Liste bos\n");
	}
	else{
		node *p = head;
		while(p != NULL){
			printf("Ogrencinin adi ve soyadi: %s %s \t No: %d \n",p->isim,p->soyad,p->no);
			
			p = p->next;
		}
	}
	return head;
}
node * search(node*head){
	int ogrno;
	printf("Bulmak istediginiz ogrencinin numarasi: ");
	scanf("%d",&ogrno);
	node *s = head;
	while(s !=NULL){
		if(s->no == ogrno){
			printf("Ogrencinin adi ve soyadi: %s %s \t No: %d",s->isim,s->soyad,s->no);
			break;
		}
		s = s->next;
	}	printf("\n");
	return head;
}
	node *head = NULL;
int main(){
	node *ilk = (node *)malloc(sizeof(node));
	node *ikinci = (node*)malloc(sizeof(node));
	ilk -> no = 123456;
	strcpy(ilk ->isim,"serpil");
	strcpy(ilk ->soyad,"ustebay");
	head = ilk;
	ilk -> next = ikinci;
	ikinci -> no = 123457;
	strcpy(ikinci->isim,"ayse");
	strcpy(ikinci->soyad,"gul");
	ikinci -> next = NULL;
	int select;

	while(1){
		printf("1)Ogrenci Ekle \n2)Ogrenci Sil\n3)Ogrenci Ara\n4)Ogrencileri goruntule");
		printf("\nYapacaginiz islemi seciniz: ");
		scanf("%d",&select);
		switch(select){
			case 1: head = ekle(head);
			break;
			case 2: head = sil(head);
			break;
			case 3: head = search(head);
			break;
			break;
			case 4: head = print(head);
			break;
			default : printf("Hatali secim\n");
		}
	}
	return 0;
}
