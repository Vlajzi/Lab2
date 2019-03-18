#pragma once
#include "HeapElement.h"
#include <iostream>

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

private:
	HeapElement* minitem;
	HeapElement* head;
	int count;


	//HeapElement* Mearge(HeapElement* a, HeapElement* b);
};
