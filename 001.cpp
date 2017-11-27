#include <iostream>
using namespace std;

struct data
{
	int Pos;
	int Val;
};

struct List
{
	data data_of_el;
	List *next;
};

int Add_to_beginning(int Pos, int Val, List **First)   //добавление в начало
{
	List *el = new List;
	el->data_of_el.Pos = Pos;
	el->data_of_el.Val = Val;
	el->next = *First;
	*First = el;
	return 0;
}
int Add_to_end(int Pos, int Val, List **First)   // добавление в конец
{
	List *semisemi = *First;
	List *el = new List;
	el->data_of_el.Pos = Pos;
	el->data_of_el.Val = Val;
	while ((semisemi) && (Pos > semisemi->next->data_of_el.Pos))
	{
		semisemi = semisemi->next;
	}
	semisemi->next = el;
	return 0;

}
int Add_between(int Pos, int Val, List **First)     //добавление между элементами
{
	List *semisemi = *First;
	List *el = new List;
	el->data_of_el.Pos = Pos;
	el->data_of_el.Val = Val;
	while ((semisemi) && (Pos > semisemi->data_of_el.Pos))
	{
		semisemi = semisemi->next;
	}
	el = semisemi->next;
	semisemi->next = el;
	while ((Pos == semisemi->next->next->data_of_el.Pos) && (!semisemi->next->next->next))
	{
		semisemi->next->next->data_of_el.Pos++;
		semisemi->next->next = semisemi->next->next->next;
	}
	return 0;
}
int Delete_el(int Pos, List **First)     //удалить элемент
{
	if (!*First)
	{
		return 0;
	}
	List *semi = *First;
	while ((Pos > semi->data_of_el.Pos) && (!semi->next))
	{
		semi = semi->next;
	}
	if (Pos = semi->data_of_el.Pos)
	{
		if (semi == *First)         //начало
		{
			*First = semi->next;
			delete semi;
			return 0;
		}
		if (!semi->next)            //конец
		{
			semi = *First;
			while (!semi->next->next)
			{
				semi = semi->next;
			}
			delete(semi->next);
			semi->next = 0;
			return 0;
		}
		semi = *First;
		while (Pos > semi->next->data_of_el.Pos)
		{
			semi = semi->next;
		}
		semi->next = semi->next->next;
		List *semisemi = semi->next->next;
		delete (semi->next);
		semi->next = semisemi;
		return 0;
	}
	cout << "Element with this Position not exist\n";
	return 0;
}
int ShowList(List **First)     // вывести список
{
	List *show = *First;
	if (!show)
	{
		cout << " List is empty \n";
		return 0;
	}
	cout << " Position\t Value\n";
	while (show)
	{
		cout << show->data_of_el.Pos << "\t" << show->data_of_el.Val << "\n";

		show = show->next;
	}
	return 0;

}
int Add_elem(int Pos, int Val, List **First)
{
	List *semi = *First;
	cout << Pos;
	if (!First)
	{
		Add_to_beginning(Pos, Val, First);
		return 0;
	}
	if (Pos == 1)
	{
		Add_to_beginning(Pos, Val, First);
		return 0;
	}

	while ((semi) && (Pos > semi->data_of_el.Pos))
	{
		semi = semi->next;
	}
	if (!semi)
	{
		Add_to_end(Pos, Val, First);
		return 0;
	}
	Add_between(Pos, Val, First);
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int Pos, Val;
	char op;
	List* First = 0;
	do
	{
		
		cin.clear();
		_flushall();
		cin >> (op);
		switch (op)
		{
		case '+': cout << "Enter Position of new element\n";
			cin >> (Pos);
			if (Pos <= 0)
			{
				cout << "Position can not be unpositive\n";
				break;
			}
			cout << "Enter Value of new element\n";
			cin >> (Val);
			Add_elem(Pos, Val, &First);

			break;
		case '=':
			ShowList(&First);
			break;
		case '-':
			Delete_el(Pos, &First);
			break;
		}
	} while (op != 0);
	return 0;
}
