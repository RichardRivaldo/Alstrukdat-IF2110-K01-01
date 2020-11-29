#include <stdio.h>	
#include "boolean.h"
#include "bintree.h"
#include <stdlib.h>
#include "MatriksOfString.h"
#include "customString.h"
//PROGRAM
int main ()
{
	//KAMUS
	upgradeInfo U;
	BinTree P,L,R,LL,LR,RL,RR,LLL,LLR,LLLL,LLLR;
	//ALGORTIMA
	LR = NULL;RL = NULL,LL = NULL,RR = NULL;
	L = NULL;
	R = Tree(CreateUpgradeInfo("Deadly Coaster", "Roller Coaster"),RR,RL);
	MakeTree(CreateUpgradeInfo("Roller Coaster", "base"),L,R,&P);
	printf("IsTreeEmpty R? %d\n", IsTreeEmpty(R));
	printf("IsTreeOneElmt R? %d\n", IsTreeOneElmt(R));
	printf("IsUnerLeft P?%d\n", IsUnerLeft(P));
	printf("IsUnerRight P?%d\n", IsUnerRight(P));
	printf("IsBiner P?%d\n", IsBiner(P));

	printf("\n");
	printf("Print Tree\n");
	PrintTree(P,2);
	printf("\n");

	printf("Ada Deadly Coaster? %d\n", SearchTree(P,"Deadly Coaster"));
	U = FindTreeNode(P,"Deadly Coaster");
	printf("Wahana sebelum Deadly Coaster = %s\n", U.wahanasblm);
	printf("\n");

	U = CreateUpgradeInfo("Roller Coaster V2", "Roller Coaster");
	printf("Add Roller Coaster V2 dari Akar\n");
	AddCabang(&P,"Roller Coaster",U);
	PrintTree(P,2);
	printf("\n");

	U = CreateUpgradeInfo("Roller Coaster V3", "Roller Coaster V2");
	printf("Add Roller Coaster V3 dari Roller Coaster V2 (daun)\n");
	AddDaun(&P,"Roller Coaster V2", U, true);
	PrintTree(P,2);
	return 0;
}