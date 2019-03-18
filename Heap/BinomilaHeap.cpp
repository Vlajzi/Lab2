#include "BinomilaHeap.h"

BinomialHeap::BinomialHeap()
{
	minitem = nullptr;
	head = nullptr;
	count = 0;
}

HeapElement* Consoladate(HeapElement* a, HeapElement* b);
void Print(HeapElement* node);

// decrease key treba
void BinomialHeap::Normalize()
{
	HeapElement* curent = head;
	HeapElement* poziton = curent;
	if (curent == nullptr || curent->next == nullptr)
	{
		return;
	}

	bool mach = false;
	while (poziton->next!= nullptr)//check
	{ 
		
		
		if (poziton->next->degree == poziton->degree)
		{ 
			HeapElement* tmp = poziton->next->next;
			if (poziton == head)
			{
				head = Consoladate(poziton->next, poziton);
				head->next = tmp;
				curent = head;
			}
			else
			{
				curent->next = Consoladate(poziton->next, poziton);
				curent->next->next = tmp;
			}
			poziton = curent;
			
		}
		else
		{
			if (poziton != head)
			{
				curent = curent->next;
			}
			poziton = curent->next;
		}
						
	}
}

void BinomialHeap::AddElement(short el)
{
	HeapElement* tmp = new HeapElement(el, nullptr);
	tmp->next = head;
	head = tmp;
	if (minitem == nullptr)
	{
		minitem = head;
	}
	else if (minitem->key >= head->key)
	{
		minitem = head;
	}
	Normalize();
}

short BinomialHeap::Minimum()
{
	return this->minitem->key;

}

//Merge by node


HeapElement* Consoladate(HeapElement* a,HeapElement* b)
{
	if (a == nullptr)
		return b;
	if (b == nullptr)
		return a;

	HeapElement* result = nullptr;
	HeapElement* new_parent;
	HeapElement* new_child;

	if (a->key <= b->key)
	{
		new_parent = a;
		new_child = b;
	}
	else
	{
		new_parent = b;
		new_child = a;
	}
		result = new_parent;
		result->degree++;
		result->children.push_back(new_child);
		new_child->next = nullptr;
		new_child->parent = result;
		
	return result;

}

//merge by node


void BinomialHeap::Mearge(BinomialHeap& a)
{

	HeapElement* last = a.head;

	if (last == nullptr)
	{
		return;
	}
	do
	{
		HeapElement* elem = head;
		//last->parent = nullptr;//test
		if (head == nullptr)
		{
			head = last;

		}
		else
		{
			bool ind = true;
			while (ind)
			{
				if (elem->next == nullptr)
				{
					elem->next = last;
					ind = false;
				}
				else if (elem->next->degree >= last->degree)
				{
					HeapElement* tmp = last;
					last = last->next;
					tmp->next = elem->next;
					elem->next = tmp;
					ind = false;
				}
				elem = elem->next;
			}
		}

		last = last->next;

	} while (last != nullptr);
	
	count += a.count;

	if (minitem == nullptr || minitem->key >= a.minitem->key)
	{
		minitem = a.minitem;
	}

	Normalize();

}

short BinomialHeap::ExtractMin()
{

	HeapElement* help = head;

	if (head == minitem)
	{
		head = head->next;
		
	}
	else
	{
		while (help->next != minitem)
		{
			help = help->next;
		}
		
		help->next = minitem->next;
		BinomialHeap* tmp = new BinomialHeap();
		tmp->head = minitem->children[0];
		HeapElement* point = tmp->head;
		for (int i = 1; i < minitem->degree; i++)
		{
			point->next = minitem->children[i];
		}

		Mearge(*tmp);
	}
	
	
	

	//help = head;
	//cahnge to merge

	short value = minitem->key;

	minitem->~HeapElement();

	Normalize();

	return value;
}

void BinomialHeap::Printf()
{
	Print(this->head);
}

void Print( HeapElement* node )
{
	HeapElement* tmp = node;
	while (tmp != nullptr)
	{
	 	cout << tmp->key << "\t";

		HeapElement* pom;

		for (int i = 0; i < tmp->children.size(); i++)
		{
			
			Print(tmp->children[i]);
		}

		tmp = tmp->next;
		cout << endl;
	}
}
