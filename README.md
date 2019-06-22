# ConsCell
A linked list class similar to a LISP cons cell.
Each ConsCell contains some data and a pointer to the next ConsCell.

To create a new ConsCell:

ConsCell<int> cell(5);

5 is the value of the first cell.

cell.add(6);
cell.add(7);
...

cell.insert(0, 1);
... inserts a new value before 5.

Inserting a new value 'a' at index 'x':
	- Create a new ConsCell on the heap
	- Set the value to the value of the cell at 'x' - 1
	- Set the 'next' pointer of the new cell to the 'next' pointer of the cell at 'x' - 1
	- Set the value of the cell at 'x' - 1 to 'a'
	- Set the 'next' pointer of this cell to the address of the new cell.
