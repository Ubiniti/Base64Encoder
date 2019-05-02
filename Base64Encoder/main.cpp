#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

char toBase64Char(unsigned int code)
{
	if (code <= 25)
	{
		return (char)(code + 65);
	}
	if (code <= 51)
	{
		return (char)(code + 97 - 26);
	}
	if (code <= 61)
	{
		return (char)(code + 48 - 52);
	}
	if (code == 62)
	{
		return '+';
	}
	if (code == 63)
	{
		return '/';
	}
	if (code >= 64)
	{
		return '=';
	}
}

string toBase64(string text)
{
	string output = "";
	char c1, c2, c3, c4;

	for (int i = 0; i < text.length() - 2; i += 3)
	{
		char first6Bits = (text[i] & 0b11111100) >> 2,
			second6Bits = ((text[i] & 0b00000011) << 4) | ((text[i+1] & 0b11110000) >> 4),
			third6Bits = ((text[i+1] & 0b00001111) << 2) | ((text[i+2] & 0b11000000) >> 6),
			fourth6Bits = (text[i + 2] & 0b00111111);
		c1 = toBase64Char((int)first6Bits);
		c2 = toBase64Char((int)second6Bits);
		c3 = toBase64Char((int)third6Bits);
		c4 = toBase64Char((int)fourth6Bits);

		output += c1;
		output += c2;
		output += c3;
		output += c4;
	}
	
	return output;
}

int main(char **argc, int argv)
{
	string text;
	string encoded;

	cout << "Text to encode: " << endl;
	cin >> text;

	encoded = toBase64(text);

	cout << encoded << endl;

	cin.get();
	cin.get();

	return 0;
}