template <class T>
class ConsCell
{
public:
	//making and deleting nodes
	void add(T);
        void remove(int);
        void insert(int, T);
        //getters
	ConsCell<T>* getptr(T);
	T getval(int);
	T& operator[](int index);
	//setters
	void setnode(int, T);
	//ctors
	ConsCell(T);
	ConsCell(const ConsCell<T>&);
	//assignment operator
	ConsCell<T> &operator= (const ConsCell&);
	//dtor
	~ConsCell();
	//printing
	void print(char mode = 'v');
private:
	T val;
	ConsCell<T> *next;
	ConsCell();
};
