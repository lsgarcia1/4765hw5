#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cout << "Enter a string" << endl;
        getline(cin, input);
	
	for (int i = 0, len = input.size(); i < len; i++)
	{
		if (ispunct(input[i]) || isspace(input[i]))
		{
			input.erase(i--, 1);
			len = input.size();
		}
		else 
		{
			input[i] = tolower(input[i]);
		}
		
	}

	cout << input;
	return 0;
}
