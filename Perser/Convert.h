/////////Class convert(interface)
#include "getStringElements.h"
#include "getValues.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Convert
{
private:
	getStringElements *parser;
	getValues *convert;

public:
	Convert();
	int get_elements_size(const char* );
	bool getBadSymvol(string& );
	void get_Elements(const char* ,unsigned int *);
	float* get_verticles(const char* ,char ,short& );
	~Convert();
};
