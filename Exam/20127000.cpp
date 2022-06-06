#include "header.h"

Animal *createAnimal(string id, double w1, double w2)
{
	Animal *p = new Animal;
	p->id = id;
	p->w1 = w1;
	p->w2 = w2;
	p->next = NULL;
	return p;
}

void addHead(AnimalList *&a, Animal *a_)
{
	if (a->first == NULL)
	{
		a->first = a->last = a_;
		return;
	}
	a_->next = a->first;
	a->first = a_;
}
void addTail(AnimalList *&a, Animal *a_)
{
	if (a->first == NULL)
	{
		a->first = a->last = a_;
		return;
	}
	a->last->next = a_;
	a->last = a_;
}
AnimalList *read_file(string input_file)
{
	// TODO: read input.txt and return vector of animals
	string id;
	double w1, w2;
	AnimalList *a = new AnimalList;
	a->first = a->last = NULL;
	fstream fs(input_file, ios::in);
	while (!fs.eof())
	{
		fs >> id >> w1 >> w2;
		Animal *p = createAnimal(id, w1, w2);
		if (id[0] == 'P' && id[1] == 'i')
			addHead(a, p);
		else
			addTail(a, p);
	}
	fs.close();
	return a;
}

bool checkAnimal(Animal *a)
{
	string name = string(1, a->id[0]) + string(1, a->id[1]);

	if ((a->id[2] == '0' && a->id[3] == '0') || (a->id[2] == '1' && a->id[3] > '2'))
		return 0;
	if (a->w1 < 0 || a->w2 < 0)
		return 0;
	if ((a->id).length() != 9)
		return 0;
	if (name != "Pi" && name != "Co")
		return 0;
	if ((name == "Pi" && a->w2 > 50 && a->w2 < 100) || (name == "Co" && a->w2 > 50 && a->w2 < 200))
		return 1;
	return 0;
}
void solveC(AnimalList *animals, int x)
{
	Animal *head = animals->first;
	vector<Animal *> v;

	while (head)
	{
		if (checkAnimal(head))
			v.push_back(head);
		head = head->next;
	}

	for (int i = 0; i < v.size() - 1; i++)
		for (int j = i + 1; j < v.size(); j++)
			if (v[i]->w2 - v[i]->w1 < v[j]->w2 - v[j]->w1)
				swap(v[i], v[j]);

	for (int i = 0; i < x; i++)
		cout << v[i]->id << endl;
}
void print_output(AnimalList *animals, int x)
{
	// TODO: do all other tasks and print (cout) output like output.txt
	Animal *p = animals->first;
	while (p)
	{
		cout << p->id << " " << p->w1 << " " << p->w2 << '\n';
		p = p->next;
	}
	cout << "-----------------\n";
	p = animals->first;
	while (p)
	{
		if (!checkAnimal(p))
			cout << p->id << '\n';
		p = p->next;
	}
	cout << "-----------------\n";
	solveC(animals, x);
}

void main_debug(string input_file, int x)
{
	// YOUR MAIN HERE: do whatever you want here
	AnimalList *al = read_file(input_file);
	print_output(al, x);
}

// DO NOT CHANGE ANYTHING FROM HERE
int main(int argc, char *argv[])
{
	string input_file;
	int x;
	if (argc > 2)
	{
		input_file = argv[1];
		x = atoi(argv[2]);
		if (argc > 3 && atoi(argv[3]) == 1)
		{
			main_testcases(input_file, x);
			return 0;
		}
	}
	else
	{
		// cout << "Enter input_file:";
		input_file = "input.txt";
		// cout << "Enter x:";
		x = 3;
	}
	main_debug(input_file, x);
	if (!system(NULL))
		system("pause");
	return 0;
}

void main_testcases(string input_file, int x)
{
	AnimalList *animals = read_file(input_file);
	print_output(animals, x);
}
