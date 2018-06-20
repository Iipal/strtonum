#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct createNumberString {
private:
	int const _sizeStr = 0;
	int *_numStr = new int[_sizeStr];
public:
	createNumberString(int const sizeStr) : _sizeStr(sizeStr) { }
	createNumberString(createNumberString const *cNS) : _sizeStr(cNS->_sizeStr) { }

	void setENS(const int i, const int value) { _numStr[i] = value; }
	void showNS() const {
		for (int i(0); i < _sizeStr; ++i)
			cout << _numStr[i];
	}
	
	~createNumberString() { delete[] _numStr; }
};
class strtoNum {
private:
	string str;
public:
	strtoNum(const string _str) : str(_str) { }
	strtoNum(strtoNum const *stN) : str(stN->str) { }

	createNumberString* convert(strtoNum const _str) {
		int sizeNumStr = 0;

		for (int i(0); i < _str.str.length(); ++i) {
			if ((int)_str.str[i] < 10)			sizeNumStr += 1;
			else if ((int)_str.str[i] < 100)	sizeNumStr += 2;
			else if ((int)_str.str[i] < 1000)	sizeNumStr += 3;
		}

		createNumberString *numStr = new createNumberString(sizeNumStr);

		for (int i(0); i != _str.str.length(); ++i) {
			if ((int)_str.str[i] < 10)
				numStr->setENS(i, (int)_str.str[i]);
			else if ((int)_str.str[i] < 100) {
				numStr->setENS(i, ((int)_str.str[i] / 10));
				numStr->setENS((i + 1), ((int)_str.str[i] % 10));
			}
			else if ((int)_str.str[i] < 1000) {
				numStr->setENS(i, ((int)_str.str[i] / 100));
				numStr->setENS((i + 1), (((int)_str.str[i] / 10) % 10));
				numStr->setENS((i + 2), ((int)_str.str[i] % 10));
			}
		}
		return numStr;
	}
};

int main() {
	strtoNum *_str = new strtoNum("Hello");
	createNumberString *numArray = _str->convert(_str);

	numArray->showNS();

	system("pause");
	return 0;
}