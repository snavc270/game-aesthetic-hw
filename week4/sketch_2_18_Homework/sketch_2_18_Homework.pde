  
  PFont font; 
  String grid [][]; 
  int player [][]; 
  int obstacle[][];
  int walls[][]; 
  int people[][]; 
  
  int r=30; 
  int c=30; 
  int x; 
  int y; 
  int xVel = 1; 
  int yVel = 1; 
  int state= 0; 
  int  xPos; 
  int  yPos; 
  
  int count; 
  int health = 20; 
  int op; 
  
  boolean playerMoving; 
  boolean obstacleMoving; 
  
  
  void setup() {
    size(500, 500); 
    font = createFont("AmericanTypewriter-Bold-48.vlw", 14); 
    textFont(font); 
    background(255); 
  
    grid = new String[r][c]; 
    player= new int[r][c]; 
    obstacle= new int[r][c]; 
    walls= new int[r][c]; 
    people= new int[r][c]; 
    
    xPos=15; 
    yPos= 5; 
    
    x= 0; 
    y= 10; 
  
    op=200; 
  
  
    for (int i = 0; i< c; i++) {
      for (int j= 0; j< r; j++) {
        grid[i][j] = "+"; 
        player[i][j]= 0;   
        obstacle[i][j]= 0; 
        walls[i][j]=0;
        people[i][j]=0; 
      }
    }
  }
  
  void draw() {
    
    
    background(0);  
    
    player[x][y]= 1; 
    obstacle[xPos][yPos]=1; 
    
    people[5][20]=1; 
    people[10][10]= 1; 
    people[3][4]=1; 
    
    healthy(); 
    
    if(health==0){
        state=20; 
    }
    
    if(state==20){
        youDead(); 
    }

    for (int i=0; i<r; i++) {
      for (int j= 0; j<c; j++) {
        if(j <10 || j >15){
    
        walls[i][1] =1; 
        walls[0][j]=1; 
        walls[29][j]=1; 
        walls[i][29]=1;
        }
      }
    }
  
  
    for (int i= 0; i< c; i++) {
      for (int j= 0; j<r; j++) {
  
  
        if (player[i][j]==0 && obstacle[i][j]==0 && walls[i][j]==0 && people[i][j]==0) {
          fill(0, 255, 255, op); 
          rect(i*10, j*10-10, 10, 10); 
          fill(0); 
          text(grid[i][j], i*10, j*10);
        } else if (player[i][j] == 1) {
          fill(128, 255, 0, 255); 
          rect(i*10, j*10-10, 10, 10); 
          fill(0); 
          text("@", i*10, j*10);
        } else if (obstacle[i][j] ==1) {
          fill(255, 0, 0, op); 
          rect(i*10, j*10-10, 10, 10); 
          fill(0); 
          text("*", i*10, j*10);
        } else if (walls[i][j]==1) {
          fill(0, 51, 102, op);  
          rect(i*10, j*10-10, 10, 10); 
          fill(0); 
          text("#", i*10, j*10);
        } else if (people[i][j]==1){
          fill(127, 0, 255, 255); 
          rect(i*10, j*10-10, 10, 10); 
          fill(0); 
          text("@", i*10, j*10); 
        }
      }
    }
    
    
      
    if (x==r) {
      x=0;
      player[x][y]=0;
    }
  
    if (y==c) {
      y=0; 
      player[x][y]=0;
    }
 
  
    if (x==15 && y ==5) {
      fill(255); 
      text("WATCH OUT FOR THE SOURCE OF THE FLAMES", width*.01, height*.65);
    }
    
    if (x==5 && y== 20){
        scenario1(); 
    }
    
    if (x==10 && y==10){
        scenario2(); 
    }
    
    if (x==3 && y==4){
        scenario3(); 
    }
  
  if(millis()% 30 == 0){
    obstacleMove();
  }
  
    
  
  
  
    println(x); 
    println(y); 
    
  }
  
  void obstacleMove() {
    
  
    int ran = int(random(4)); 
    
    
    if (ran ==0 && xPos <28) {
      xPos += xVel; 
      obstacle[xPos][yPos]=0;
    } else if (ran ==1 && xPos >1) {
      xPos -= xVel; 
      obstacle[xPos][yPos]=0;
    } else if (ran ==2 && yPos<28) {
      yPos += yVel; 
      obstacle[xPos][yPos]=0;
    } else if (ran==3 && yPos>2){
      yPos -= yVel;
      obstacle[xPos][yPos]=0;
    }
  
  
  }
  void healthy(){
      if(x== xPos && y== yPos && health>-0){
        if(millis()%5 == 0){
        health--; 
        }
    }
    
    fill(255); 
    text("health:", width*.75, height*.1); 
    text(health, width*.85, height*.1);
  }
  
  
  void keyPressed(){  
    if (key == CODED) {
      if (keyCode == UP && y> 2) {
        player[x][y]= 0;
        y-= yVel;
      }
      if (keyCode == DOWN && y <28) {
        player[x][y]=0; 
        y+= yVel;
      }
      if (keyCode ==LEFT && x >0) {
        player[x][y]=0; 
        x -= xVel;
      }
      if (keyCode == RIGHT){
        if(x< 29 && y<16 && y>9) {
        player[x][y]=0; 
        x+= xVel;
        } else if( x<28){
         player[x][y]=0; 
         x+= xVel;         
        } else if (x == 29){
           x = 0; 
           //erases player at exit 
           player[29][y] = 0; 
           op -=18; 
           state ++; 
        }
      }
    }
  }
    
    void youDead(){
        xVel = 0; 
        yVel = 0; 
        
        text("You Died.", width*.1, height*.8); 
    }
    
    void scenario1(){
        if(state==0){
          fill(255); 
          text("'Hi! How are you?'", width*.01, height*.65);
        } else if(state==1){
          fill(255); 
          text("'Hi. How are you?'", width*.01, height*.65); 
        } else if(state==2){
          fill(255); 
          text("'Hi.'", width *.01, height*.65); 
        } else if(state==3){
          fill(255); 
          text("Maybe they did't want to talk to me", width*.01, height*.65); 
        } else if(state==4){
          fill(255); 
          text("I don't think they wanted to talk to me", width*.01, height*.65); 
        } else if(state==5){
          fill(255); 
          text("I had nothing to contribute to the conversation", width*.01, height*.65); 
        } else if(state==6){
          fill(255); 
          text("What did they mean by 'how are you'?", width*.01, height*.65); 
        } else if(state==7){
          fill(255); 
          text("Do I look like I'm not okay?", width*.01, height*.65); 
        } else if(state==8){
          fill(255); 
          text("They probably thought I looked terrible", width*.01, height*.65); 
        } else if(state==9){
          fill(255); 
          text("I shouldn't have approached them", width*.01, height*.65);  
        } else if(state==10){
          fill(255); 
          text("Why can't I stop thinking about this?", width*.01, height*.65);
        }
    }
    
    
    void scenario2(){
        if(state==0){
          fill(255); 
          text("I need to call my bank today", width*.01, height*.65);
        } else if(state==1){
          fill(255); 
          text("I hate talking to strangers on the phone", width*.01, height*.65); 
        } else if(state==2){
          fill(255); 
          text("I am really dreading this", width *.01, height*.65); 
        } else if(state==3){
          fill(255); 
          text("I am clearly ruining the phone operators day", width*.01, height*.65); 
        } else if(state==4){
          fill(255); 
          text("They don't want to deal with me", width*.01, height*.65); 
        } else if(state==5){
          fill(255); 
          text("I don't even want to deal with me", width*.01, height*.65); 
        } else if(state==6){
          fill(255); 
          text("What if there is an awkard silence", width*.01, height*.65); 
        } else if(state==7){
          fill(255); 
          text("Their business hours aren't over yet", width*.01, height*.65); 
        } else if(state==8){
          fill(255); 
          text("Okay, one more hour to call", width*.01, height*.65); 
        } else if(state==9){
          fill(255); 
          text("Still 30 minutes to call ", width*.01, height*.65);  
        } else if(state==10){
          fill(255); 
          text("I'll just do it tomorrow", width*.01, height*.65);
        }
    }
    
    void scenario3(){
        if(state==0){
          fill(255); 
          text("'Hey, I'm having a party tonight. You should come!'", width*.01, height*.65);
        } else if(state==1){
          fill(255); 
          text("'Sure, okay'", width*.01, height*.65); 
        } else if(state==2){
          fill(255); 
          text("I guess I'm not doing anything tonight", width *.01, height*.65); 
        } else if(state==3){
          fill(255); 
          text("It might be good to be social", width*.01, height*.65); 
        } else if(state==4){
          fill(255); 
          text("What if they only invited me just to be nice?", width*.01, height*.65); 
        } else if(state==5){
          fill(255); 
          text("I wonder how many people will be there", width*.01, height*.65); 
        } else if(state==6){
          fill(255); 
          text("I'm probably not going to know anyone", width*.01, height*.65); 
        } else if(state==7){
          fill(255); 
          text("And I'm going to have to make uncomfortable small talk", width*.01, height*.65); 
        } else if(state==8){
          fill(255); 
          text("Meeting new people is so exhausting", width*.01, height*.65); 
        } else if(state==9){
          fill(255); 
          text("I've already had such a long day", width*.01, height*.65);  
        } else if(state==10){
          fill(255); 
          text("I'm just going to stay at home", width*.01, height*.65);
        }
    }    
    
    
  

