#include "function.h"

int main() {
	SSTable ST;
	ST_Init(ST, 10);
	ST_Print(ST);

	//qsort≈≈–Ú
	//qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);
	sort(ST.elem + 1, ST.elem + ST.TableLen);
	ST_Print(ST);
	
	ElemType key;
	printf("Please input search key:\n");
	scanf("%d", &key);
	int pos;
	//pos = sequential_search(ST, key);
	pos = binary_Search(ST, key);
	if (pos) {
		printf("Find key, pos = %d\n", pos);
	}
	else {
		printf("Not find.\n");
	}
	return 0;
}