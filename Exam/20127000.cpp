#include "header.h"

AnimalList* read_file(string input_file){
	// TODO: read input.txt and return vector of animals

	return nullptr;
}


void print_output(AnimalList* animals, int x){
	// TODO: do all other tasks and print (cout) output like output.txt
}


void main_debug(string input_file, int x){
	// YOUR MAIN HERE: do whatever you want here

}






// DO NOT CHANGE ANYTHING FROM HERE
int main(int argc, char* argv[]){
	string input_file; int x;
	if (argc > 2) {
		input_file = argv[1]; x = atoi(argv[2]);
		if (argc > 3 && atoi(argv[3]) == 1) {
			main_testcases(input_file, x); return 0; }}
	else {
		cout << "Enter input_file:"; cin >> input_file;
	 	cout << "Enter x:"; cin >> x; }
	main_debug(input_file, x);
	if (!system(NULL)) system("pause"); return 0; }

void main_testcases(string input_file, int x){
	AnimalList* animals = read_file(input_file);
	print_output(animals, x); }
