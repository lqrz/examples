#include <iostream>

using namespace std;

//When a normal variable is passed by value, C++ copies the value of the argument into the function parameter.
//Because the parameter is a copy, changing the value of the parameter does not change the value of the 
//original argument.

void print_int_value(int x){
//	i have now a copy of x.
	x = x+1;
	cout << "Value of x inside function: " << x << endl;

}

//However, because copying large arrays can be very expensive, C++ does not copy an array when an array is 
//passed into a function. Instead, a reference is passed.

void print_array_value(int a[]){
//	in the array case, i have a pointer to the array.
	a[1] = 5;
	cout << "Value of a[1] inside function: " << a[1] << endl;
}

int main(int argc, char **argv)
{
	int x = 1;
	cout << "Value of x before function call: " << x << endl;
	print_int_value(x);
	cout << "Value of x after function call: " << x << endl;
	
	int a[] = {1,2,3,4};
	cout << "Value of a[1] before function call: " << a[1] << endl;
	print_array_value(a);
	cout << "Value of a[1] after function call: " << a[1] << endl;
	
	return 0;
}
