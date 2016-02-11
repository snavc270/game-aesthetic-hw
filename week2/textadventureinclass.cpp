#include <iostream>  
#include <string> 
using namespace std; 

class Room {
public:
	string description;
	bool canGoNorth ;
	bool can3GoSouth ;
	bool canGoEast ;
	bool canGoWest ;
};
int main(){
	
	//string to store input 

	string input; 

	Room map[3][3];

	int x= 1; 
	int y= 1; 
	

		//2 variables to store player position 
	//move players position based on north south east west 
	//2d array to store map 

	for(int i= 0; i<3; i++){
				for(int j=0; j<3; j++){
					map[j][i].description= "There's nothing here!";
					map[j][i].canGoWest = false;
					map[j][i].canGoEast = false;  
					map[j][i].canGoNorth = false;
					map[j][i].canGoSouth = false;  

				}
				
			}

			map[0][1].description= "here lies a street cookie";
			map[2][0].description= "you've found gold";

			map[1][1].description= "There's a path going east and west.";
			map[1][1].canGoWest = true;
			map[1][1].canGoEast = true; 

			map[1][3].description= "There's a path going north."; 
			map[1][3].canGoNorth = true; 

	while(input != "q"){

		cout<< "you are at" << x << " " << y << endl;
		cout << map[x][y].description << endl;	

		cout << "which direction?" << endl; 
		cin >> input; 

			if(input == "NORTH"){
				if(map[x][y].canGoNorth ==true){	
					y--;
				} else{
					cout << "you can't go that way stupid" << "\n";
				}
			} else if(input == "SOUTH"){
				if(map[x][y].canGoSouth == true){
					y++;
				} else {
					cout << "you can't go that way stupid" << "\n";
				}
				
			} else if(input == "EAST"){
				if(map[x][y].canGoEast == true){
					x++;
				} else {
					cout << "you can't go that way stupid" << "\n";
				}

			} else if(input == "WEST"){
				if(map[x][y].canGoWest == true){
					x--; 
				} else {
					cout << "you can't go that way stupid" << "\n";
				}
			} else{
				cout << "I don't understand" << input << "\n";  
			}

			
			// for(int i= 0; i<10; i++){
			// 	for(int j=0; j<10; j++){
			// 		cout << map[j][i];
			// 	}
			// 	cout<<endl; 
			}
		
		return 0; 	
	}
		
	

	//game loop is while loop
	//check for exit condition in while loop (while != exit condition)

	
	

	//move the players position in the map
