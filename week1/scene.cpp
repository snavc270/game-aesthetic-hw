#include <iostream>

using namespace std; 

class Obstacle {
public: 
	Obstacle(int _x=1, int _y = 1, int _vx=1, int _vy =1); 
	void update(int r, int c); 
	int getX(); 
	int getY(); 


private: 
	int x; 
	int y; 
	int vx; 
	int vy; 
}; 

Obstacle::Obstacle(int _x, int _y, int _vx, int _vy):
	x(_x), 
	y(_y), 
	vx(_vx),
	vy(_vy)

	{}

void Obstacle::update(int r, int c){
	
	srand(time(NULL));
		cout<< rand() % 2 <<endl; 
	
	vx = rand()% 2; 
	if(x<0 || x> r-5){
		vx = vx * -1; 
	}
	if(x> 0 && x< r-5){
		x += vx * (rand() % 2); 
	}
	// else {
		 
	// 	x -= vx * (rand() % 2); 
	// }

	// if(y >0 && y < c-5){
	// 	y +=vy * (rand() % 2); 
	// }else {
	
	// 	y -= vy * (rand() % 2); 
	// }

	vy = rand()% 2; 
	if(y<0 || y> c-5){
		vy = vy * -1; 
	}
	if(y> 0 && y< c-5){
		y += vy * (rand() % 2); 
	}
} 

int Obstacle::getX(){
	return x; 
}

int Obstacle::getY(){
	return y; 
}


class Player {
public: 
	Player(int _x=1, int _y = 1, int _vx =1, int _vy =1); 

	// void update(int r, int c); 
	void up(int r, int c); 
	void down(int r, int c);
	void left(int r, int c);
	void right(int r, int c);
	int getX(); 
	int getY(); 
	// char input; 

private: 
	int x; 
	int y; 
	int vx; 
	int vy; 
	
}; 

Player::Player(int _x, int _y, int _vx, int _vy):
	x(_x), 
	y(_y), 
	vx(_vx),
	vy(_vy)

{}

// void Player::update(int r, int c){
// 	if(input == 'w'){
// 		y-=vy; 
// 	}

// 	if(input == 's'){
// 		y+=vy; 
// 	}
// 	if(input == 'a'){
// 		x-= vx;
// 	}
// 	if(input =='d'){
// 		x+= vx; 
// 	}
// }

void Player::up(int r, int c){
	// if(y>0 && y < c-1){
		y -= vy; 
	
}
void Player::down(int r, int c){
	// if(y>0 && y < c-1){
		y += vy; 
	
}

void Player::left(int r, int c){
 	// if(x>0 ){
 		 
 		x -= vx;
 	
 }

 void Player::right(int r, int c){
 	// if(x>0 ){
 		x += vx; 
 	
 }

int Player::getX(){
	return x; 
}

int Player::getY(){
	return y; 
}

