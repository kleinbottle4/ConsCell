#include <iostream>
#include "../ConsCell.cpp"
using namespace std;

void locallist()
{
	ConsCell<int> list(0);
	for (int i = 1; i <= 5; i++)
		list.add(i);
}

int main(int argc, const char ** argv)
{
	//ctor
	cout << "ctor...\n";
	ConsCell<int> list(0);
	list.print();
	cout << endl;

	//add
	cout << "add...\n";
	for (int i = 1; i <= 10; i++)
		list.add(i);
	list.print();
	cout << endl;

	//setval
	cout << "setnode...\n";
	list.setnode(0, 100);
	list.setnode(5, 200);
	list.setnode(10, 300);
	list.print();
	cout << endl;

	//getval
	cout << "getval...\n"
	<< "list.getval( 0):\t" << list.getval(0) << endl
	<< "list.getval( 5):\t" << list.getval(5) << endl
	<< "list.getval(10):\t" << list.getval(10) << endl
	<< endl;

	//getptr
	cout << "getptr...\n"
	<< "list.getptr( 0):\t" << list.getptr(0) << endl
	<< "list.getptr( 5):\t" << list.getptr(5) << endl
	<< "list.getptr(10):\t" << list.getptr(10) << endl
	<< endl;

	//operator[]
	cout << "operator[]...\n"
	<< "list[ 0]:\t" << list[0] << endl
	<< "list[ 5]:\t" << list[5] << endl
	<< "list[10]:\t" << list[10] << endl << endl
	<< endl
	<< "list[0] = -1; ...\n";
	list[0] = -1;
	cout << "list[5] = -2; ...\n";
	list[5] = -2;
	cout << "list[10] = -3; ...\n";
	list[10] = -3;

	cout << endl;
	list.print();
	cout << endl;

	//remove
	cout << "remove(0)...\n";
	list.remove(0);
	list.print();
	cout << "\nremove(1)...\n";
	list.remove(1);
	list.print();
	cout << "\nremove(2)...\n";
	list.remove(2);
	list.print();
	cout << endl;

	//insert
	cout << "Inserting val 512 at index 5...\n";
	list.insert(5, 512);
	list.print();
	cout << endl;

	//local list
	cout << "Creating list inside a subroutine in order to test destructor...\n";
	locallist();
	cout << endl;

	//dtor
	cout << "main is about to return.\n" << "list.print('a')...\n";
	list.print('p');
	cout << endl;
	cout << "Calling dtor...\n";
	return 0;
}
