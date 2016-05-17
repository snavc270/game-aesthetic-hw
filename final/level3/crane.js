var crane;
var craneY = 400; 
var onACrane = false; 
var released = false; 
function craneSetup(){
  crane = createSprite(1100, 250); 
  crane.addAnimation("resting","assets/crane.png"); 
  
  cranePicker= createSprite(1250, 400); 
  cranePicker.addAnimation("blah", "assets/crane2.png");
  
}

function craneUpdate(){

  stroke(0); 
  strokeWeight(3); 
  line(1250, 50, 1250, craneY-50); 
    cranePicker.position.y = craneY; 
  
  // if (keyWentDown("UP_ARROW") || keyWentDown("w")){
  //     released = false; 
  //   }
    
  if(square.position.x > 1235 && square.position.x < 1265 && released===false){
    if (keyWentDown("DOWN_ARROW")){
    released = true; 
    }else { 
      square.position.y = craneY;
      square.velocity.y = 0; 
      square.position.x = 1250; 
    }
    
  
    if(craneY >= 100){
      craneY --; 
    }
  }
  
  if(immaSquare ===true){
   if(blob.position.x > 1235 && blob.position.x < 1265 && released===false){
    if (keyWentDown("s")){
    released = true; 
    onACrane = false; 
    }else { 
      blob.position.y = craneY;
      blob.velocity.y = 0; 
      blob.position.x = 1250; 
      onACrane = true; 
    }
    
  
    if(craneY >= 100){
      craneY --; 
    }
    }
  }
  if(released===true && craneY < 400){
    craneY++; 
  }
}