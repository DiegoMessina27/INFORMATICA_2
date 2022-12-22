/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <programma che contiene cinque funzione                                           *
*	la prima che carica il file di record;                                             *
*	il secondo lo stampa;                                                              *
*	la terza che cerca un cognome e stampa;                                            *
*	la quarta corregge con il cognome di un record con un altro;                       *
*	la quinta restituisce il numero di record nel file;                                *
*                                                                                          *
* @author <Diego Messina>                                                                  *
* @date <21/11/22>                                                                         *
* @version 1.0 <21/11/22>                                                                  *
*                                                                                          *
*******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define M 20
#define C 20
#define V 10
#define N 2


struct s_data 
{
	int gg;
	char mese[M];
	int aa;
}typedef s_data;


struct s_stud
{
	char cog[C];
	char voti[V];
	s_data nascita;
}typedef s_stud;



void carica(char [], int );
void stampaF(char [], int );
void ricerca(char [], char [],int );
void correzione(char [], int );
int stampaR(char [], int, int );
int quantita(char [], int);

int main()
{

	char nome[]={"record.dat"},cog[C];		//assegna alla stringa il nome del file 
	int dim=1,scelta,q,num;
	srand(time(NULL));

	printf("quanti studenti vanno messi nel file?");
	scanf("%d",&dim);
	
	do
	{
		printf("1 per caricare il file \n");
		printf("2 per stampare il file \n");	
		printf("3 per cercare un cognome nel file \n");
		printf("4 per stampare le informazioni di un studente \n");			
		printf("5 per correggere i dati di un record \n");		
		printf("6 per calcolare il numero di record nel file \n");
		printf("0 per terminare il programma \n");
		scanf("%d",&scelta);
				
	switch(scelta)
	{
		case 0:
		printf("chiusura del programma...");
		break;
		
		case 1:
			carica(nome, dim);
		break;
		
		case 2:
			stampaF(nome, dim);
		break;		
		
		case 3:
			printf("inserisci un cognome da cercare");
			scanf("%s",cog);
			ricerca(nome, cog, dim);
		break;		
		
		case 4:
		correzione(nome, dim); 
		break;
				
		case 5:
			printf("che record vuoi stampare");
			stampaR(nome,num,dim);
		break;
		

		
		case 6:
			q=quantita(nome, dim);	
		break;		
	}





	}while(scelta!=0);
	
	return 0;
}

/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che permette di caricare un file di record>                             *
*                                                                                          *
* @author <Diego Messina>                                                                  *
* @date <21/11/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
void carica(char st[], int dim)
{
	s_stud buffer[dim];
	int i,j,n;
	FILE *File; 		//dichiara i puntatori
	
	srand(time(NULL));
	
	File=fopen(st,"ab"); 		//apre il file iniziale in read (append)
	if(File!=NULL)
	{
		for(i=0;i<dim;i++)
		{
			//inserimento della stringa come cognome
			printf("inserire il cognome dello studente.\n");
			scanf("%s",buffer[i].cog);
			//inserimento voti
			for(j=0;j<V;j++)
				buffer[i].voti[j]=rand()%10;
			//inserimento data di nascita 
			printf("inserire la data di nascita:\n");
			scanf("%d",&buffer[i].nascita.gg);
			scanf("%s",buffer[i].nascita.mese);
			scanf("%d",&buffer[i].nascita.aa);
			printf("\n");
			fwrite(&buffer,sizeof(struct s_stud),dim,File);
		}
		fclose(File);
	}

}


/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che stampa tutti i recorde un file>                                     *
*                                                                                          *
* @author <Diego Messina>                                                                  *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
void stampaF(char st[], int dim)
{
	s_stud buffer[dim];
	int i,j,n;
	FILE *File; 		//dichiara i puntatori
	
	File=fopen(st,"rb"); 		//apre il file iniziale in read (lettura)

	
		for(i=0;i<dim;i++)
		{
			n=fread(buffer,sizeof(struct s_stud),dim,File);
			printf("lo studente %s ",buffer[i].cog);
			printf("i voti dello studente\n");
			
			for(j=0;j<V;j++)
				printf("%d ",buffer[i].voti[j]);
				printf("\n");
			printf("e nato il:");
			printf("%d / ",buffer[i].nascita.gg);
			printf("%s / ",buffer[i].nascita.mese);
			printf("%d \n",buffer[i].nascita.aa);
			printf("\n");
		}
		fclose(File);
	}