int main(){
	Obstacle obstacle; 
	Player player; 

	cout << "use W A S D to move" << endl; 
	cout << "get to the star" << endl; 
	
	const int COLS = 35; 
	const int ROWS= 20; 
	const int TARCOL= 5;
	const int TARROW= 19; 
	char grid[COLS][ROWS]; 

	for(int i= 0; i<ROWS; i++){
		for(int j=0; j<COLS; j++){
			grid[j][i] = '-'; 
		}
	}

	
	int x = 1; 
	int y = 1; 
	int vx = 1; 
	int vy = 1; 

	char input; 
	



	while(input != 'q'){
		
		grid[TARCOL][TARROW]= '*';

		// player.update(ROWS, COLS); 

		if(input == 'w'){
		player.up(ROWS, COLS);
		}
		if(input == 's'){
			player.down(ROWS, COLS);
		}

		if(input == 'a'){
			player.left(ROWS, COLS);
		}

		if(input == 'd'){
			player.right(ROWS, COLS); 
		}

		grid[player.getX()+25][player.getY()+1]= 'O'; 
		grid[player.getX()+27][player.getY()+1]= 'O'; 
		grid[player.getX()+26][player.getY()+1]= '_'; 
		grid[player.getX()+25][player.getY()]= '^'; 
		grid[player.getX()+27][player.getY()]= '^'; 
		grid[player.getX()+26][player.getY()]= '^';
		
		if((player.getX()+26)==TARROW && (player.getY()+1)==TARCOL){
			cout << "You win" << endl; 
		 }

		obstacle.update(ROWS, COLS); 

		for(int i=0; i<15; i++){
		grid[obstacle.getX()+i][obstacle.getY()] = '_'; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		grid[obstacle.getX()+i][obstacle.getY()-1] = '_' ; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}


		grid[obstacle.getX()][obstacle.getY()] = '|';
		grid[obstacle.getX()][obstacle.getY()-1]= '-'; 
		grid[obstacle.getX()+15][obstacle.getY()] = '|'; 
		grid[obstacle.getX()+15][obstacle.getY()-1] = '-'; 


		for(int i=0; i<10; i++){
		grid[obstacle.getX()+i+20][obstacle.getY()+3] = '_'; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}
		for(int i=0; i<10; i++){
		grid[obstacle.getX()+i+20][obstacle.getY()+2] = '_' ; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}


		grid[obstacle.getX()+20][obstacle.getY()+3] = '|';
		grid[obstacle.getX()+20][obstacle.getY()+2]= '-'; 
		grid[obstacle.getX()+30][obstacle.getY()+3] = '|'; 
		grid[obstacle.getX()+30][obstacle.getY()+2] = '-'; 

		for(int i=0; i<12; i++){
		grid[obstacle.getX()+i+-1][obstacle.getY()+5] = '_'; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}
		for(int i=0; i<12; i++){
		grid[obstacle.getX()+i-1][obstacle.getY()+4] = '_' ; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}


		grid[obstacle.getX()-1][obstacle.getY()+5] = '|';
		grid[obstacle.getX()-1][obstacle.getY()+4]= '-'; 
		grid[obstacle.getX()+11][obstacle.getY()+5] = '|'; 
		grid[obstacle.getX()+11][obstacle.getY()+4] = '-'; 

		for(int i=0; i<20; i++){
		grid[obstacle.getX()+i+5][obstacle.getY()+8] = '_'; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}
		for(int i=0; i<20; i++){
		grid[obstacle.getX()+i+5][obstacle.getY()+7] = '_' ; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}


		grid[obstacle.getX()+5][obstacle.getY()+8] = '|';
		grid[obstacle.getX()+5][obstacle.getY()+7]= '-'; 
		grid[obstacle.getX()+25][obstacle.getY()+8] = '|'; 
		grid[obstacle.getX()+25][obstacle.getY()+7] = '-'; 

		for(int i=0; i<10; i++){
		grid[obstacle.getX()+i+25][obstacle.getY()+11] = '_'; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}
		for(int i=0; i<10; i++){
		grid[obstacle.getX()+i+25][obstacle.getY()+10] = '_' ; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}


		grid[obstacle.getX()+25][obstacle.getY()+11] = '|';
		grid[obstacle.getX()+25][obstacle.getY()+10]= '-'; 
		grid[obstacle.getX()+35][obstacle.getY()+11] = '|'; 
		grid[obstacle.getX()+35][obstacle.getY()+10] = '-'; 

		for(int i=0; i<20; i++){
		grid[obstacle.getX()+i-1][obstacle.getY()+13] = '_'; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}
		for(int i=0; i<20; i++){
		grid[obstacle.getX()+i-1][obstacle.getY()+12] = '_' ; 
		// grid[obstacle.getY()-1][obstacle.getY()] = '_';
		}


		grid[obstacle.getX()-1][obstacle.getY()+13] = '|';
		grid[obstacle.getX()-1][obstacle.getY()+12]= '-'; 
		grid[obstacle.getX()+19][obstacle.getY()+13] = '|'; 
		grid[obstacle.getX()+19][obstacle.getY()+12] = '-'; 

		for (int i=0; i<ROWS; i++){
			for(int j=0; j< COLS; j++){
				cout << grid[j][i]; 

			}
			cout << endl; 
		}

		for (int i= 0; i <ROWS; i++){
			for (int j=0; j<COLS; j++){
				grid[j][i] = '-'; 
			}
		}


		cin >> input; 
	}
	return 0; 
}