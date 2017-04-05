#include <iostream>

using namespace std;

//#PASSING BY VALUE
//When a normal variable is passed by value, C++ copies the value of the argument into the function parameter.
//Because the parameter is a copy, changing the value of the parameter does not change the value of the 
//original argument.

void print_int_value(int x){
//	i have now a copy of x.
	x = x+1;
	cout << "Value of x inside function: " << x << endl;

}

//# PASSING BY REFERENCE (ARRAYS)
//However, because copying large arrays can be very expensive, C++ does not copy an array when an array is 
//passed into a function. Instead, a reference is passed.

void print_array_value(int a[]){
//	in the array case, i have a pointer to the array.
	a[1] = 5;
	cout << "Value of a[1] inside function: " << a[1] << endl;
}

//# PASSING BY REFERENCE
//Sometimes we intentionally want to pass params by reference for the function to modify them directly.
//e.g. if we want to return more than one value from a function! (functions return can only one value).

void increment_counters(int &x, int &y){
	x++;
	y++;
}

//# PASSING BY ADDRESS
//We can also pass params by address (as a pointer). Note that passing by address actually passess the address by value.
//if i change the pointer address inside the function, it will only impact the copy inside the func.
//if i needed to change the pointer address, then i should pass the pointer by reference (as done before).

int main(int argc, char **argv)
{
	
//	Usually, params are passed by value
	int x = 1;
	cout << "Value of x before function call: " << x << endl;
	print_int_value(x);
	cout << "Value of x after function call: " << x << endl;
	
//	Arrays are passed by reference!
	int a[] = {1,2,3,4};
	cout << "Value of a[1] before function call: " << a[1] << endl;
	print_array_value(a);
	cout << "Value of a[1] after function call: " << a[1] << endl;
	
//	Sometimes we pass args by reference
	int y = 1;
	cout << "Value of x, y before function call: " << x << ", "<< y << endl;
	increment_counters(x, y);
	cout << "Value of x, y after function call: " << x << ", " << y << endl;
	
	return 0;
}
