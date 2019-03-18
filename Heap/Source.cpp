#include "BinomilaHeap.h"
#include "HeapElement.h"



int main(int argc, char* argv[])
{
	srand(10);
	/*BinomialHeap test = BinomialHeap();
	
	short a[] = { 100,80,85,70,50,65,40,20,30,25,50,10,12 };

	for (int i = 0; i < 13; i++)
	{
		test.AddElement(a[i]);
	}

	HeapElement* proba = test.FindNode(12);

	test.Printf();
	cin.ignore();*/


}

void FillHeap(BinomialHeap* heap,int count)
{
	for (int i = 0; i < count; i++)
	{
		short val = rand()%10001;
		heap->AddElement(val);
	}
}