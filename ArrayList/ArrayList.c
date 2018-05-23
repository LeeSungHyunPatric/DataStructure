#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ArrayListNodeType { // ������ ����� 
	int data
}ArrayListNode;

typedef struct ArrayListType{ // �迭 ����Ʈ�� ���� ������ ������ ���� 
	int maxSzie;
	int currentPos;
	ArrayListNode *node;
}ArrayList;

ArrayList *create(int count) {
	printf("it is not validate index1\n");
	ArrayList* arrayList = (ArrayList*)malloc(sizeof(ArrayList));
	arrayList->maxSzie = count;
	arrayList->currentPos = 0;
	arrayList->node = (ArrayListNode*)malloc(sizeof(ArrayListNode) * count);
	memset(arrayList->node, 0, sizeof(arrayList)*count);
	return arrayList;
}

void addNode (ArrayList* arrayList, int pos, int data) {
	int i;
	
	for(i = arrayList->currentPos-1; i >= pos; i--) arrayList->node[i+1] = arrayList->node[i];
	
	arrayList->node[pos].data = data;
	arrayList->currentPos++;
	printf("it is not validate index3\n");
}

void rmNode (ArrayList* arrayList, int pos) {
	int i;
	
	for(i = pos; pos<arrayList->currentPos-1; i++) arrayList->node[i] = arrayList->node[i+1];
	
	arrayList->currentPos--;
	printf("it is not validate index4\n");
}

int getNode (ArrayList* arrayList, int pos) {
	if(pos < arrayList->currentPos) return arrayList->node[pos].data;
	
	printf("it is not validate index5\n");
}

void listFree(ArrayList* arrayList) {
	free(arrayList->node);
	free(arrayList);
	printf("it is not validate index6\n");
}

int main (void) {
	
	int i;

	ArrayList arrayList = *(create(10));
	addNode(&arrayList, 0, 3);
	addNode(&arrayList, 0, 4);
	addNode(&arrayList, 0, 5);
	addNode(&arrayList, 0, 6);
	addNode(&arrayList, 0, 7);
	addNode(&arrayList, 0, 8);
	addNode(&arrayList, 0, 9);
	
	rmNode(&arrayList, 2);
	rmNode(&arrayList, 2);
	rmNode(&arrayList, 2);
	
	for(i = 0; i < arrayList.currentPos; i++) 	printf("%d ", getNode(&arrayList, i));
}
