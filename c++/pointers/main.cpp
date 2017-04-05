#include <iostream>

using namespace std;

//what are pointers used for:
//1) Arrays are implemented using pointers.
//2) The only way to dynamically allocate memory.
//3) Argument passing via reference.
//4) Allow linking structures.

int main(int argc, char **argv)
{
	int x = 5;
	int *ptr; // here the operator is not the dereference operator. Its part of the declaration.
	
	ptr = &x;
	
	cout << "Value: " << x <<endl;
	cout << "Address: " << &x << endl; //getting the vars address
	cout << "Address: " << ptr << endl;
	cout << "Value: " << *&x << endl; //dereference operator
	cout << "Value: " << *ptr << endl; //dereferencing the pointer
	
	return 0;
}
