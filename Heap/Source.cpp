#include "BinomilaHeap.h"
#include "HeapElement.h"
#include <ctime>
void FillHeap(BinomialHeap* heap, int count);
void TestHeap(BinomialHeap* heap, int count);


int main(int argc, char* argv[])
{
	srand(10);
	/*BinomialHeap test = BinomialHeap();
	
	short a[] = { 100,80,85,70,50,65,40,20,30,25,50,10,12,45,105};

	for (int i = 0; i < 15; i++)
	{
		test.AddElement(a[i]);
	}

	HeapElement* proba = test.FindNode(4);

	test.Printf();
	cin.ignore();
	cout << endl << "---New---" << endl;
	test.DecreseKey(test.FindNode(8), 9);
	test.Printf();
	cin.ignore();
	test.ExtractMin();
	cout << endl << "---New---" << endl;
	test.Printf();
	cin.ignore();
	cout << endl << "---New---" << endl;
	test.ExtractMin();
	test.Printf();
	cin.ignore();*/
	
	int des = 10;
	for (int i = 0; i < 5; i++)
	{
		BinomialHeap* heap = new BinomialHeap();
		FillHeap(heap, des);
		cout << "Za " << des << " elemenata" << endl;
		TestHeap(heap, des);
		des *= 10;
		cout << endl;
	}
	
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
	clock_t begin = clock();
	for (int i = 0; i < size; i++)
	{
		//cout << " " << heap->ExtractMin();
		
		heap->ExtractMin();
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout <<"Proslo je :" << elapsed_secs << " sekundi za ExtractMin" <<endl;


	//size = count / 10;
	HeapElement** test = (HeapElement**)malloc(size * sizeof(BinomialHeap*));
	int ind = 0;
	begin = clock();
	for (int i = 0; i < size; i++)
	{
		ind = rand() % count;

	 	HeapElement* proba = heap->FindNode(ind);// lose za test

		heap->DecreseKey(proba, proba->key - 100);

		test[i] = proba;
	}
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Proslo je :" << elapsed_secs << " sekundi za Decrease Key" << endl;


	begin = clock();
	for (int i = 0; i < size; i++)
	{
		heap->Deleate(test[i]);
	}
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Proslo je :" << elapsed_secs << " sekundi za Deleate Key" << endl;


	begin = clock();
	for (int i = 0; i < size; i++)
	{
		short val = rand() % 10001;
		heap->AddElement(val);
	}
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Proslo je :" << elapsed_secs << " sekundi za Add Element" << endl;

}

