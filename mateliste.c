#include <stdio.h>
#include <stdlib.h>
#include "mateliste.h"





/**********************************/
/*        FUNZIONI MATRICI        */
/**********************************/

/*Funzione che inserisce un elemento in una lista doppiamente concatenata;*/
/*Prende come parametri un puntatore ad una lista di un grafo con liste di adiacenza*/
/*(percui prende g_out->adiacenti[i] del nodo i-esimo) e un intero j, info del nodo*/
/*adiacente al nodo i-esimo*/
void inserisci_in_lista(elist** puntatore_lista, int j){
    /*alloco memoria per un nuovo elist*, non un elist: questo perchè la lista è */
    /*somposta da puntatori */
    elist* new_edge = (elist*) malloc (sizeof(elist));
    new_edge->prev = NULL;
    new_edge->info = j;
    new_edge->next = (*puntatore_lista);
    if((*puntatore_lista) != NULL)
        (*puntatore_lista)->prev = new_edge;
    (*puntatore_lista) = new_edge;
}


/*Funzione che cambia rappresentazione: da Matrice ----> a Liste*/
grafo_liste* LISTE(grafo_matrice* gm){
    /*alloco memoria per un puntatore ad un grafo rappresentato con liste di adiacenza*/
    grafo_liste* gl = (grafo_liste*) malloc(sizeof(grafo_liste));
    
    /*il numero di nodi del grafo con le liste è uguale a quello della matrice*/
    gl->numero_nodi = gm->numero_nodi;
    
    /*l'array di liste di adiacenza ha dimensione pari al numero di nodi*/
    gl->adiacenti = (elist**) calloc(gl->numero_nodi,sizeof(elist*));
    
    for(int i=0; i<gl->numero_nodi; i++){
        for(int j=0; j<gl->numero_nodi; j++){
            if(gm->matrice[i][j] == 1){
                inserisci_in_lista(&(gl->adiacenti[i]), j);
            }
        }
    }
    return gl;
}


/*Funzione che stampa un grafo*/
void stampa_grafo(grafo_matrice* gm){
    for(int i=0; i<gm->numero_nodi; i++){
        for(int j=0; j<gm->numero_nodi; j++){
            if(i==0 && j==0)    printf("   ");
            else{
                if(j==0) printf("[%d]", i);
                else{
                    if(i==0)    printf("[%d]", j);
                    else    printf(" %d ", gm->matrice[i][j]);
                }
            }
        }
        printf("\n");
    }
}


/*Funzione che restituisce il grado di uscita di un nodo (con Matrice)*/
int grado_di_uscita(grafo_matrice* gm, int nodo){
    int cont = 0;
    for(int j=1; j<gm->numero_nodi; j++){
        if(gm->matrice[nodo][j] == 1) cont++;
    }
    return cont;
}


/*Funzione che restituisce il grado di ingresso di un nodo (con Matrice)*/
int grado_di_ingresso(grafo_matrice* gm, int nodo){
    int cont = 0;
    for(int i=1; i<gm->numero_nodi; i++){
        if(gm->matrice[i][nodo] == 1)   cont++;
    }
    return cont;
}


/*Funzione che restituisce il grado di ingresso di un grafo*/
float grado_uscita_medio(grafo_matrice* gm){
    int cont = 0;
    for(int i=1; i<gm->numero_nodi; i++)
        cont += grado_di_uscita(gm, i);
    float sum = (float)cont/((float)gm->numero_nodi-1);
    return sum;
}


/*Funzione che verifica se il grafo è semplice (privo di cappi)*/
int grafo_semplice(grafo_matrice* gm){
    for(int i=0; i<gm->numero_nodi; i++){
        if(gm->matrice[i][i] == 1)  return 0;
    }
    return 1;
}





/****************************/
/*      FUNZIONI LISTE      */
/****************************/

