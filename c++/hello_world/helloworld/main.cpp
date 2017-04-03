#include <iostream>

using namespace std;

//forward declaration
void print_value(int);
int read_input();

int main()
{
    int x;
    x = read_input();
    print_value(x);

    return 0;
}

void print_value(int _number){
    cout << "You entered the value: " << _number;
}

int read_input(){
    int x;
    cout << "Input an integer value: ";
    cin >> x;

    return x;
}