/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <cerca il cognome e lo stampa a schermo>                                          *
*                                                                                          *
* @author <Diego Messina>                                                                  *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/	

void ricerca(char st[],char cognome[], int dim)
{
	s_stud buffer;
	int i,n,r,eta;
	float media=0;
	FILE *File; 		//dichiara i puntatori
	
	srand(time(NULL));
	
	File=fopen(st,"rb"); 		//apre il file iniziale in read 
	n=fread(&buffer,sizeof(struct s_stud),1,File);	
	r=strcmp(buffer.cog,cognome);
		if(r==0)
		{
		for(i=0;i<V;i++)
		{
			media+=buffer.voti[i];
		}
		media=media/i;
		eta=2022-buffer.nascita.aa;
		printf("\nlo studente %s ha %d anni \n",buffer.cog,eta);
		printf("la media dei suoi voti %f\n",media);
		media=0;
		fclose(File);
		}
	}



/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che stampa le informazioni presenti in un record>                       *      
*          <restituendo 0 se è presente,-1 se non esistente>                               *
*                                                                                          *
* @author <Diego Messina>                                                                  *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
int stampaR(char st[], int dim, int indice)
{
	s_stud buffer[dim];
	int i,n,j;
	float media=0;
	FILE *File; 		//dichiara i puntatori
	
	File=fopen(st,"rb"); 	//apre il file iniziale in read 
	
	for(i=0;i<dim;i++)
	{
		if(i==indice)
		{
			n=fread(buffer,sizeof(struct s_stud),1,File);	
			printf("stampa del record di indice %d",indice);
			printf("lo studente %s ",buffer[i].cog);
			printf("i voti dello studente\n");
			
			for(j=0;j<V;j++)
			{
				printf("%d ",buffer[i].voti[j]);
			}
			printf("\n");
			printf("e nato il:");
			printf("%d / ",buffer[i].nascita.gg);
			printf("%s / ",buffer[i].nascita.mese);
			printf("%d \n",buffer[i].nascita.aa);
			printf("\n");
		}
			fclose(File);
	}
	
}

/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che corregge un record richiesto dall'utente>                           *
*                                                                                          *
* @author <Diego Messina>                                                                  *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
void correzione(char st[], int dim,int num)
{
	s_stud buffer[dim];
	int i,n,j;

	FILE *File; 		//dichiara i puntatori
	
	srand(time(NULL));
	
	File=fopen(st,"rb"); 		//apre il file iniziale in read 

		for(i=0;i<dim;i++)
		{
			n=fread(buffer,sizeof(struct s_stud),dim,File);	
			if(i==num)
			{
				printf("inserisci le nuove informazioni:\n");
				printf("nuovo cognome:\n");
				scanf("%s",buffer[i].cog);

				for(j=0;j<V;j++)
				{
					buffer[i].voti[j]=rand()%10;
				}
				printf("\n");
				printf("inserire la nuova data di nascita:\n");
				scanf("%d",&buffer[i].nascita.gg);
				scanf("%s",buffer[i].nascita.mese);
				scanf("%d",&buffer[i].nascita.aa);
			}
			fwrite(&buffer,sizeof(struct s_stud),dim,File);
		}
			fclose(File);

}

/*******************************************************************************************
* \mainpage <file_record.c>                                                                *
*                                                                                          *
* @brief <funzione che restituisce il numero di record nel file>                           *
*                                                                                          *
* @author <Diego Messina>                                                                  *
* @date <21/12/22>                                                                         *
* @version 1.0 <21/12/22> Versione iniziale                                                *
*******************************************************************************************/
int  quantita ( char st[], int dim)
{
	s_stud buffer[dim];										// dichiarazione  record
	int fs,ft,numr;											//fs=fseek / ft=ftell / mentre numr sono i record nel file
	int n= sizeof (buffer[dim-1]);									//n dice quanti byte occupa lo struct
	FILE* File;											
    File= fopen (st,"rb");									
	if (File!= NULL )										 
	{
		fs=fseek (File,0,2);								// il puntatore viene messo alla fine del file
		ft=ftell (File);										// restituisce la posizione del puntatore
		numr=ft/n;											// divido ft con n per trovare quanti record sono
		fclose (File);										// chiusura del file
		return numr;
	}
	else 	
	{
		printf ( "file non esistente \n " );
		return - 1 ;
	}
}
