//Leonardo Garcia and Hannah Tippin
//Computer Security
//Homework 5

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
	double freq = 0.0;
	double upperBound;
	double lowerBound;

	cout << "Enter a string:" << endl;//outputs to the user
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

	cout << "\nSanitized String: \n" << input << endl;//outputs satitized string

	for (int i = 0; i < 26; i++)//compares letter frequency and outputs on any mismatches
	{
		freq = (double(alph[i]) / input.size()) * 100.0;//frequency of current character in the string
		upperBound = charFreq[i] + 5.0;//> 5% more than standard frequency
		lowerBound = charFreq[i] - 5.0;//> 5% less than standard frequency

		if (freq > upperBound || freq < lowerBound)//checks if the calculated freq is within 5% of the standard english freq
		{
			cout << "\nThere was a greater than 5% mismatch for: " << char(i + 'a') << endl;
			cout << "The standard english frequency for: "<< char(i + 'a') << " is: " << charFreq[i] << endl;
			cout << "The frequency of: " << char(i + 'a') << " in the string is: " << freq << endl;
		}
	}

	return 0;
}

/* Sources
* https://www.techiedelight.com/remove-whitespaces-string-cpp/
* https://www.geeksforgeeks.org/removing-punctuations-given-string/
* http://www.cplusplus.com/reference/cctype/tolower/
* https://www.tutorialspoint.com/cplusplus-program-to-find-the-frequency-of-a-character-in-a-string
* http://www.cplusplus.com/reference/string/string/getline/
*/