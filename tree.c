#include <stdio.h>
#include <malloc.h>

typedef char DataType;

struct BTNode
{
    DataType data;
    struct BTNode *LChild;
    struct BTNode *RChild;
};

struct BTNode * CreateBTree();
void PreTraverseBTree(struct BTNode * pT); 		//先序遍历 
void InTraverseBTree(struct BTNode * pT); 		//中序遍历 
void PostTraverseBTree(struct BTNode * pT); 	//后序遍历 

int main()
{
    struct BTNode * root = CreateBTree();
    PreTraverseBTree(root);
    InTraverseBTree(root);
    PostTraverseBTree(root);
    
    return 0;
}

struct BTNode * CreateBTree()
{
    	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));

    	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->LChild = pB;
	pA->RChild = pC;
	pB->LChild = pB->RChild = NULL;
	pC->LChild = pD;
	pC->RChild = NULL;
	pD->LChild = NULL;
	pD->RChild = pE;
	pE->LChild = pE->RChild = NULL;

	return pA;
}

void PreTraverseBTree(struct BTNode * pT)
{
	if(pT != NULL)
	{
		printf("%c\n", pT->data);
		if(pT->LChild != NULL)
		{
			PreTraverseBTree(pT->LChild);
		}
		if(pT->RChild != NULL)
		{
			PreTraverseBTree(pT->RChild);
		}
	}
}

void InTraverseBTree(struct BTNode * pT)
{
	if(pT != NULL)
	{
		if(pT->LChild != NULL)
		{
			InTraverseBTree(pT->LChild);
		}
		printf("%c\n", pT->data);
		if(pT->RChild != NULL)
		{
			InTraverseBTree(pT->RChild);
		}
	}
}

void PostTraverseBTree(struct BTNode * pT)
{
	if(pT != NULL)
	{
		printf("%c\n", pT->data);
		if(pT->LChild != NULL)
		{
			PostTraverseBTree(pT->LChild);
		}
		printf("%c\n", pT->data);
		if(pT->RChild != NULL)
		{
			PostTraverseBTree(pT->RChild);
		}
	}
}
