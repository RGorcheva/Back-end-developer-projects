/*
* Реализирайте ваша имплементация на граф, в който всеки връх е град(има стойност - име на град)
и в който имаме тегло на ребрата - дължината на пътя между два града
● Дефинирайте функции за добавяне и премахване на нови градове и за добавяне и премахване
на нови пътища между два града
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
		if (((graph->edge->vertex1 == ind1)&&(graph->edge->vertex2 == ind2)) || ((graph->edge->vertex1 == ind2) && (graph->edge->vertex2 == ind1)))
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
	graph_addEdge(graph, "Burgas", "Plovdiv", 400);
	graph_addEdge(graph, "Plovdiv", "Stara Zagora", 100);
	graph_print(graph);
	graph_removeVertexAndAllEdges(graph, "Sofia");
	graph_print(graph);

    return 0;
}