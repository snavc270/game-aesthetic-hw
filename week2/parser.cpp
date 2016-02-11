#include <iostream>
#include <cctype>
#include <string>

using namespace std; 

int main() 
{

	cout<< "type something: " ;
	string answer; 
	string answer2; 
	cin >> answer; 
	cin >> answer2; 
	cout << "you responded: " << answer << "\n"; 

	for (int i= 0; i < answer.size(); i++){
		cout <<" converting letter " << answer.at(i) << "\n";
		answer.at(i) = toupper(answer.at(i)); 
	}
	for (int i= 0; i < answer2.size(); i++){
		cout <<" converting letter " << answer2.at(i) << "\n";
		answer2.at(i) = toupper(answer2.at(i)); 
	}
	cout << answer  << endl;  
	cout << answer2 << endl; 

	return 0; 
}