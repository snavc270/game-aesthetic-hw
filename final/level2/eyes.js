var eyeWhitesImg; 
var eyeWhites; 
var pupils; 
var pupilImg; 

function eyes(){
  eyeWhitesImg = loadImage("assets/eyes.png"); 
  eyeWhites = createSprite(1000, 150);
  eyeWhites.addImage(eyeWhitesImg); 
}

function pupils(){
  pupilImg = loadImage("assets/pupils.png"); 
  pupils = createSprite(1000, 150); 
  pupils.addImage(pupilImg); 
}

function pupilsMovement(){
  if(square.position.x > 590 && square.position.x < 780){
    if(pupils.position.x >= 980){
      pupils.position.x -= 0.5;  
    }
  }
  if (square.position.x > 780){
    if (pupils.position.x <=1020){
      pupils.position.x +=0.5
    }
  }
 
}


