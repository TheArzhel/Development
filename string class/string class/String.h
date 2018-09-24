#ifndef STRING_H
#define STRING_H

#include <cstring>

class String
{
private:
	unsigned int char_numb = 0;
	char* str = nullptr;

public:
	// constructor

	String() : char_numb(0), str(nullptr) {}

	String(const char* string_pointer) :
		char_numb(strlen(string_pointer)),
		str(new char[char_numb + 1])
	{
		strcpy_s(str, char_numb + 1, string_pointer);
	}

	String(const String &string_ref) :
		char_numb(string_ref.char_numb),
		str(new char[char_numb + 1])
	{
		strcpy_s(str, char_numb + 1, string_ref.str);
	}

	//destructor 

	virtual ~String()
		{
		delete[] str;
		}

	//methods

	bool empty() const
	{
		return char_numb == 0;
	}

	unsigned int size() const
	{
		return char_numb;
	}

	void clear() 
	{
		delete[] str;
		str = nullptr;
		char_numb = 0;
	}
	
	const char* pointer() const
	{
		return str;
	}

	//overload operators

	String operator=(const String &string_ref)
	{
		delete[] str;
		char_numb = string_ref.char_numb;
		str = new char[char_numb + 1];
		strcpy_s(str, char_numb + 1, string_ref.str);
		return *this;
	}

	String operator+=(const String &string_ref)
	{
		unsigned int new_char_numb = char_numb + string_ref.char_numb;
		char *new_str = new char[new_char_numb + 1];
		strcpy_s(new_str, new_char_numb + 1, str);
		strcat_s(new_str, new_char_numb + 1, string_ref.str);
		delete[] str;
		char_numb = new_char_numb;
		str = new_str;
		return *this;
	}

	String operator+ (const String &string_ref) const
	{
		String concatenation(str);
		concatenation += string_ref;
		return concatenation;
	}

	bool operator== (const String &string_ref) const
	{
		return strcmp(str, string_ref.str) == 0;
	}

	bool operator!=(const String &string_ref) const
	{
		return strcmp(str, string_ref.str) != 0;
	}
	

};
#endif // !STRING_H

