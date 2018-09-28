//to create a node which is connected to the given node (duplicate node)
struct AdListNode{
	int val;
	int weight;
	struct AdListNode *next;
};typedef struct AdListNode LNode;

 
//in order to keep track of nodes that connected to the given node
//maintain a pointer variable to keep track of adjacency nodes

struct AdList{
	int data;
	LNode *head;
};typedef struct AdList adlist;



//graph is presented as a linked list 
//linked list contains duplicate nodes which are connected to the given node 

struct GRAPH{
	int nodesNo;
	adlist *vertices;
};typedef struct GRAPH graph;

