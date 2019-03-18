#pragma once
#include "HeapElement.h"
#include <iostream>
#include <math.h>

using namespace std;

class BinomialHeap
{
public:
	BinomialHeap();
	~BinomialHeap() = default;//Kasnije

	void Normalize();
	void AddElement(short el);
	short Minimum();
	void Mearge(BinomialHeap& a);
	short ExtractMin();
	void Printf();
	void DecreseKey(HeapElement* nod, short val);
	void Deleate(HeapElement* nod);
	HeapElement* FindNode(int pozition);

private:
	HeapElement* minitem;
	HeapElement* head;
	int count;

	void FindMin();


	//HeapElement* Mearge(HeapElement* a, HeapElement* b);
};
