#include <stdio.h>
#include <stdlib.h>
#include "mateliste.h"
#include "mateliste.c"


int main(){
    /*Alloco memoria per il grafo rappresentato da una matrice*/
    grafo_matrice* gm = (grafo_matrice*) malloc (sizeof(grafo_matrice));
    
    /*inizializzo il numero di nodi a 6*/
    gm->numero_nodi = 7;
    /*alloco esattamente (numero_nodi) righe della matrice (in questo caso 6)*/
    gm->matrice = (int**) calloc(gm->numero_nodi,sizeof(int*));
    
    for(int i=0; i<gm->numero_nodi; i++){   //per ognuna di esse, alloco (numero_nodi) colonne (6)
        gm->matrice[i] = (int*) calloc(gm->numero_nodi,sizeof(int));
    }
    /*assegno alcuni valori*/
    gm->matrice[1][4] = 1;
    gm->matrice[5][1] = 1;
    gm->matrice[5][4] = 1;
    gm->matrice[4][5] = 1;
    gm->matrice[3][5] = 1;
    gm->matrice[4][3] = 1;
    gm->matrice[4][2] = 1;
    gm->matrice[2][4] = 1;
    gm->matrice[5][3] = 1;
    //gm->matrice[6][6] = 1;
	
    stampa_grafo(gm);
    
    
    printf("\nIl grado di uscita del nodo 1 è: %d (atteso: 1)", grado_di_uscita(gm, 1));
    printf("\nIl grado di uscita del nodo 2 è: %d (atteso: 1)", grado_di_uscita(gm, 2));
    printf("\nIl grado di uscita del nodo 3 è: %d (atteso: 1)", grado_di_uscita(gm, 3));
    printf("\nIl grado di uscita del nodo 4 è: %d (atteso: 3)", grado_di_uscita(gm, 4));
    printf("\nIl grado di uscita del nodo 5 è: %d (atteso: 3)", grado_di_uscita(gm, 5));
    printf("\nIl grado di uscita del nodo 6 è: %d (atteso: 1)\n", grado_di_uscita(gm, 6));
    
    printf("\nIl grado di entrata del nodo 1 è: %d (atteso: 1)", grado_di_ingresso(gm, 1));
    printf("\nIl grado di entrata del nodo 2 è: %d (atteso: 1)", grado_di_ingresso(gm, 2));
    printf("\nIl grado di entrata del nodo 3 è: %d (atteso: 2)", grado_di_ingresso(gm, 3));
    printf("\nIl grado di entrata del nodo 4 è: %d (atteso: 3)", grado_di_ingresso(gm, 4));
    printf("\nIl grado di entrata del nodo 5 è: %d (atteso: 2)", grado_di_ingresso(gm, 5));
    printf("\nIl grado di entrata del nodo 6 è: %d (atteso: 1)\n", grado_di_ingresso(gm, 6));
    
    printf("\nIl grado di uscita medio è: %f (atteso: 1,667)\n", grado_uscita_medio(gm));
    
    if(grafo_semplice(gm))  printf("\nIl grafo è semplice;\n");
    else    printf("\nIl grafo NON è semplice;\n");
    
    /*Alloco memoria per un puntatore ad un grafo rappresentato con liste di adiacenza*/
    printf("\n\n\n\n\n\n\nCreo un grafo rappresentato con liste di adiacenza;");
    grafo_liste* gl = LISTE(gm);
    printf("\nFatto!");
    
    printf("\nIl grado di uscita di %d è %d;", 1, grado_di_uscita_liste(gl, 1));
    printf("\nIl grado di uscita di %d è %d;", 2, grado_di_uscita_liste(gl, 2));
    printf("\nIl grado di uscita di %d è %d;", 3, grado_di_uscita_liste(gl, 3));
    printf("\nIl grado di uscita di %d è %d;", 4, grado_di_uscita_liste(gl, 4));
    printf("\nIl grado di uscita di %d è %d;", 5, grado_di_uscita_liste(gl, 5));
    printf("\nIl grado di uscita di %d è %d;\n", 6, grado_di_uscita_liste(gl, 6));
    
    printf("\nIl grado di ingresso di %d è %d;", 1, grado_di_ingresso_liste(gl, 1));
    printf("\nIl grado di ingresso di %d è %d;", 2, grado_di_ingresso_liste(gl, 2));
    printf("\nIl grado di ingresso di %d è %d;", 3, grado_di_ingresso_liste(gl, 3));
    printf("\nIl grado di ingresso di %d è %d;", 4, grado_di_ingresso_liste(gl, 4));
    printf("\nIl grado di ingresso di %d è %d;", 5, grado_di_ingresso_liste(gl, 5));
    printf("\nIl grado di ingresso di %d è %d;\n", 6, grado_di_ingresso_liste(gl, 6));
    
    printf("\nIl grado di uscita medio del grafo è: %f;", grado_uscita_medio_liste(gl));
    
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 1, 2, verifica_arco(gl, 1, 2));
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 2, 5, verifica_arco(gl, 2, 5));
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 5, 2, verifica_arco(gl, 5, 2));
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 4, 3, verifica_arco(gl, 4, 3));
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 3, 5, verifica_arco(gl, 3, 5));
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 5, 1, verifica_arco(gl, 5, 1));
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 5, 6, verifica_arco(gl, 5, 6));
    printf("\nEsiste l'arco da %d a %d? Risposta: %d;", 6, 6, verifica_arco(gl, 5, 1));
    
	printf("\nIl grafo è orientato? Risposta: %d (atteso: 0);\n", verifica_non_orientato(gl));
	
	printf("\nIl nodo %d è un pozzo? Risposta: %d;", 1, verifica_pozzo(gl, 1));
	printf("\nIl nodo %d è un pozzo? Risposta: %d;", 2, verifica_pozzo(gl, 2));
	printf("\nIl nodo %d è un pozzo? Risposta: %d;", 3, verifica_pozzo(gl, 3));
	printf("\nIl nodo %d è un pozzo? Risposta: %d;", 4, verifica_pozzo(gl, 4));
	printf("\nIl nodo %d è un pozzo? Risposta: %d;", 5, verifica_pozzo(gl, 5));
	printf("\nIl nodo %d è un pozzo? Risposta: %d;\n", 6, verifica_pozzo(gl, 6));
	
	printf("\nIl nodo %d è una sorgente? Risposta: %d;", 1, verifica_sorgente(gl, 1));
	printf("\nIl nodo %d è una sorgente? Risposta: %d;", 2, verifica_sorgente(gl, 2));
	printf("\nIl nodo %d è una sorgente? Risposta: %d;", 3, verifica_sorgente(gl, 3));
	printf("\nIl nodo %d è una sorgente? Risposta: %d;", 4, verifica_sorgente(gl, 4));
	printf("\nIl nodo %d è una sorgente? Risposta: %d;", 5, verifica_sorgente(gl, 5));
	printf("\nIl nodo %d è una sorgente? Risposta: %d;\n", 6, verifica_sorgente(gl, 6));
	
    stampa_grafo_liste(gl);
	
    /*Alloco memoria per un nuovo puntatore ad un grafo rappresentato con matrici*/
    printf("\n\n\n\n\n\n\nCreo un grafo rappresentato con matrici di adiacenza;");
    grafo_matrice* gm2 = MATRICE(gl);
    printf("\nFatto!\n");
    stampa_grafo(gm2);
    
}
