#include <iostream>
#include <string>

typedef const int cint; // just for try used this

using std::cout;
using std::endl;
using std::string;

struct NumberArray {
private:
	cint _sizeArr = 0;
	int *_numArr  = new int[_sizeArr];
public:
	NumberArray(      cint size      ) : _sizeArr(size) { }
	NumberArray(const NumberArray *NS) : _sizeArr(NS->_sizeArr) {
		for (int i(0); i != NS->_sizeArr; ++i)
			this->_numArr[i] = NS->_numArr[i];
	}

	void setENA(cint i, cint value) { _numArr[i] = value; }
	void getNA ()       const       {
		for(int i(0); i != _sizeArr; ++i)
			cout << _numArr[i] << ' ';
		cout << endl;
	}
	
	~NumberArray() { delete[] _numArr; }
};

class String {
private:
	string _str;
public:
	String(const string	 str ) : _str(   str   ) { }
	String(const String  *stN) : _str(stN->_str) { }

	void getStr() { cout << _str << endl; }

	NumberArray *convert(const String str) {
		NumberArray *numArr = new NumberArray(str._str.length());

		for (int i(0); i != str._str.length(); ++i)
			numArr->setENA(i, (int)str._str[i]);

		return numArr;
	}
};

int main() {
	String			*str		= new String("Hello");
	NumberArray		*numArr		= str->convert(str);

	str->getStr();
	numArr->getNA();

	system("pause");

	delete str;
	delete numArr;
	
	return 0;
}