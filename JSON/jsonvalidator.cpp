#include <iostream>
#include <string>
using namespace std;

bool isString();
bool isObj();
bool isColon();
bool isArray();
bool isNumber();
bool isBool();
bool isValue();
bool checkBound();
string isCommaOrEnd();


string str;
int index = 0;
int str_length = 0;

int main()
{
	/*
	
	*/

	cin >> str;
	while (str[str_length] != NULL) {
		str_length++;
	}
	//str_length = str.length;

	cout << (isValue()? "true" : "false") << endl;

	return 0;
}

bool checkBound()
{
	index++;
	if (index >= str_length) return false;
	return true;
}

bool isValue()
{
	if (index != 0) {
		if (checkBound() == false) return false;
	}
	if (str[index] == '{') {
		if (isObj() == false) return false;
	}
	else if (str[index] == '[') {
		if (isArray() == false) return false;
	}
	else if (str[index] == '"') {
		if (isString() == false) return false;
	}
	else if (isNumber() == false) return false;
	else if (isBool() == false) return false;
	
	return true;
}


bool isString(){
	if (checkBound() == false) return false;

	while (str[index] != '\"')
	{
		if (checkBound() == false) return false;
	}

	return true;
}

bool isColon(){
	if (checkBound() == false) return false;
	if (str[index] == ':') return true;
	return false;
}

bool isObj() {
	while (index < str_length) {

	if (str[++index] == '\"') {
		if (isString() == false) return false;
	}
	if (isColon() == false) return false;

	if (isValue() == false) return false;
	
	string stateCommaEnd = isCommaOrEnd();
	if (stateCommaEnd == "Comma");
	else if (stateCommaEnd == "EndOfObj") return true;
	else return false;
	}
	
	return false;
	
}

bool isArray() {
	while (index < str_length) {
		if (isValue() == false) return false;

		string stateCommaEnd = isCommaOrEnd();
		if (stateCommaEnd == "Comma");
		else if (stateCommaEnd == "EndOfArr") return true;
		else return false;
	}
	return false;
}

bool isNumber() {
	while (str[index+1] >= '0' && str[index+1] <= '9') {
		if (index++ >= str_length) return false;
	}
	return true;
}

bool isBool() {
	//수정필요
	return true;
}

string isCommaOrEnd() {
	if (index + 1 >= str_length) return "error";
	if (str[index + 1] == ','){
		index++;
		return "Comma";
	}
	if (str[index + 1] == '}') {
		index++;
		return "EndOfObj";
	}
	if (str[index + 1] == ']') {
		index++;
		return "EndOfArr";
	}

	return "error";
	
}

