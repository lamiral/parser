#include "Convert.h"

using namespace std;

	Convert::Convert()
	{
		parser = new getStringElements;
		convert = new getValues;
	}

	int  Convert::get_elements_size(const char* filepath)
	{
		ifstream file(filepath);
		if(!file.is_open())
		{
			cout << "Error file" << endl;
			return -1;
		}

		string str;
		int count = 0;

		while(getline(file,str))
		{
			if(str[0] == 'f')
			{
				count ++;
			}
		}

		file.close();

		return count*3;
	}

	bool Convert::getBadSymvol(string &str)
	{
		short i = 0;
		short size = str.size();
		while(i < size)
		{
			if(str[i] == '/')
			{
				return true;
			}
			cout << str[i];
			i++;
		}
		return false;
	}

	void Convert::get_Elements(const char *filepath,unsigned int *array)
	{
		ifstream file(filepath);

		if(!file.is_open())	
		{
			cout << "Error file" << endl;
			return;
		}	

		vector <string> vec;
		string str;

		while(getline(file,str))
		{
			if(str[0] == 'f')
			{
				vec.push_back(parser->strcatV(str,'f'));
			}
		}

		bool bad_symvol = false; 

		if(this->getBadSymvol(vec[4]))
		{
			bad_symvol = true;
		}
		else
		{
			bad_symvol = false;
		}

		short size = vec.size();
		short iter = 0;


		for(int i = 0;i<size;i++)
		{
			convert->get_Values(vec[i],array,iter,bad_symvol);
		}

		file.close();
	}

	float* Convert::get_verticles(const char *filepath,char flag,short &size_array)
	{
		vector <char *> mainVec;

		float *result_array;

		if(!parser->parseValues(filepath,mainVec,flag))
		{
			cout << "ERROR PARSE!!" << endl;
			return NULL;
		}

		const short size = mainVec.size();
		result_array = new float[size];
	
		for(int i = 0;i<size;i++)
		{
			result_array[i] = (float)(convert->getValueAfterPoint(mainVec[i])+ convert->getValueBeforePoint(mainVec[i]));
		}

		size_array = size;
		return result_array;
	}

	Convert::~Convert()
	{
		delete parser;
		delete convert;
	}
