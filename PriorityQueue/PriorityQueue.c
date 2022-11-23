#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // M��teri say�s� = pri_que.length
void musteriEkle(int);
void create();
void showQueue();
void showPQueue();
int pri_que[MAX];
int front, rear;
 void main()
{
    int n, ch;
    create();
    while (1)
    {	
		printf("\n--------------------------");
   		printf("\n1 - Musteri Ekleme");
   		printf("\n2 - Gelen Musteri Sirasini Gorme");
   		printf("\n3 - Kuyruk Sirasini Gorme");
		printf("\n4 - Cikis");
 		printf("\n--------------------------");
 		printf("\nYapmak istediginiz islemi seciniz : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\n1-Kurumsal islem yapan musteri\n2-Bireysel islem yapan musteri\n3-65 yas ve uzeri musteri\nEklemek istediginiz musterinin numarasini seciniz : ");
            scanf("%d",&n);
            musteriEkle(n);
            break;
        case 2:
        	printf("Gelen Musteri sirasi: ");
            showQueue();
            break;
        case 3:
        	printf("Oncelikli Kuyruk sirasi: "); // �ncelik s�ras� = 65 ya� ve �zeri m��teri (3)  > Kurumsal m��teri (1) > Bireysel m��teri (2)
			showPQueue();
			break;    
        case 4: 
            exit(0);
        default: 
            printf("\n Hatali secim");
        }
    }
}
 void create()
{
    front = rear = -1;
}
 void musteriEkle(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\n !Bankanin musteri kapasitesi doldu !");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }    
    else
        pri_que[rear+1] = data;
    rear++;
}
void showQueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nKuyruk Bos");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }
 
    front = 0;
}
void showPQueue(){
	int i,j;
	for(i=0;i<MAX;i++){ // Bubble sort ile dizi 3 2 1 �eklinde s�raland�
            for(j=0;j<MAX;j++){
                  if(pri_que[j]<=pri_que[i]){
                        int tmp;
						tmp=pri_que[i];  
                        pri_que[i]=pri_que[j];
                        pri_que[j]=tmp;
                        }
                  }
            }
    for(i = 0; i < MAX; i++){ // Kurumsal m��terilerin(1) ,kendilerinden �nce mutlaka en az iki bireysel m��teri (2) olmak zorundad�r ko�ulunu sa�layan k�s�m 
		if(pri_que[i]==2 && pri_que[i+1]==2){
    		int tmp;
    		tmp = pri_que[i+2];
			pri_que[i+2]= pri_que[i+3];
			pri_que[i+3] = tmp;
    		
		}
        printf("%d  ", pri_que[i]);
	}
}
