#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int alph[26] = { 0 };
	double charFreq[26] = { 8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03, 5.92, 
							7.31, 0.10, 0.69, 3.98, 2.61, 6.95, 7.68, 1.82, 0.11, 
							6.02, 6.28, 9.10, 2.88, 1.11, 2.09, 0.17, 2.11, 0.07 };

	int j;

	cout << "Enter a string" << endl;//outputs to the user
        getline(cin, input);//reads the users input
	
	for (int i = 0, len = input.size(); i < len; i++)//iterate through the string
	{
		if (ispunct(input[i]) || isspace(input[i]))//case where input[i] is not a character
		{
			input.erase(i--, 1);//removes punctuation or whitespace
			len = input.size();//update size of the string
		}
		else//case where input[i] is a character
		{
			input[i] = tolower(input[i]);//converts character to lowercase
			j = input[i] - 'a';//computes what character input[i] is
			++alph[j];//increment counter for the specific character
		}
		
	}
	cout << input<<endl;
	cout<<"Frequency of all alphabets in the string is:"<<endl;
    for (int i = 0; i < 26; i++)
    cout<< char(i + 'a')<<" : "<< alph[i]<< endl;

	
	return 0;
}
