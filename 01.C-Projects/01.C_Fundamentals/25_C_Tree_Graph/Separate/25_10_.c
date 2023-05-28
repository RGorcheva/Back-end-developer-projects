/*
 Дефинирайте функция, която намира път от един връх до друг. Mоже и най-прекия, например с
алгоритъма на Дийкстра (Dijkstra's Algorithm)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Vertex {
	char* name;
	int vertIdx;
}Vertex;

typedef struct Edge {
	int vertex1;
	int vertex2;
	int lenght;
}Edge;

typedef struct Graph {
	int iNumberOfVertices;
	int iNumberOfEdges;
	Vertex vertex[MAX_SIZE];
	Edge edge[MAX_SIZE * MAX_SIZE];
} Graph;

void graph_init(Graph* graph)
{
	graph->iNumberOfVertices = 0;
	graph->iNumberOfEdges = 0;
}
char* grapf_findVertexName(Graph* graph, int vertIndx)
{
	for (int i = 0; i < graph->iNumberOfVertices; i++)
	{
		if (graph->vertex[i].vertIdx == vertIndx)
		{
			return graph->vertex[i].name;
		}
	}
	return NULL;
}
int grapf_findVertexIdx(Graph* graph, char* town)
{
	for (int i = 0; i < graph->iNumberOfVertices; i++)
	{
		if (graph->vertex[i].name == town)
		{
			return graph->vertex[i].vertIdx;
		}
	}
	return -1;
}
void graph_addVertex(Graph* graph, char* town)
{
	graph->vertex[graph->iNumberOfVertices].vertIdx = graph->iNumberOfVertices;
	graph->vertex[graph->iNumberOfVertices].name = town;
	++graph->iNumberOfVertices;
}
void graph_removeVertexAndAllEdges(Graph* graph, char* town)
{
	int ind1 = grapf_findVertexIdx(graph, town);
	if (ind1 == -1)
	{
		printf("There is no such vertex!");
		return;
	}
	for (int i = 0; i < graph->iNumberOfEdges; i++)
	{
		if ((graph->edge[i].vertex1 == ind1) || (graph->edge[i].vertex2 == ind1))
		{
			for (int j = i; j < graph->iNumberOfEdges - 1; j++)
			{
				graph->edge[j].lenght = graph->edge[j + 1].lenght;
				graph->edge[j].vertex1 = graph->edge[j + 1].vertex1;
				graph->edge[j].vertex2 = graph->edge[j + 1].vertex2;
			}
			--graph->iNumberOfEdges;
			i--;
		}
	}
	for (int i = 0; i < graph->iNumberOfVertices; i++)
	{
		if (graph->vertex[i].name == town)
		{
			for (int j = i; j < graph->iNumberOfVertices - 1; j++)
			{
				graph->vertex[j].name = graph->vertex[j + 1].name;
				graph->vertex[j].vertIdx = graph->vertex[j + 1].vertIdx;
			}
			--graph->iNumberOfVertices;
		}
	}
}
void graph_removeVertex(Graph* graph, char* town)
{
	for (int i = 0; i < graph->iNumberOfVertices; i++)
	{
		if (graph->vertex[i].name == town)
		{
			for (int j = i; j < graph->iNumberOfVertices - 1; j++)
			{
				graph->vertex[j].name = graph->vertex[j + 1].name;
				graph->vertex[j].vertIdx = graph->vertex[j + 1].vertIdx;
			}
			--graph->iNumberOfVertices;
		}
	}
}
void graph_addEdge(Graph* graph, char* town1, char* town2, int dist)
{
	int ind1 = grapf_findVertexIdx(graph, town1);
	int ind2 = grapf_findVertexIdx(graph, town2);
	if ((ind1 == -1) || (ind2 == -1))
	{
		printf("There is no such vertex!\n");
		return;
	}
	for (int i = 0; i < graph->iNumberOfEdges; i++)
	{
		if (((graph->edge->vertex1 == ind1) && (graph->edge->vertex2 == ind2)) || ((graph->edge->vertex1 == ind2) && (graph->edge->vertex2 == ind1)))
		{
			printf("Edge with these towns alredy exist!");
			return;
		}
	}
	graph->edge[graph->iNumberOfEdges].lenght = dist;
	graph->edge[graph->iNumberOfEdges].vertex1 = ind1;
	graph->edge[graph->iNumberOfEdges].vertex2 = ind2;
	++graph->iNumberOfEdges;
}
void graph_removeEdge(Graph* graph, char* town1, char* town2)
{
	int ind1 = grapf_findVertexIdx(graph, town1);
	int ind2 = grapf_findVertexIdx(graph, town2);
	if ((ind1 == -1) || (ind2 == -1))
	{
		printf("There is no such vertex!");
		return;
	}
	for (int i = 0; i < graph->iNumberOfEdges; i++)
	{
		if (((graph->edge[i].vertex1 == ind1) && (graph->edge[i].vertex2 == ind2)) || ((graph->edge[i].vertex1 == ind2) && (graph->edge[i].vertex2 == ind1)))
		{
			for (int j = i; j < graph->iNumberOfEdges - 1; j++)
			{
				graph->edge[j].lenght = graph->edge[j + 1].lenght;
				graph->edge[j].vertex1 = graph->edge[j + 1].vertex1;
				graph->edge[j].vertex2 = graph->edge[j + 1].vertex2;
				--graph->iNumberOfEdges;
			}
		}
	}
}
void graph_print(Graph* graph)
{
	if (graph == NULL)
	{
		printf("The graph is empty!\n");
		return;
	}
	for (int i = 0; i < graph->iNumberOfVertices; i++)
	{
		printf("%d-%s\n", graph->vertex[i].vertIdx, graph->vertex[i].name);
	}
	printf("\n");
	for (int i = 0; i < graph->iNumberOfEdges; i++)
	{
		printf("%s-%s(%d)\n", grapf_findVertexName(graph, graph->edge[i].vertex1), grapf_findVertexName(graph, graph->edge[i].vertex2), graph->edge[i].lenght);
	}
	printf("\n");
}
bool graph_isPath(Graph* graph, char* town1, char* town2)
{
	if (town1 == town2) {
		return true;
	}
	int idxStart = grapf_findVertexIdx(graph, town1);
	int idxEnd = grapf_findVertexIdx(graph, town2);

	bool visited[MAX_SIZE] = { 0 }; //Масив, който държи 1 или 0 в зависимост дали съответния връх е проверен
	int queue[MAX_SIZE], front = 0, rear = 0; //пази върховете, които трябва да се прегледат
	queue[rear++] = idxStart;
	visited[idxStart] = true;
	while (front != rear) {
		int current = queue[front++];
		for (int i = 0; i < graph->iNumberOfVertices; i++)
		{
			for (int j = 0; j < graph->iNumberOfEdges; j++)
			{
				if ((graph->edge[j].vertex1 == current && graph->edge[j].vertex2 == i && !visited[i]) || (graph->edge[j].vertex2 == current && graph->edge[j].vertex1 == i && !visited[i]))
				{
					if (i == idxEnd) {
						return true;
					}
					queue[rear++] = i;
					visited[i] = true;
				}
			}
		}
	}
	return false;
}
void shortest_path(Graph* graph, char* town1, char* town2)
{
	if (town1 == town2) {
		printf("Entered towns are the same!");
	}
	int idxStart = grapf_findVertexIdx(graph, town1);
	int idxEnd = grapf_findVertexIdx(graph, town2);

	int distance[MAX_SIZE], previousVertex[MAX_SIZE];
	bool isVisited[MAX_SIZE] = { 0 };
	int queue[MAX_SIZE], front = 0, back = 0;
	for (int i = 0; i < graph->iNumberOfVertices; i++) 
	{
		distance[i] = INT_MAX;
		previousVertex[i] = -1;
	}
	distance[idxStart] = 0;
	queue[back++] = idxStart;
	while (front != back) {
		int current = queue[front++];
		isVisited[current] = true;
		for (int i = 0; i < graph->iNumberOfVertices; i++) 
		{
			for (int j = 0; j < graph->iNumberOfEdges; j++) 
			{
				if ((graph->edge[j].vertex1 == current && graph->edge[j].vertex2 == i) || (graph->edge[j].vertex2 == current && graph->edge[j].vertex1 == i))
				{
					int weight = graph->edge[j].lenght;
					if (distance[current] + weight < distance[i]) 
					{
						distance[i] = distance[current] + weight;
						previousVertex[i] = current;
						if (!isVisited[i]) 
						{
							queue[back++] = i;
						}
					}
				}
			}
		}
	}
	if (previousVertex[idxEnd] != -1) 
	{
		int vertex = idxEnd;
		while (vertex != -1) 
		{
			printf("%s", grapf_findVertexName(graph, vertex));
			vertex = previousVertex[vertex];
			if (vertex != -1) printf("<-");
		}
	}
	if (previousVertex[idxEnd] != -1)
	{
		int vertex = idxStart;
		while (vertex != -1)
		{
			printf("%s", grapf_findVertexName(graph, vertex));
			vertex = previousVertex[vertex--];
			if (vertex != idxEnd) printf("->");
		}
		printf("%s", grapf_findVertexName(graph, vertex));
	}
}

int main(void)
{
	Graph grap;
	Graph* graph = &grap;
	graph_init(graph);

	graph_addVertex(graph, "Sofia");
	graph_addVertex(graph, "Varna");
	graph_addVertex(graph, "Burgas");
	graph_addVertex(graph, "Plovdiv");
	graph_addVertex(graph, "Stara Zagora");
	graph_addEdge(graph, "Sofia", "Varna", 520);
	graph_addEdge(graph, "Sofia", "Burgas", 380);
	graph_addEdge(graph, "Sofia", "Plovdiv", 180);
	graph_addEdge(graph, "Sofia", "Stara Zagora", 230);
	graph_addEdge(graph, "Varna", "Burgas", 130);
	graph_addEdge(graph, "Plovdiv", "Stara Zagora", 100);
	graph_print(graph);
	bool isPath = graph_isPath(graph, "Burgas", "Plovdiv");
	printf("%d\n", isPath);
	shortest_path(graph, "Burgas", "Plovdiv");

	return 0;
}



