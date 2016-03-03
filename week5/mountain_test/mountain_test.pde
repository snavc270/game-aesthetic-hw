//try fixing this code to ensure we never get an array index out of bounds exception

color[][] map;
int SIZE = 50;
int cellSize = 13;

int cLength = SIZE-2;     //how long the cave should be (in tiles)
int cRoughness = 90;  //how much the cave varies in width
int cWindyness = 10;  //how much the cave varies in positioning

int x, y;
int stepWidth;
int step;
int totalRuns;

void setup() {
  size(640, 640);
  noSmooth();
  textAlign(BOTTOM, LEFT);
  background(0);
  map = new color[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) { 
      map[j][i]= color(0); 
      fill(map[j][i]); 
    }
  }

  x = SIZE-2;
  y = floor(SIZE*.8)+ floor(random(-5, 5));
  map[x][y] = color(0);

  stepWidth = floor(random(3, SIZE/4));
  float increment = 0.09; 
  float xoff = 0.0; 
  for(int j = 0; j <width/cellSize; j++){
      xoff += increment; 
      float yoff= 0.0; 
      for(int i = 0; i < height/cellSize; i++){
        yoff += increment; 
        float noiseVal = noise( xoff, yoff); 
        
        if(noiseVal <1){
          color fillColor = color(map(noiseVal, 0, 1, 0, 153), map(noiseVal, 0, 1, 76, 229),
                            map(noiseVal, 0, 1, 153, 255)); 
                    map[j][i] = fillColor;         
        }
      }
  }
  for (int i = -stepWidth/2; i < stepWidth/2; i++) {
      fill(map[x][y+i]); 
    
  }
}

void draw() {
  background(0);
  step();
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      fill(map[j][i]); 
      noStroke(); 
      rect(j*cellSize, i*cellSize, cellSize, cellSize); 
    }
  }
  if (step == cLength && totalRuns < 2) {
    totalRuns++;
    step = 0;
    x = SIZE-2;
    y = floor(SIZE*.8);
  }
}

void step() {
  if (step < cLength) {
    x--;
    if (random(100) <= cRoughness) {
      int r = 0;
      while (r == 0) {
        r = floor(random(-2, 3));
      }
      stepWidth += r;
      if (stepWidth < 3) {
        stepWidth = 3;
      } else if (stepWidth > SIZE) {
        stepWidth = SIZE;
      }
    }

    if (random(100) <= cWindyness) {
      int r = 0;
      while (r == 0) {
        r = floor(random(-2, 3));
      }
      y += r;
      if (y < 0) {
        y = 0;
      }
      if (y > SIZE-3) {
        y = SIZE-3;
      }
    }

    for (int i = -stepWidth/2; i < stepWidth/2; i++) {
      map[x][y+i] = color(87, 19, 28); 
    }
    step++;
  }
}


//one thing we haven't been doing is allowing for multiple regenerations.
//we're doing this by resetting some stuff in a function that we'll call on keyReleased.
//ordinarily we'd want to generate everything in a while loop, but since we're doing it sequentially here this works too.
void reset() {
  
  float increment = 0.09; 
  float xoff = 0.0; 
  for(int j = 0; j <width/cellSize; j++){
      xoff += increment; 
      float yoff= 0.0; 
      for(int i = 0; i < height/cellSize; i++){
        yoff += increment; 
        float noiseVal = noise( xoff, yoff); 
        
        if(noiseVal <1){
          color fillColor = color(map(noiseVal, 0, 1, 0, 153), map(noiseVal, 0, 1, 76, 229),
                            map(noiseVal, 0, 1, 153, 255)); 
                    map[j][i] = fillColor;         
        }
      }
    }
    
  

  x = SIZE-2;
  y = floor(SIZE*.8) + floor(random(-5, 5));
  
//  map[x][y+i] = color(0) ;
  totalRuns = 0;
  step = 0;
  
  stepWidth = floor(random(3, SIZE/4));
//  for (int i = -stepWidth/2; i < stepWidth/2; i++) {
//    map[x][y+i] = color(0);
//  }
}

void keyReleased() {
  reset();
}
