#include "BinomilaHeap.h"
#include "HeapElement.h"

void FillHeap(BinomialHeap* heap, int count);
void TestHeap(BinomialHeap* heap, int count);


int main(int argc, char* argv[])
{
	srand(10);
	BinomialHeap test = BinomialHeap();
	
	short a[] = { 100,80,85,70,50,65,40,20,30,25,50,10,12 };

	for (int i = 0; i < 13; i++)
	{
		test.AddElement(a[i]);
	}

	HeapElement* proba = test.FindNode(4);

	test.Printf();
	cin.ignore();
	cout << endl << "---New---" << endl;
	test.DecreseKey(test.FindNode(8), 11);
	test.Printf();
	cin.ignore();
	test.ExtractMin();
	cout << endl << "---New---" << endl;
	test.Printf();
	cin.ignore();
	cout << endl << "---New---" << endl;
	test.ExtractMin();
	test.Printf();
	cin.ignore();

	/*BinomialHeap* heap = new BinomialHeap();
	int des = 10;
	for (int i = 1; i < 2; i++)
	{
		FillHeap(heap, i * des);
		TestHeap(heap,i * des);
	}
	*/
}

void FillHeap(BinomialHeap* heap,int count)
{
	for (int i = 0; i < count; i++)
	{
		short val = rand()%10001;
		heap->AddElement(val);
	}
}

void TestHeap(BinomialHeap* heap,int count)
{
	int size = count / 10;
	count = count - size;
	cout << "Minimumi su: ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << heap->ExtractMin();
	}
	cout << endl;


	//size = count / 10;
	HeapElement** test = (HeapElement**)malloc(size * sizeof(BinomialHeap*));
	int ind = 0;
	for (int i = 0; i < size; i++)
	{
		ind = rand() % count;

	 	HeapElement* proba = heap->FindNode(ind);// lose za test

		heap->DecreseKey(proba, proba->key - 100);

		test[i] = proba;
	}

	for (int i = 0; i < size; i++)
	{
		heap->Deleate(test[i]);
	}

	for (int i = 0; i < size; i++)
	{
		short val = rand() % 10001;
		heap->AddElement(val);
	}
}

