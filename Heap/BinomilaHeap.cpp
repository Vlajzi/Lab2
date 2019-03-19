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

	HeapElement* mh1 = curent;
	HeapElement* mh2 = poziton;

	if (curent == nullptr || curent->next == nullptr)
	{
		return;
	}

	bool mach = false;
	while (poziton != nullptr && poziton->next != nullptr)//check
	{ 
		
		
		if (poziton->next->degree == poziton->degree )// ako ima vise
		{ 
			mach = true;
			mh1 = curent;
			mh2 = poziton;
			/*HeapElement* tmp = poziton->next->next;
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
			poziton = curent;*/
			if (poziton->next->next == nullptr || poziton->next->next->degree != poziton->degree)
			{
				mach = false;
				HeapElement* tmp = mh2->next->next;
				if (mh2 == head)
				{
					head = Consoladate(mh2->next, mh2);
					head->next = tmp;
					mh1 = head;
				}
				else
				{
					mh1->next = Consoladate(mh2->next, mh2);
					mh1->next->next = tmp;
				}
				poziton = mh1;
				curent = mh1;


			}
			else
			{
				if (poziton != head)
				{
					curent = curent->next;
				}
				poziton = poziton->next;
			}
			
		}
		else
		{
			

			if (poziton != curent)
			{
				curent = curent->next;
			}
			poziton = poziton->next;
			
		}
						
	}

	this->FindMin();
}

void BinomialHeap::AddElement(short el)
{
	HeapElement* tmp = new HeapElement(el, nullptr);
	tmp->next = head;
	head = tmp;
	count++;
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
	
	bool test = true;
	if (last == nullptr)
	{
		return;
	}
	HeapElement* elem = head;
	HeapElement** pozition = &head;
	do
	{
		
		//last->parent = nullptr;//test
		if (head == nullptr)
		{
			head = last;
			minitem = a.minitem;
			break;
		}
		else
		{
			bool ind = true;
			while (ind)
			{
				if (elem->degree > last->degree)
				{
					*pozition = last;
					HeapElement* help = last;
					last = last->next;
					help->next = elem;
					pozition = &help->next;
					ind = false;
				}
				else
				{
					if (elem->next == nullptr)
					{
						elem->next = last;
						last = last->next;
						if(last != nullptr)
						last = nullptr;
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
		}

		//last = last->next;

	} while (last != nullptr);
	
	count += a.count;//ne treba

	/*if (minitem == nullptr || minitem->key >= a.minitem->key)
	{
		
	}*/
	minitem = a.minitem;
	Normalize();

}

short BinomialHeap::ExtractMin()
{
	
	HeapElement* help = head;
	HeapElement* tmpMin = minitem;

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
		
		//bilo
	}
	if (minitem->degree != 0)
	{
		help->next = minitem->next;
		BinomialHeap* tmp = new BinomialHeap();
		tmp->head = minitem->children[0];
		HeapElement* point = tmp->head;
		point->parent = nullptr;
		for (int i = 1; i < minitem->degree; i++)
		{
			point->next = minitem->children[i];
			point = point->next;
			point->parent = nullptr;
		}
		tmp->FindMin();
		Mearge(*tmp);//823 pogresno vezuje i gore i dete
	}
	
	

	//help = head;
	//cahnge to merge

	short value = tmpMin->key;

	tmpMin->~HeapElement();
	tmpMin = nullptr;
	Normalize();
	count--;
	return value;
}

void BinomialHeap::Printf()
{
	Print(this->head);
}


void BinomialHeap::FindMin()
{
	if (head == nullptr)
		return;
	if (minitem == nullptr)
	{
		minitem = head;
	}
	HeapElement* pom = this->head;
	while (pom != nullptr)
	{
		if (minitem->key >= pom->key)
		{
			minitem = pom;
		}
		pom = pom->next;
	}
}


void BinomialHeap::DecreseKey(HeapElement * nod, short val)
{
	HeapElement* tmp = nod;
	tmp->key = val;
	bool out = true;
	while (tmp->parent != nullptr && out)
	{
		if (val <= tmp->parent->key)
		{
			short m = tmp->parent->key;
			tmp->parent->key = val;
			tmp->key = m;		
			tmp = tmp->parent;
		}
		else
		{
			out = false;
		}
	}
	if (out)
	{
		FindMin();
	}

}

void BinomialHeap::Deleate(HeapElement * nod)
{
	DecreseKey(nod, minitem->key - 1);
	ExtractMin();
}


//proveri
HeapElement * BinomialHeap::FindNode(int pozition)
{
	HeapElement* rez = nullptr;

	if (pozition >= count)
	{
		throw exception("Out of range");
	}

	rez = head;

	while (pozition > 0)
	{
		
		int val = pow(2, rez->degree);
		if (val  <= pozition)
		{
			pozition -= val;
			rez = rez->next;
		}
		else
		{
			int i = rez->degree-1;
			while (i >= 0 && pozition > 0)
			{
			
				val = pow(2,rez->children[i]->degree);
				if (val < pozition)
				{
					pozition -= val;
					i--;
				}
				else
				{
					rez = rez->children[i];
					if (1 == pozition )
					{
						pozition = -1;
						
					}
					else
					{
						pozition--;
						i = rez->degree - 1;
					}
				}
			}
		}
	}

	return rez;
}


//Los print

void Print( HeapElement* node )
{
	HeapElement* tmp = node;
	while (tmp != nullptr)
	{
	 	cout << tmp->key;

		HeapElement* pom;

		for (int i = tmp->degree - 1; i >= 0; i--)
		{
			cout << "----------";
			Print(tmp->children[i]);
			if(i != tmp->degree - 1)
				cout << endl;
			if(i != 0)
			cout << "\t|";
		}

		tmp = tmp->next;
		cout << endl<<endl;
	}
}



