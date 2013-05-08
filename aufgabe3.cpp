#include <cstring> // Not part of STL, so we can use strcpy and strcat
#include <iostream>

using namespace std;

class String {
public:
	String() {
		m_length = 0;
		m_chars = new char[0];
	}
	
	String(char* chars) {
		m_length = strlen(chars);
		m_chars = new char[m_length];
		strcpy(m_chars, chars);
	}
	
	String(const String& s) {
		m_length = s.m_length;
		m_chars = new char[m_length];
		strcpy(m_chars, s.m_chars);
	}
	
	~String() {
		delete[] m_chars;
	}
	
	String& operator= (const String& rhs) {
		String tmp(rhs);
		swap(tmp);
		return *this;
	}
	
	char operator[] (int i) {
		return m_chars[i];
	}
	
	String& operator+= (const String& rhs) {
		strcat(m_chars, rhs.m_chars);
		return *this;
	}
	
	String operator+ (const String& rhs) {
		return String(*this) += rhs;
	}
	
	friend ostream& operator<< (ostream& lhs, const String& rhs) {
		lhs << rhs.m_chars;
		return lhs;
	}

private:
	char* m_chars;
	unsigned int m_length;
	
	void swap(String& rhs) {
		// Because exercise forbids us to use std::swap()...
		int tmp_length = m_length;
		m_length = rhs.m_length;
		rhs.m_length = tmp_length;
		
		char* tmp_chars = m_chars;
		m_chars = rhs.m_chars;
		rhs.m_chars = tmp_chars;
	}
};

int main() {
	String s1;
	String s2("Hello");
	String s3(s2);
	s1 += s2; s2 = s3;
	cout << s2 << endl;
	cout << s2[ 2 ] << endl;
};
