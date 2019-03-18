#include "BinomilaHeap.h"
#include "HeapElement.h"


int main(int argc, char* argv[])
{
	BinomialHeap test = BinomialHeap();
	
	short a[] = { 100,80,85,70,50,65,40,20,30,25,50,10,12 };

	for (int i = 0; i < 13; i++)
	{
		test.AddElement(a[i]);
	}

	test.Printf();
	cin.ignore();
}