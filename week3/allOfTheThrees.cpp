#include <iostream>
#include <fstream>
using namespace std; 

char getTile(int x, int y, unsigned char data[], int size, int w, int h);
int writeBytes(int offset, unsigned char data[]);

int main(){
	ifstream map("bit.bmp"); 

	const int BMPSIZE = 248; 
	unsigned char bmpBytes[BMPSIZE]; 
	unsigned char data; 

	int whichByte = 0; 
	while(map >> data) {
		bmpBytes[whichByte] = data; 
		whichByte++; 
	}

	bool playing= true; 

	map.close(); 

	const int w = 8; 
	const int h = 8; 

	char grid[h][w]; 

	for (int i= 0; i < h; i++){
		for (int j= 0; j<w; j++){
			grid[j][i] = getTile(j,i, bmpBytes, BMPSIZE, w, h); 
		}
	}

	
	while(playing == true){
	while(true){

		cout << "\n\n\n\n"; 
		cout << "YOU WILL MATCH THE 3'S. DO NOT PRESS CONTROL-C."; 
		cout << "\n\n\n\n"; 
		cout<< "\t    0 1 2 3 4 5 6 7\n"; 
		cout<< "\t    ===============\n"; 

		//drawing the grid
		for(int i = 0; i<h; i++) {
			for (int j = 0; j < w; j++) {
				if(j == 0){
					cout << "\t" << i << " ||"; 
				}
				cout << grid[j][i] << " "; 
				}
				cout << endl; 
			}

		cout << "\n\n"; 

		int inputX; 
		int inputY; 
		int inputSwapX; 
		int inputSwapY; 

		cout<< "\tChoose x coord: ";
		cin >> inputX; 

		cout<< "\tChoose y coord: "; 
		cin >> inputY; 

		cout<< "\tSwap with x coord: ";
		cin >> inputSwapX; 

		cout<< "\tSwap with y coord: "; 
		cin >> inputSwapY; 
		

		//swaps grid pos

		int swapNumber; 

		if(abs(inputX-inputSwapX)==1 || abs(inputY-inputSwapY)==1){
			char temp = grid[inputX][inputY];
			grid[inputX][inputY] = grid[inputSwapX][inputSwapY];
			grid[inputSwapX][inputSwapY] = temp;
			swapNumber ++; 
		} else {
			cout<< "You can't do that!" << endl; 
			}
		
	
	
		

		//check for matches:
		//STUDENTS: (advanced) - to do this properly you'll need a recursive function.
		int matches = 0; 
		for (int i = -1; i<2; i++){
			for (int j = -1; j<2; j++){
				// if (grid[inputX][inputY] == grid[inputX+i][inputY+j]){
				// 	matches++; 
				// 	cout << "you got a match! " << inputX+i << " , "<< inputY +j << endl;
				//checking in the x direction
				   if(grid[inputX][inputY]==grid[inputX+i][inputY]){
				   	matches++; 
				   	// cout<< "you got a match! " << inputX+i << endl; 
					} 
					//checking in the y direction
					if(grid[inputX][inputY]==grid[inputX][inputY+j]) {
					matches++; 
					// cout<< "you got a match! " << inputY+j << endl; 
					}


					 if(grid[inputSwapX][inputSwapY]==grid[inputSwapX+i][inputSwapY]){
				   	matches++; 
				   	// cout<< "you got a match! " << inputX+i << endl; 
					} 

					if(grid[inputSwapX][inputSwapY]==grid[inputSwapX][inputSwapY+j]) {
					matches++; 
					// cout<< "you got a match! " << inputY+j << endl; 
					}
				// if (grid[inputSwapX][inputSwapY] == grid[inputSwapX+i][inputSwapY+j]){
				// 	matches++; 
				// 	cout << "you got a match!" << inputSwapX+i << ", " << inputSwapY+j << endl; 
				// }				
			}
		}



		
		if (matches >= 2) {
			cout<< "you got a match!" << endl; 

			for(int i=-1; i<2; i++){
				for (int j = -1; j <2; j++){
					if(grid[inputX+i][inputY+j]> -1){
						if(grid[inputX][inputY]== grid[inputX+i][inputY]){
							grid[inputX+i][inputY] = ' ';
						}

						if(grid[inputX][inputY]== grid[inputX][inputY+j]){
							grid[inputX][inputY+j] = ' ';
						}

						if(grid[inputSwapX][inputSwapY]== grid[inputSwapX+i][inputSwapY]){
							grid[inputSwapX+i][inputSwapY] = ' ';
						}

						if(grid[inputSwapX][inputSwapY]== grid[inputSwapX][inputSwapY]+j){
							grid[inputSwapX][inputSwapY+j] = ' ';
						}
					}
				  }
				}
			}

		int count; 
		for(int i=0; i<h; i++){
			for(int j= 0; j<w; j++){
				if(grid[j][i] == ' '){
					count++;   
				}
			}	
		}
	
		if(count > 130){
				cout<< "YOU WON!" << endl; 
				playing = false; 
		}
	

		if(swapNumber > 10 && count < 130){
			cout<< "YOU LOSE wah wah wahhhhhhhh" << endl; 
				playing = false; 
			}

		}
	}
		// } else {
		// 	char temp = grid[inputX][inputY];
		// 	grid[inputX][inputY] = grid[inputSwapX][inputSwapY];
		// 	grid[inputSwapX][inputSwapY] = temp; 
		// }
			

			// make a win state
			//try different mechanics

			//add a loose state
		

		//ALL STUDENTS: 
			//add a win state
			//try other mechanics, for example: 
				//match only 1
				//try fewer types of tiles
				//try 16x16 instead of 8x8
		
		//ADVANCED STUDENTS: 
			//add a lose state
			//make remaining tiles fall down if there is empty space
		return 0; 
	}

	char getTile(int x, int y, unsigned char data[], int size, int w, int h){
		int r =0; 
		int g= 0; 
		int b = 0; 
		int i = 54 + (y* w + x) * 3; 

		int numBytesPerRow = w * 3; 
		int paddingValue = numBytesPerRow % 4; 

		if (paddingValue !=0){
			i += y * (4-paddingValue); 
		}

		b = writeBytes(i, data); 
		g = writeBytes(i+1, data); 
		r = writeBytes(i+2, data);

		if(r == 255 && g ==0 && b == 0){
			return 'O'; 
		} else if (r==0 && g==0 && b==255){
			return '*'; 
		} else if (r==0 && g==255 && b==0){
			return '#'; 
		} else{
			return ' '; 
		}
	}

	int writeBytes(int offset, unsigned char data[]) {
		return data[offset]; 
	}
