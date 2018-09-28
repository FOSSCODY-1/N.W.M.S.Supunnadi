#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include "Graphs.h"

# define INF 9999

//function to find node which has minimum weight
int miniNode(int dist[], int FNodes[],int size){
	
	int min=INF,min_node;
	int i;
	
	for(i=0;i<size;i++){
		if(FNodes[i]==0 && dist[i] <=min){
			min =dist[i];
			min_node=i;
		}
	}
	return min_node;
}

void printSPT(int src,int dist[],int size){
	printf("\nVertex distance from given Node :%d \n\n",src);
	printf("Vertex\tDistance\n");
	
	int i;
	
	for(i=0;i<size;i++){
		if(dist[i]==INF){
			printf("%d\tInfinity :can't reach from given node\n",(i+1));
		}else{
			printf("%d\t%d\n",(i+1),dist[i]);
		}
	}
}
void Dijkstra(graph *g,int src){
	
	int size,i;
	size=g->nodesNo;
	
	int Distances[size]; //keep track of shortest path distance 
	int FinishedNodes[size]; //keep track of already finished nodes
	
	//initialize the Distance array and FinishedNodes array
	for(i=0;i<size;i++){
		
		//my graph assign values starting 1 (see the createGraph function)
		if(i==(src-1)){
			Distances[i]=0; //initially only the source node has minimum distance
		}else{
			Distances[i]=INF;
		}
		
		FinishedNodes[i]=0;//initially there are no finishedNodes
	}
	
	for(i=0;i<size;i++){
		
		int min_node=miniNode(Distances,FinishedNodes,size);
		FinishedNodes[min_node]=1;
		
		int wght,nodeNo;
		LNode *p=g->vertices[min_node].head;
		
		while(p){
			
			wght=p->weight;
			nodeNo=(p->val)-1;//since the graph starts from 1
			
			//only update value if it's not include already
			if(FinishedNodes[nodeNo]==0){
				Distances[nodeNo]=wght+Distances[min_node];
			}
			p=p->next;
		}
	}
	
	printSPT(src,Distances,size);
}

int main(){
	graph *G=createGraph();
	buildEdges(G);
	printGraph(G);
	
	int src;
	printf("\n\n=============Dijkstra=================");
	printf("\n\nNow enter the source for find shortest paths : ");
	scanf("%d",&src);
	Dijkstra(G,src);
}
