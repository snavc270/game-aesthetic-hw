#include <iostream>
#include <string> 

using namespace std; 

class Hallway{
	public: 
	string description; 
		bool move; 
		bool stay; 
		bool start; 
		bool exitHall; 
};

class Room{
	public:
	string description; 
	bool enterRoom; 
	bool flashlight; 

};

class TinyRoom{
public: 

};

int main(){

	string input; 
	Hallway map[4][1]; 
	Room map2[4][4]; 

	int x= 0; 
	int y= 1; 

	int b= 0; 

	for(int i=0; i<1; i++){
		for(int j=0; j<3; j++){
			map[j][i].move=false;
			map[j][i].stay=false;
			map[j][i].exitHall= false; 
			map[j][i].start= true; 
		}
	}

	map[0][1].description= "You are in a narrow hallway. You want desperately to continue to the room at the end of the hall." "\n" "CONTINUE or STAY?"; 
	map[1][1].description= "You hesitate before entering the room. You have a nagging feeling that you shouldn't be there and the others will quickly discover you're a fraud." "\n" "ENTER or STAY?"; 
	map[2][1].description= "You enter a dark room and hear faint voices. A wave of panic overcomes you." "\n" "MOVE or EXIT?" ;
	map[3][1].description= "";  	

		

	for(int i=1; i<4; i++){
		for(int j=3; j<7; j++){
			map2[j][i].enterRoom= false; 
			map2[j][i].flashlight= false; 
			// map2[j][i].move=false;
			// map2[j][i].stay=false;
			// map2[j][i].start= true; 
		}
	}
	int x2= 0; 
	int y2= 0; 
	map2[1][0].description= "You grasp around wildly in the dark when suddenly your fingers grope the outline of what feels like a flashlight." "\n" "TAKE it or LEAVE it?"; 
	map2[2][0].description= "You click the flashlight on. Looks like it needs batteries."; 

	while(input !="q"){
		cout<< map[x][y].description << endl; 
		cout<< map2[x2][y2].description<< endl; 
		cin >> input; 

		if(input == "CONTINUE"){
			if(map[x][y].start == true){
			x++; 
			map[x][y].start = false; 
			map[x][y].move = true; 
			} else {
			cout<< "did you mean to say CONTINUE?" << "\n"; 
			}

		}else if(input == "STAY"){
			cout<< "You make no progress, crippled by your own fear." << endl; 
		
		} else if(input == "ENTER"){
			if(map[x][y].move ==true){
				x++; 
				map[x][y].exitHall= true; 
			}
		} else if(input == "MOVE"){
			if(map[x][y].exitHall== true){ 
			map2[x][y].enterRoom= true; 
			
			x2++ ; 
		} else if(input == "EXIT"){
			if(map[x][y].exitHall== true){
			cout<< "You make no progress, crippled by your own fear." << endl;
			}
		} else if(input == "TAKE"){
			if(map[x][y].exitHall== true){
			map2[x][y].flashlight = true;
			x2++;  
			// cout<< "batteries:" << "" << b << endl;  
			}
		}
		
	}
	}
return 0; 
}