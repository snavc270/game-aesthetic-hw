var openingScreen; 
var sound1; 

function preload(){
    sound1 = loadSound("assets/music2.wav"); 
    opener = loadAnimation("assets/openingScreen1.png","assets/openingScreen4.png");
}
function setup() {
  sound1.setVolume(1); 
  sound1.play(); 
  sound1.loop(); 
  createCanvas(1000, 600); 
  setFrameRate(5); 
}

function draw() {
    animation(opener, width*.5, height*.5); 
    
    if(keyWentDown("ENTER")){
      window.location= 'http://localhost:3000/'
    }
}
