// ==============
// BFS & DFS
// ==============

#include <iostream>
#include "queue.h"
#include "stack.h"
#define MAX 20   // it is a macrO ....it replaces the MAX by the value while compilation of code , always written in a CAPITAL CASE 
using namespace std;

class graph
{
	friend class stack;
	int n;
	int adj[MAX][MAX];
	int visited[MAX];   
public:
	graph();
	void create();
	void dfs();
	void bfs();
	void initialize_visited();
};


graph :: graph()
{
	for (int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			adj[i][j]=0;

	for (int i = 0; i<MAX; i++)
		visited[i]=0;
}

void graph :: create()
{
	int ch;
	cout<<"No. of Vertices in a graph ::  ";
	cin>>n;

	for (int i = 0; i< n-1; i++)//Vertices/Nodes
	 {
		for(int j = i+1; j < n; j++)//Adjacency nodes
		{
			cout<<"Does edge is present between "<< i <<" and " <<j<<"?(1/0)- ";
			cin >> ch;
			if(ch==1) adj[i][j] = adj[j][i] = 1;
		}//inner for -j
	}//outer for - i
}//create


void graph :: dfs()
{
	stack s;
	int i;
	cout<<"\n--------------------DFS---------------------\n";
	cout<<"Enter starting vertex :: ";
	cin >> i;

	s.push(i);//push starting vertex into stack

	while(!s.isEmpty()) //Till stack is not empty
	{
		i = s.pop(); //Pop the vertex

		if(visited[i]==1) //ignore if the vertex is visited
			continue;

		cout<<" "<<i; //print the vertex

		visited[i] = 1;   //set it as visited

		for (int k = 0; k < n; k++) //for accessing adjacent elements of i
		{
			if(adj[i][k] == 1 && visited[k] == 0)
            { //if edge is present and new vertex is not visited
				s.push(k);
            }    
		}//for
	}//while	
}//dfs

void graph :: initialize_visited()
{
	for (int i = 0; i<MAX; i++)
			visited[i]=0;
}


void graph :: bfs()
{
	queue q;
	int i;
	cout<<"\n--------------------BFS---------------------\n";
	cout<<"Enter starting vertex :: ";
	cin >> i;

	q.push(i); //push starting vertex into queue

	while(!q.isEmpty()) //Till queue is not empty
	{
		i = q.pop(); //Pop the vertex from queue

		if(visited[i]==1) //ignore if the vertex is visited
			continue;

		cout<<" "<<i; //print the vertex

		visited[i] = 1; //set it as visited

		for (int k = 0; k < n; k++) //for accessing adjacent elements of i
		{
			if(adj[i][k] == 1 && visited[k] == 0)
            { //if edge is present and new vertex is not visited
				q.push(k);
            }
		}
	}//while
}//bfs


int main()
{
	graph g;
	g.create();
	g.initialize_visited();
	g.dfs();
	g.initialize_visited();
	g.bfs();
	return 0;
}
