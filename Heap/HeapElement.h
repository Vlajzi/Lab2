#pragma once
#include <vector>

using namespace std;
class HeapElement
{
public:
	HeapElement(short key, HeapElement* parent);
	~HeapElement() = default;

	short key;
	HeapElement* next;
	//HeapElement** children;
	vector<HeapElement*> children;
	HeapElement* parent;
	int degree;
};