/*Funzione che cambia rappresentazione: da Liste ----> a Matrice*/
grafo_matrice* MATRICE(grafo_liste* gl){
    /*creo la matrice di adiacenza*/
    grafo_matrice* gm = (grafo_matrice*) malloc(sizeof(grafo_matrice));
    gm->numero_nodi = gl->numero_nodi;
    gm->matrice = (int**) calloc(gl->numero_nodi, sizeof(int*));
    for(int i=0; i<gl->numero_nodi; i++){
        gm->matrice[i] = (int*) calloc(gl->numero_nodi, sizeof(int));
    }
    for(int i=0; i<gm->numero_nodi; i++){
        elist* scorri_lista = gl->adiacenti[i];
        while(scorri_lista != NULL){
            gm->matrice[i][scorri_lista->info] = 1;
            scorri_lista = scorri_lista->next;
        }
    }
    return gm;
}


/*Funzione che restituisce il grado di uscita di un nodo (con Liste)*/
int grado_di_uscita_liste(grafo_liste* gl, int nodo){
    int cont = 0;
    elist* scorri_lista = gl->adiacenti[nodo];
    while(scorri_lista != NULL){
        cont++;
        scorri_lista = scorri_lista->next;
    }
    return cont;
}


/*Funzione che restituisce il grado di ingresso di un nodo (con Liste)*/
int grado_di_ingresso_liste(grafo_liste* gl, int nodo){
    int cont = 0;
    for(int i=0; i<gl->numero_nodi; i++){
        elist* scorri_lista = gl->adiacenti[i];
        while(scorri_lista != NULL){
            if(scorri_lista->info == nodo)  cont++;
            scorri_lista = scorri_lista->next;
        }
    }
    return cont;
}


/*Funzione che restituisce il grado di uscita medio di un grafo*/
float grado_uscita_medio_liste(grafo_liste* gl){
    int cont = 0;
    for(int i=0; i<gl->numero_nodi; i++){
        elist* scorri_lista = gl->adiacenti[i];
        while(scorri_lista != NULL){
            cont++;
            scorri_lista = scorri_lista->next;
        }
    }
    return (float)cont / ((float)gl->numero_nodi-1);
}


/*Funzione che verifica l'esistenza di un arco dal nodo u al nodo v*/
int verifica_arco(grafo_liste* gl, int nodo_u, int nodo_v){
    elist* scorri_lista = gl->adiacenti[nodo_u];
    while(scorri_lista != NULL){
        if(scorri_lista->info == nodo_v)    return 1;
        scorri_lista = scorri_lista->next;
    }
    return 0;
}


/*Funzione che stampa un grafo (con Liste)*/
void stampa_grafo_liste(grafo_liste* gl){
	printf("\n\n");
	for(int i=1; i<gl->numero_nodi; i++){
		printf("[%d]----->", i);
		elist* scorri_lista = gl->adiacenti[i];
		while(scorri_lista != NULL){
			printf("[%d]-->", scorri_lista->info);
			scorri_lista = scorri_lista->next;
		}
		printf("\n|");
		printf("\n|");
		printf("\n\\/\n");
	}
}


/*Funzione che verifica se un grafo è orientato*/
int verifica_non_orientato(grafo_liste* gl){
	for(int i=1; i<gl->numero_nodi; i++){
		elist* scorri_lista = gl->adiacenti[i];
		while(scorri_lista != NULL){
			if(!verifica_arco(gl, scorri_lista->info, i))	return 0;
			scorri_lista = scorri_lista->next;
		}
	}
	return 1;
}


/*Funzione che verifica se un nodo non ha archi uscenti (è un pozzo)*/
int verifica_pozzo(grafo_liste* gl, int nodo){
	return (gl->adiacenti[nodo] == NULL);
}


/*Funzione che verifica se un nodo non ha archi entranti (è una sorgente)*/
int verifica_sorgente(grafo_liste* gl, int nodo){
	for(int i=0; i<gl->numero_nodi; i++){
		elist* scorri_lista = gl->adiacenti[i];
		while(scorri_lista != NULL){
			if(scorri_lista->info == nodo)	return 0;
			scorri_lista = scorri_lista->next;
		}
	}
	return 1;
}