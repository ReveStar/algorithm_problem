// 图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include <queue>
using namespace std;
#define VERTEX_MAX 26

#define MAXVALUE 32767
#define QUEUE_MAXSIZE 30

typedef struct {
	int Data[QUEUE_MAXSIZE];
	int head;
	int tail;
}SeqQueue;

typedef struct {
	char Vertex[VERTEX_MAX];
	int Edge[VERTEX_MAX][VERTEX_MAX];
	int isTrav[VERTEX_MAX];
	int VertexNum;
	int EdgeNum;
	int GraphType;//0无向，1有向
}MatrixGraph;

void CreateMatrixGraph(MatrixGraph* G);
void OutMatrixGraph(MatrixGraph* G);
void CreateMatrixGraph(MatrixGraph* G) {
	int i, j, k ,weight;
	char start, end;
	for (i = 0; i < G->VertexNum; i++) {
		getchar();
		cin >> G->Vertex[i];
	}
	for (k = 1; k < G->EdgeNum; k++) {
		getchar();
		cin >> start >> end >> weight;

	}
	for (i = 0; start != G->Vertex[i]; i++) {
		for (j = 0; end != G->Vertex[j]; j++) {
			G->Edge[i][j] = weight;
			if(G->GraphType == 0) {
				G->Edge[j][i] = weight;

			}

		}
	}

}

void OutMatrixGraph(MatrixGraph* G) {
	int i, j;
	for (j = 0; j < G->VertexNum; j++) {
		cout << G->Vertex[j];
	}
	for (i = 0; i < G->VertexNum; i++) {
		for (j = 0; j < G->VertexNum; j++) {
			if (G->Edge[i][j] != MAXVALUE) {
				cout << G->Edge[i][j];
			}
		}

	}
}
void QueueInit(SeqQueue* Q) {
	Q->head = Q->tail = 0;
	
}
int QueueIsEmpty(SeqQueue* Q) {
	return Q->head == Q->tail;
}
int QueueIn(SeqQueue* Q, int ch) {
	if ((Q->tail + 1) % QUEUE_MAXSIZE == Q->head) {
		return 0;
	}
	Q->Data[Q->tail] = ch;
	Q->tail = (Q->tail + 1) % QUEUE_MAXSIZE;
	return 1;
}
int QueueOut(SeqQueue* Q, int* ch) {
	if (Q->head == Q->tail) {
		return 0;
	}
	*ch = Q->Data[Q->head];
	Q->head = (Q->head + 1) % QUEUE_MAXSIZE;
	return 1;
}


void BFSM(MatrixGraph* G, int k) {
	//k为起始顶点序号
	queue<int> q;
	int i, j;
	G->isTrav[k] = 1;
	q.push(G->Vertex[k]);
	while (!q.empty()) {
		i = q.front();
		q.pop();
		for (j = 0; j < G->VertexNum; j++) {
			if (G->Edge[i][j] != MAXVALUE && G->isTrav[j] != 1) {
				G->isTrav[j] = 1;
				q.push(j);
			}
		}
	}

}
void DFSM(MatrixGraph* G, int i) {
	int j;
	G->isTrav[i] = 1;
	for (j = 0; j < G->VertexNum; j++) {
		if (G->Edge[i][j] != MAXVALUE && G->isTrav[j] != 1) {
			DFSM(G, j);
		}
	}
}
void DFSTraverse(MatrixGraph* G) {
	int i;
	for (i = 0; i < G->VertexNum; i++) {
		G->isTrav[i] = 0;
	}
	for (i = 0; i < G->VertexNum; i++) {
		if (!G->isTrav[i]) {
			DFSM(G, i);
		}
	}
}


#define USED 0
#define NOADJ -1
void prime(MatrixGraph* G) {
	int i, j, k, min, sum = 0;
	int weight[VERTEX_MAX];
	char tmpvertex[VERTEX_MAX];
	for (i = 1; i < G->VertexNum; i++) {
		weight[i] = G->Edge[0][i];
		if (weight[i] == MAXVALUE)tmpvertex[i] = NOADJ;
		else tmpvertex[i] = G->Vertex[0];
	}
	tmpvertex[0] = USED;
	weight[0] = MAXVALUE;

}

int main()
{
    std::cout << "Hello World!\n"; 
}


