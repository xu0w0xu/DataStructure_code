#include "function.h"

int main() {
	SSTable ST;
	ST_Init(ST, 10);
	ST_Print(ST);
	ElemType key;
	printf("Please input search key:\n");
	scanf("%d", &key);
	int pos;
	pos = sequential_search(ST, key);
	if (pos) {
		printf("Find key, pos = %d\n", pos);
	}
	else {
		printf("Not find.\n");
	}
	return 0;
}