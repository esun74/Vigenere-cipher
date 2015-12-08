#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std; 
const int X = 5;
const int Y = 26;
typedef char cipher[X][Y];

template <typename T>
void convert(T &thing);
void create(string word, cipher data);
vector<char> encode(string word, vector<char> sentence);

int main() {
	///*
	char temp;
	string word;
	vector<char> sentence;
	cout << "Keyword: ";
	cin >> word;
	cout << "Message to Encode: ";
	cin.ignore(100, '\n');
	cin.get(temp);
	do {
		sentence.push_back(temp);
		cin.get(temp);
	} while (temp != '\n');
	convert(word); 
	convert(sentence);
	sentence = encode(word, sentence);

	cout << "Encrypted Message: ";
	for (int i = 0; i < static_cast<int>(sentence.size()); i++)
		cout << sentence[i];
	cout << endl;
	return 0;
	//*/
}

template <typename T>
void convert(T &thing)
{
	for (int i = 0; i < thing.size(); i++)
		thing[i] = toupper(thing[i]);
}

void create(string word, cipher data)
{
	for (int i = 0; i < X; i++)
		for (int ii = 0; ii < Y; ii++)
			data[i][ii] = static_cast<char>(ii + static_cast<int>(word[i]) >= (65 + 26) ? ii + static_cast<int>(word[i]) - 26 : ii + static_cast<int>(word[i]));
}

vector<char> encode(string word, vector<char> sentence) {
	int count = 0;
	cipher data;
	vector<char> new_sentence;
	create(word, data);
	for (int i = 0; i < sentence.size(); i++)
	{
		if (sentence[i] == ' ' || !isalpha(sentence[i]))
			new_sentence.push_back(' ');
		else
		{
			new_sentence.push_back(data[count % 5][static_cast<int>(sentence[i]) - 65]);
			count++;
		}
	}	
	return new_sentence;
}
