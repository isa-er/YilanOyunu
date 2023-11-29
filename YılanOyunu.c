#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define N 20
#define M 60

void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

int duraklatma_sayisi=0;

int main(){
	
	//double sec;
    //time_t time1, time2;
    //time(&time1);

char oyuncu_ismi[10];

	FILE *ptr;
	ptr=fopen("snake_game.txt","w");

int yenilen_yem_sayisi=0;	
int yilanin_kendi_uzerinden_gecme_sayisi=0;  
int random_x,random_y,b;
int kuyruksatir[100];
int kuyruksutun[100];

int randomyem(){
	srand(time(0));
	random_x=4+rand()%50;
	random_y=4+rand()%14;
		
		if(       (random_x==35 && random_y==13) || (random_x==36 && random_y==13) || (random_x==37 && random_y==13)|| (random_x==38 && random_y==13)|| (random_x==39 && random_y==13) || 
		
		(random_x==35 && random_y==16) || (random_x==36 && random_y==16) || (random_x==37 && random_y==16)|| (random_x==38 && random_y==16)|| (random_x==39 && random_y==16) || 
		
		(random_x==15 && random_y==5) || (random_x==15 && random_y==6) || (random_x==15 && random_y==7) || (random_x==21 && random_y==5) || (random_x==15 && random_y==6) ||(random_x==15 && random_y==7)  ){

	
	random_x++;   // engel ustunde yem cıkarsa,yemin yerini degistirir
	random_y++;		
		}	
}

	struct hiz{		
		char s[6];
		char oyuncu_ismi[10];
	};
	struct hiz h;
	randomyem();
	
	int i,j;
	for(i=0;i<=M+1;i++){
        if(i==0){
            printf("%c",201);
        }else if(i==M+1){
            printf("%c",187);
        }else{
            printf("%c",205);
        }
    }
    printf("\n");
    
    for(i=0;i<N;i++){
            printf("%c",186);
        for(j=0;j<M;j++){
        	if(j==M-1){
        		printf(" %c\n",186);
			}
			else{
				printf(" ");		
			}
		}
    	
	}  
	for(i=0;i<=M+1;i++){
        if(i==0){
            printf("%c",200);
        }else if(i==M+1){
            printf("%c",188);
        }else{
            printf("%c",205);
        }
    }
    
    
    gotoxy(35,13);
    printf("%c%c%c%c%c",205,205,205,205,205);
    gotoxy(35,16);
    printf("%c%c%c%c%c",205,205,205,205,205);
    
    gotoxy(15,5);
    printf("%c",186);
    gotoxy(15,6);
    printf("%c",186);
    gotoxy(15,7);
    printf("%c",186);
    
    gotoxy(21,5);
    printf("%c",186);
    gotoxy(21,6);
    printf("%c",186);
    gotoxy(21,7);
    printf("%c",186);

    int hiz;
	gotoxy(65,10);
	printf("Lutfen Oyun Hizinizi Seciniz:\n");
	gotoxy(65,11);
	printf("1.YAVAS");
	gotoxy(65,12);
	printf("2.ORTA");
	gotoxy(65,13);
	printf("3.HIZLI");
	scanf("%d",&hiz);
	gotoxy(65,14);
	printf("oyuncu adi:");
	scanf("%s",&h.oyuncu_ismi);
	
	if(hiz==1)
	strcpy(h.s,"YAVAS");
	if(hiz==2)
	strcpy(h.s,"ORTA");
	if(hiz==3)
	strcpy(h.s,"HIZLI");
	
	gotoxy(65,10);
	printf("                              ");
	gotoxy(65,11);
	printf("        ");
	gotoxy(65,12);
	printf("        ");
	gotoxy(65,13);
	printf("        ");
	gotoxy(65,14);
	printf("               ");

    char basilan;
    int x_koordinati=30;
    int y_koordinati=10;
    int y=0;
    int x=0;
 	
	do{	
		if(kbhit()){   // tusa basilmissa
			basilan=getch();
    			switch(basilan){
    				case 119:
    					y=-1;
    					x=0;
    					break;
    				case 97:
    					y=0;
    					x=-1;
    					break;
    				case 115:
    					y=1;
    					x=0;
    					break;
    				case 100:
    					y=0;
    					x=1;
    					break;
					case 112:   // pause 

					for(i=0;i<yenilen_yem_sayisi+1;i++){
						gotoxy(kuyruksutun[i],kuyruksatir[i]);
						printf("*");
														}

					for(i=5;i>0;i--){
						gotoxy(65,11);
						printf("%d SANIYE KALDI!!!",i);
						Sleep(1000);
						gotoxy(65,11);
						printf("                    ");
						
					}

					duraklatma_sayisi++;
					break;								   		
		}	
    	
	}
	
	x_koordinati=x_koordinati+x;                // x_koordinati= guncel x koordinat , x=basilan tus sonucu x_koordinati i etkiliyor
	y_koordinati=y_koordinati+y;
		
	kuyruksatir[0]=y_koordinati;
	kuyruksutun[0]=x_koordinati;
	
	for(i=1;i<=yenilen_yem_sayisi;i++){      // yilan kendi uzerinden hareekt etti
		if(x_koordinati==kuyruksutun[i] && y_koordinati==kuyruksatir[i]){
			yilanin_kendi_uzerinden_gecme_sayisi++;
	
		}			
	}

		gotoxy(x_koordinati,y_koordinati);
     	printf("*");
	
     	for(b=0;b<=yenilen_yem_sayisi;b++){
     		gotoxy(kuyruksutun[b],kuyruksatir[b]);
     		printf("*");
			}
			
			
     	if(x_koordinati==random_x && y_koordinati==random_y){	 	
		randomyem();
	
		for(b=0;b<=yenilen_yem_sayisi;b++)
		if(random_x==kuyruksutun[b] &&   random_y==kuyruksatir[b]){
			random_x++;         // yilan uzerinde yem dogmasini engelliyor
			random_y++;
		}

		gotoxy(65,5);
		printf("***********OYUN BILGILERI************");
		gotoxy(65,7);
		printf("%s modda oynuyorsunuz.",h.s);
		gotoxy(65,8);
		printf("___________________");
		gotoxy(65,9);
		printf("Yenilen Yem Sayisi:%d",(yenilen_yem_sayisi+1));
		gotoxy(65,10);
		printf("____________________");
		yenilen_yem_sayisi++;
	}

	gotoxy(random_x,random_y);
	printf("%c",248);
     	Sleep(180/hiz);         
     	gotoxy(x_koordinati,y_koordinati);
		printf(" ");
		
		for(b=0;b<=yenilen_yem_sayisi;b++){
     		gotoxy(kuyruksutun[b],kuyruksatir[b]);
     		printf(" ");
			}
		
		for(b=yenilen_yem_sayisi;b>0;b--){
			kuyruksutun[b]=kuyruksutun[b-1];
			kuyruksatir[b]=kuyruksatir[b-1];
		}

			
	}  while( x_koordinati<61 && x_koordinati>2  && y_koordinati<22 && y_koordinati>1 &&   (x_koordinati!=35 || y_koordinati!=13 )   &&   (x_koordinati!=36 || y_koordinati!=13 )  &&(x_koordinati!=37 || y_koordinati!=13 ) &&(x_koordinati!=38 || y_koordinati!=13 )  &&(x_koordinati!=39 || y_koordinati!=13 ) &&
		
	(x_koordinati!=35 || y_koordinati!=16 )   &&   (x_koordinati!=36 || y_koordinati!=16 )  &&(x_koordinati!=37 || y_koordinati!=16 ) &&(x_koordinati!=38 || y_koordinati!=16 )  &&(x_koordinati!=39 || y_koordinati!=16 )   
	
	
	&&(x_koordinati!=15 || y_koordinati!=5) &&(x_koordinati!=15 || y_koordinati!=6) &&(x_koordinati!=15 || y_koordinati!=7) &&(x_koordinati!=21 || y_koordinati!=5) &&(x_koordinati!=21 || y_koordinati!=6) &&(x_koordinati!=21 || y_koordinati!=7)
	
	  );
	gotoxy(65,14);
	printf("***************OYUN OZETI*************");
	gotoxy(80,12);
	printf("GAME OVER !!!\n\n\n");
	gotoxy(65,16);
	printf("%d Kez Yilaniniz Kendine Degdi.%d Puan Ceza kesildi",yilanin_kendi_uzerinden_gecme_sayisi,(yilanin_kendi_uzerinden_gecme_sayisi*2));
	gotoxy(65,18);
	printf("SKOR:%dPUAN ILE BITIRDINIZ...",(yenilen_yem_sayisi*5)-(yilanin_kendi_uzerinden_gecme_sayisi*2));
	gotoxy(65,20);
	printf("Cikmak Icin \"q\" ya Basiniz."); 
	char cikis=getch();
	if(cikis==113){
	gotoxy(65,21);
	printf("OYUN SONLANDIRILDI");
	
}
	
	fprintf(ptr,"%s Adli Oyuncunun Oyun Ozeti\n",h.oyuncu_ismi);
	fprintf(ptr,"%s modda oynadi\n",h.s);
	fprintf(ptr,"%d kez yilani kendi uzerinden oynatmaya calisti\n",yilanin_kendi_uzerinden_gecme_sayisi);
	fprintf(ptr,"%d tane yem yedi\n",yenilen_yem_sayisi);
	fprintf(ptr,"oyunu %d kez durdurdu\n",duraklatma_sayisi);
	fprintf(ptr,"toplam puani:%d",(yenilen_yem_sayisi*5)-(yilanin_kendi_uzerinden_gecme_sayisi*2));
	 	//time(&time2);
	gotoxy(65,22);
	//printf("Difference is %.2lf seconds",
           //difftime(time2, time1));
	
return 0; 
}
