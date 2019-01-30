#ifndef MATELIST_H
#define MATELIST_H

/************************************/
/*      DICHIARAZIONE STRUCT        */
/************************************/

/*Questa è la struttura degli elementi della matrice di (numero_nodi)*(numero_nodi) celle*/
typedef struct struttura_grafo_matrici{
    int numero_nodi;
    int** matrice;
}grafo_matrice;

/*Questa è la struttura degli elementi della lista di adiacenza: l'info contiene i nodi*/
typedef struct elemento_della_lista{
    struct elemento_della_lista* next;
    struct elemento_della_lista* prev;
    int info;
}elist;

/*Questa è la struttura del grafo fatto con liste di adiacenza*/
typedef struct struttura_grafo_liste{
    int numero_nodi;        //devo sapere il numero di nodi per allocare un array di nodi
    elist** adiacenti;      //array di lun=num_nodi i cui elementi sono puntatori a liste
}grafo_liste;




/**********************************/
/*        FUNZIONI MATRICI        */
/**********************************/

/*Funzione che cambia rappresentazione: da Matrice ----> a Liste*/
grafo_liste* LISTE(grafo_matrice* gm);

/*Funzione che stampa un grafo*/
void stampa_grafo(grafo_matrice* gm);

/*Funzione che restituisce il grado di uscita di un nodo (con Matrice)*/
int grado_di_uscita(grafo_matrice* gm, int nodo);

/*Funzione che restituisce il grado di ingresso di un nodo (con Matrice)*/
int grado_di_ingresso(grafo_matrice* gm, int nodo);

/*Funzione che restituisce il grado di uscita medio di un grafo*/
float grado_uscita_medio(grafo_matrice* gm);

/*Funzione che verifica se il grafo è semplice (privo di cappi)*/
int grafo_semplice(grafo_matrice* gm);

/****************************/
/*      FUNZIONI LISTE      */
/****************************/

/*Funzione che cambia rappresentazione: da Liste ----> a Matrice*/
grafo_matrice* MATRICE(grafo_liste* gl);

/*Funzione che restituisce il grado di uscita di un nodo (con Liste)*/
int grado_di_uscita_liste(grafo_liste* gl, int nodo);

/*Funzione che restituisce il grado di ingresso di un nodo (con Liste)*/
int grado_di_ingresso_liste(grafo_liste* gl, int nodo);

/*Funzione che restituisce il grado di uscita medio di un grafo*/
float grado_uscita_medio_liste(grafo_liste* gl);

/*Funzione che verifica l'esistenza di un arco dal nodo u al nodo v*/
int verifica_arco(grafo_liste* gl, int nodo_u, int nodo_v);

/*Funzione che stampa un grafo (con Liste)*/
void stampa_grafo_liste(grafo_liste* gl);

/*Funzione che verifica se un grafo è orientato*/
int verifica_non_orientato(grafo_liste* gl);

/*Funzione che verifica se un nodo non ha archi uscenti (è un pozzo)*/
int verifica_pozzo(grafo_liste* gl, int nodo);

#endif

