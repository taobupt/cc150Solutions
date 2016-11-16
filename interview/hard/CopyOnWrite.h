#include"Header.h"
class LazyString{
private:
	char* _Ptr;
	int _Len;
public:
	const char* get()
	{
		return _Ptr;
	}
	LazyString(const char* str)// new storage
	{
		 _Len = strlen(str);
		_Ptr = new char[_Len + 1 + 1];
		strcpy(_Ptr, str);
		_Ptr[_Len + 1] = 0;
	}
	LazyString(LazyString &str)// share storage
	{
		this->_Ptr=str._Ptr;
		this->_Len = str._Len;
		this->_Ptr[_Len + 1]++;
	}
	void copy_from(const char*str)// new storage
	{
		_Ptr[_Len + 1]--;
		_Len = strlen(str);
		_Ptr = new char[_Len + 1 + 1];
		strcpy(_Ptr, str);
		_Ptr[_Len + 1] = 0;
	}
	~LazyString()
	{
		_Ptr[_Len + 1]--;
		if (_Ptr[_Len + 1] == 0)delete[] _Ptr;
	}

};