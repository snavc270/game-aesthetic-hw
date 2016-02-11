#include <iostream>
#include <cctype>
#include <string>


using namespace std; 

int main(){
	string command; 
	cout << "type a command: ";
	getline (cin,command);
	cout << "\n";
	for (int i= 0; i <command.size(); i++){
		command.at(i)= toupper(command.at(i));
	}

	cout<< "Converted command to all caps: " << command << endl; 

	string word1 = "";
	string word2 = ""; 
	string lastword="";

	char c; 
	for (int i= 0; i < command.size(); i++){
		c = command.at(i); 
		if (isspace(c) && word1 != ""){
			break; 
		}
		if(!isspace(c)){
			word1 += c; 
		}
	}

	// for (int i = word1.size(); i < command.size(); i++){
	// 	c = command.at(i); 
	// 	if (!isspace(c)) {
	// 		word2 += c; 
	// 	}

	// 	//only accept first two words 
	// 	if (isspace(c) && word2!= ""){
	// 		break; 
	// 	}
	// }


	for (int i= word2.size(); i< command.size(); i++){
		c = command.at(i);
		if(!isspace(c)){
			lastword += c; 
		}
		if (isspace(c) && lastword!= ""){
			break; 
		}
	}
	// for (int i = word2.size(); i<command.size(); i++){
	// 	c = command.at(i); 

	// 	if(!isspace(c)){
	// 		word2+= c;
	// 	}
	// 	if(isspace(c) && word2 !=""){
	// 		break; 
	// 	}
	// }

	cout << "word1 is: " << word1 << endl; 
	// cout << "word2 is: " << word2 << endl; 
	cout << "lastword is"<< lastword << endl; 
 
}