#include "header.h"
using namespace std;
Animal* createNode(string id, double w1, double w2) {
	Animal* newNode = new Animal;
	newNode->id = id;
	newNode->w1 = w1;
	newNode->w2 = w2;
	newNode->next = NULL;
	return newNode;
}

bool check(Animal* animal) {
	string id = animal->id;
	if (id.size() != 9)return 0;
	double w1 = animal->w1;
	double w2 = animal->w2;
	if (w1 < 0 || w2 < 0)return 0;
	if (id[0] == 'P' && id[1] == 'i') {
		if (w1 <= 50 || w1 >= 100)return 0;
	}
	else if (id[0] == 'C' && id[1] == 'o') {
		if (w1 <= 50 || w1 >= 200)return 0;
	}
	else return 0;
	if (id[2] == '0')return 1;
	else if (id[2] == '1')return id[3] <= '2';
	else return 0;
}

bool compare(Animal* a, Animal* b) {
	return a->w2 > b->w2;
}

double sort(AnimalList* animals, int x) {
	Animal* tmp;
	tmp = animals->first;
	int n=0;
	while (tmp != NULL) {
		n++;
		tmp = tmp->next;
	}
	double* num = new double[n]; 
	tmp = animals->first;
	n = 0;
	while (tmp != NULL) {
		*(num + n) = tmp->w2;
		n++;
		tmp = tmp->next;
	}
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if(*(num+i)<*(num+j)){
				double temp = *(num + i);
				*(num + i) = *(num + j);
				*(num + j) = temp;
			}
	return *(num + (x-1));
}
AnimalList* read_file(string input_file) {
	// TODO: read input.txt and return vector of animals
	string id;
	double w1=0, w2=0;
	AnimalList* newList = new AnimalList;
	newList->first = NULL;
	newList->last = NULL;
	ifstream input(input_file);
	while (input>>id>>w1>>w2) {

		Animal* newNode = createNode(id, w1, w2);
		if (id[0] == 'P' && id[1] == 'i') {
			if (newList->first == NULL) {
				newList->first = newNode;
				newList->last = newNode;
			}
			else {
				newNode->next = newList->first;
				newList->first = newNode;
			}
		}
		else {
			if (newList->last == NULL) {
				newList->first = newNode;
				newList->last = newNode;
			}
			else {
				newList->last->next = newNode;
				newList->last = newNode;
			}
		}
	}
	return newList;
}


void print_output(AnimalList* animals, int x) {
	// TODO: do all other tasks and print (cout) output like output.txt
	Animal* tmp;
	tmp = animals->first;
	while (tmp != NULL) {
		cout << tmp->id << " " << tmp->w1 << " " << tmp->w2 << endl;
		tmp = tmp->next;
	}
	cout << "----------\n";
	tmp = animals->first;
	while (tmp != NULL) {
		if (!check(tmp))
			cout << tmp->id << endl;
		tmp = tmp->next;
	}
	cout << "----------\n";
	double min = sort(animals, x);
	tmp = animals->first;
	while (tmp != NULL) {
		if (tmp->w2 >= min)
			cout << tmp->id << endl;
		tmp = tmp->next;
	}
}


void main_debug(string input_file, int x) {
	// YOUR MAIN HERE: do whatever you want here
	main_testcases(input_file, x);
}






// DO NOT CHANGE ANYTHING FROM HERE
int main(int argc, char* argv[]) {
	string input_file; int x;
	if (argc > 2) {
		input_file = argv[1]; x = atoi(argv[2]);
		if (argc > 3 && atoi(argv[3]) == 1) {
			main_testcases(input_file, x); return 0;
		}
	}
	else {
		cout << "Enter input_file:"; cin >> input_file;
		cout << "Enter x:"; cin >> x;
	}
	main_debug(input_file, x);
	if (!system(NULL)) system("pause"); return 0;
}

void main_testcases(string input_file, int x) {
	AnimalList* animals = read_file(input_file);
	print_output(animals, x);
}
