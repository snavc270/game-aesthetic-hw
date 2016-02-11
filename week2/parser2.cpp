#include <iostream>
#include <cctype>
#include <string>

using namespace std; 


int main(){

	// cout << "write at least two words: ";
	// string answer; 
	// cin >> answer; 
	// cout << "\nFirst word was " << answer << "\n";
	// getline(cin, answer); 
	// cout << "followed by: " << answer << "\n"; 

	string name; 
	cout << "Please enter your full name: "; 
	getline (cin,name); 
	cout << "Hello, " << name << "!\n"; 

	for(int i= 0; i<name.size(); i++){
		name.at(i) = toupper(name.at(i)); 
	}
	cout << "Converted name: " << name << endl; 


	return 0; 
}