#include "HeapElement.h"

HeapElement::HeapElement(short key,HeapElement* parent)
{
	this->key = key;
	this->children = vector<HeapElement*>();
	this->next = nullptr;
	this->parent = parent;
	this->degree = 0;

}
