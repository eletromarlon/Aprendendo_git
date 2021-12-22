#ifndef GRAFO_COMUNIDADES_H_INCLUDED
#define GRAFO_COMUNIDADES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct ponto {
    int numero;         // valor vertice (ID)
    struct ponto *prox;  // arestas
    struct ponto *baixo; // vertices
} ponto;                 // estrutura que corresponde a cada Vertice/Aresta do Grafo

typedef struct
{
    int quantV;   // Quantidade de Vertices
    ponto *inicio; // Inicio --> Onde começa o 1 vertice
} ListaDinamica;  // Grafo --> ListaDinamica

void CriaLD(ListaDinamica *L);
void Free_All(ListaDinamica *L);
void ImprimeGrafoCompleto(ListaDinamica *L);
ponto *NovoVertAresta(int value);
ponto *RetornapontoAnterior(ListaDinamica *L, int v1);
int VerificaRemoveVertices(ListaDinamica *L, int v1);
int VerificaRemoveArestas(ListaDinamica *L, int v1, int v2);
int VerificaAresta(ListaDinamica *L, int v1, int v2);
void InserirArestaOrdenado(ListaDinamica *L, ponto *C, ponto *V);
int InserirVertice(ListaDinamica *L, int n);
void InserirVerticeOrdenado(ListaDinamica *L, ponto *C);
void InserirPrimeiroVertice(ListaDinamica *L, ponto *c);
void InserirFimVertice(ListaDinamica *L, ponto *c);
void RemoveAresta(ListaDinamica *Lista, ponto *V, int n);


#endif // GRAFO_COMUNIDADES_H_INCLUDED
