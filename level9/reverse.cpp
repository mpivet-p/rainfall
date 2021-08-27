#include <unistd.h>
#include <string.h>

class N {

private:
	int		_number;
	char	_annotation[100];

public:
	N(int n) {
		_number = n;
	};

	void setAnnotation(char *str) {
		memcpy(_annotation, str, strlen(str));
	}

	virtual int operator+(const N& other) {
		return (this->_number + other._number);
	}

	virtual int operator-(const N& other) {
		return (this->_number - other._number);
	}

};

int		main(int argc, char *argv[])
{
	N *a;
	N *b;

	if (argc <= 1)
	{
		_exit(1);
	}

	a = new N(5); //_Znwj <=> new    108 (0x6c) => size of instance
	b = new N(6);

	a->setAnnotation(argv[1]);
	return (*a + *b); //_ZN1NplERS_(esp+0x14, esp+0x10)
}
