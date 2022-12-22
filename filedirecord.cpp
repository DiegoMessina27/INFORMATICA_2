/***********************************************************
* @author <Diego Messina>
* @date <1/12/22> 
* @version 1.0 <1/12/22> Versione iniziale
*/

//inserimento librerie
#include <stdio.h>
#include <stdlib.h >
#include <time.h>
#include <string.h>


#define M 20	//mese
#define V 8 	//voti
#define C 40	//cognome
#define N 2

struct s_data
{
	int giorno;
	char mese[M];
	int anno;
}typedef s_data;

struct s_alunno
{
	char cognome[C];
	int voti[V];
	s_data nascita;

}typedef s_alunno;

int menu();
void carica(char [], int );
void stampaF(char [], int );
void ricerca(char [], int );
int stampaR(char [], int );
void correzione(char [], int );
int quantita(char [], int);

int main()
{

	char nome[]={"record.txt"},cognome[C];		//assegna alla stringa il nome del file 
	int dim,s,q;
	
	printf("quanti studenti vanno messi nel file?");
	scanf("%d",&dim);
	
	do
	{
	
	s=menu();		
	switch(s)
	{
		case 0:
		printf("chiusura del programma...");
		break;
		
		case 1:
			carica(nome, dim);
		break;
		
		case 2:
//			stampaF(nome, dim);
		break;		
		
		case 3:
//			printf("inserisci un cognome da cercare");
//			scanf("%s",cognome);
//			ricerca(nome, dim);
		break;		
		
		case 4:
//			stampaR(nome,dim);
		break;
		
		case 5:
//			correzione(nome, dim); 
		break;
		
		case 6:
//			q=quantita(nome, dim);	
		break;		
	}





	}while(s!=0);
	
	return 0;
}

int menu()
{
	int scelta;
	do{
		printf("1: carica il file\n");
		printf("2: stampa il file\n");
		printf("3: cerca il record\n");
		printf("4: stampa record\n");
		printf("5: correggi record\n");
		printf("6: numero dei record\n");
		printf("0: Chiudi il programma\n");
		scanf("%d", &scelta);
		if(scelta<0 ||scelta>6)
			printf("Errore! Opzione non disponibile");
	}while(scelta<0 ||scelta>6);
	return scelta;
}

void carica(char st[], int dim)
{
	s_alunno buffer;
	int i,j;
	FILE *File; 		//dichiara i puntatori
	
	File=fopen(st,"r"); 		//apre il file iniziale in read (lettura)
	for(i=0;i<N;i++)
	{
		fwrite(&buffer,sizeof(struct s_alunno),1,File);
		//inserimento della stringa come cognome
		printf("inserire il cognome dello studente.\n");
		scanf("%s",buffer.cognome);
		//inserimento voti
		for(j=0;j<V;j++)
			buffer.voti[j]=rand()%9+2;
		//inserimento data di nascita 
		printf("inserire la data di nascita:\n");
		scanf("%d",&buffer.nascita.giorno);
		scanf("%s",buffer.nascita.mese);
		scanf("%d",&buffer.nascita.anno);
	}
}
void stampa(char st[], int dim)
{
	
}
void ricerca(char st[],char cognome[], int dim)
{
	
}
void correzione(char st[], int dim)
{
	
}
int quantita(char st[], int dim)
{
	
}
