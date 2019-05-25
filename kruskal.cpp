/* union find : detectar ciclos em grafos não direcionados
 // kruskal arvore geradora mínima	
*/
#include<bits/stdc++.h>
using namespace std;
struct aresta{ // aresta , sobrecarga para ordenar as arestas
	int v1, v2,peso;
	bool operator < (const aresta &x){return peso<x.peso;}
};
typedef vector<aresta> va;
int busca( int *v, int i ){ // buscar
 		if(v[i] == -1) return i;
		return busca(v, v[i]);
}
void unir(int *v , int v1, int v2){ // v1 = vertice 1 , v2 = vertice 2
   int v1_set, v2_set;
	v1_set = busca(v,v1);
	v2_set = busca(v,v2);
	v[v1_set] = v2_set;
}

va kruskal(va a, int tam){
	 va arvore;  // armazenar a arvore
	 unsigned n = a.size(); // tamaho do vetor de arestas	
	 sort(a.begin(),a.end()); // ordenar as aretas oelo pelo menor peso
	 int  *v  = new int[tam]; // vetor com tamho do grafo para
	 memset(v,-1,sizeof(int)*tam);
	 for(unsigned i = 0; i < n; ++i){ // percorer as aretas
		 int v1 = busca(v,a[i].v1);
		 int v2 = busca(v,a[i].v2);
		 if(v1!=v2){// se for diferente não forma ciclo
			arvore.push_back(a[i]);
			v[v1] = v2; // unir
		  }
	 }
	 delete v;
	 return arvore;
}



int main(){

	 int  n = 7;
	 va grafo; 
	 aresta aux;
	 aux.v1 = 0;
	 aux.v2 = 1;
	 aux.peso =7;
	 grafo.push_back(aux);
	 
	 aux.v1 = 0;
	 aux.v2 = 3;
	 aux.peso =5;
	 grafo.push_back(aux);
	 
	 aux.v1 = 1;
	 aux.v2 = 2;
	 aux.peso =8;
	 grafo.push_back(aux);
	  
	 aux.v1 = 1;
	 aux.v2 = 3;
	 aux.peso =9;
	 grafo.push_back(aux);
	 
	 aux.v1 = 1;
	 aux.v2 = 4;
	 aux.peso =7;
	 grafo.push_back(aux);
	 
	 aux.v1 = 2;
	 aux.v2 = 4;
	 aux.peso =5;
	 grafo.push_back(aux);
	 
	 aux.v1 = 3;
	 aux.v2 = 4;
	 aux.peso =15;
	 grafo.push_back(aux);
	 
	 aux.v1 = 3;
	 aux.v2 = 5;
	 aux.peso =6;
	 grafo.push_back(aux);
	 
	 aux.v1 = 4;
	 aux.v2 = 5;
	 aux.peso =8;
	 grafo.push_back(aux);
	 
	 aux.v1 = 4;
	 aux.v2 = 6;
	 aux.peso =9;
	 grafo.push_back(aux);
	 
	 aux.v1 = 5;
	 aux.v2 = 6;
	 aux.peso =11;
	 grafo.push_back(aux);
	 
	 va teste = kruskal(grafo,n);
	 for( int i =0 ; i < teste.size();++i){
		cout<<"( "<<teste[i].v1<<", "<< teste[i].v2<<") = "<<teste[i].peso<<" \n";
	  }
	  
	 	
}
