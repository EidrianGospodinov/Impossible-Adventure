#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void PrintLine(int spaces, int stars);

void PrintTriangle(int indent, int lines);
void PrintTree(int triangles);


int main() {

	PrintTree(5);


}
void PrintLine(int spaces, int stars) {


	for (int j = 0; j < spaces; j++) {

		cout << " ";
	}
	for (int i = 0; i < stars; i++) {
		cout << "*";
	}


}
void PrintTriangle(int indent, int lines) {
	int star = 1;
	for (int i = 0; i < lines; i++) {

		PrintLine(indent, star);
		cout << endl;
		star += 2;
		indent -= 1;
	}
}
void PrintTree(int triangles) {
	for (int i = 0; i <= triangles; i++) {
		PrintTriangle(triangles, i);

	}
}