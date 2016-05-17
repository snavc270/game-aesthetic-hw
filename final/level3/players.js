
var blobStartX = 100; 
var blobStartY = 445; 
var squareStartX = 200; 
var squareStartY = 445; 
var firstPiece; 
var secondPiece; 
var thirdPiece; 
var fourthPiece; 

function playerSetup(){
  blobby_spriteSheet = loadSpriteSheet('assets/spritesheet.png', 93,119, 5);
  blobby_spriteSheet = loadSpriteSheet('assets/spritesheet.png', 93,119, 5); 
  blobby_spriteSheet1 = loadSpriteSheet('assets/piece1spriteSheet.png', 93,119, 5);
  blobby_spriteSheet2 = loadSpriteSheet('assets/piece2spriteSheet.png', 93,119, 5);
  blobby_spriteSheet3 = loadSpriteSheet('assets/piece3spriteSheet.png', 93,119, 5);
  blobby_spriteSheet4 = loadSpriteSheet('assets/piece4spriteSheet.png', 93,119, 5);
  square_spriteSheet = loadSpriteSheet('assets/spritesheet2.png', 110.133, 112.19, 4); 
  
  walk2_animation = loadAnimation(square_spriteSheet); 
  
  firstPiece = loadSpriteSheet(blobby_spriteSheet1); 
  secondPiece = loadSpriteSheet(blobby_spriteSheet2);
  thirdPiece = loadSpriteSheet(blobby_spriteSheet3);
  fourthPiece = loadSpriteSheet(blobby_spriteSheet4); 
  
  
  walk_animation = loadAnimation(blobby_spriteSheet); 
  
  
  blob = createSprite(blobStartX , blobStartY); 
  blob.setCollider("circle", 0, 0, 50); 
  blob.addAnimation("resting", "assets/blob.png"); 
  blob.addAnimation("walking", blobby_spriteSheet); 
    blob.addAnimation("firstPiece", blobby_spriteSheet1); 
  blob.addAnimation("secondPiece", blobby_spriteSheet2);
  blob.addAnimation("thirdPiece", blobby_spriteSheet3); 
  blob.addAnimation("fourthPiece", blobby_spriteSheet4);
  
  square = createSprite(squareStartX, squareStartY); 
  square.setCollider("rectangle", 0, 0, 50, 50); 
  square.addAnimation("resting", "assets/square.png");
  square.addAnimation("walking", square_spriteSheet);
}

function blobMovement(){
  blob.velocity.y += gravity; 
  var touchingGround = false; 
  var touchingSolid = false; 
  // blob.debug = true; 
  
    if(touchingSolid===false){
      touchingSolid = false; 
    }
  
  if(blob.collide(ground)){
    touchingGround = true; 
    blob.velocity.y = 0; 
  }

    
    blob.changeAnimation("walking");
  
  
  if(keyDown("d")){

    if(blob.position.x < 1300){
    blob.velocity.x = 10; 
    blob.changeAnimation("walking"); 
    }
  } else if(keyDown("a")){
    
    if(blob.position.x > 100){
    blob.velocity.x = -10; 
    blob.changeAnimation("walking"); 
  }
   }else if(keyWentDown("w") && touchingGround ===true){
    effect3.play(); 
    effect3.setVolume(1); 
    blob.velocity.y = -25; 
    blob.changeAnimation("walking");
    touchingGround = false; 
  }else{
    blob.velocity.x = 0;
    blob.changeAnimation("resting"); 
  }
}

function squareMovement(){
  var touchingGround = false; 
  square.velocity.y += gravity; 
  
  if(square.collide(ground)){
    square.velocity.y = 0; 
    touchingGround = true; 
  }
  if(keyDown("RIGHT_ARROW")){
    if(square.position.x <1300){
    square.velocity.x = 10; 
    square.changeAnimation("walking"); 
    square.mirrorX(1); 
  }
  }else if(keyDown("LEFT_ARROW")){
    if(square.position.x >100){
    square.velocity.x = -10; 
    square.changeAnimation("walking"); 
    square.mirrorX(-1); 
  }}else if(keyWentDown("UP_ARROW") && touchingGround === true){
    effect1.play(); 
    effect1.setVolume(.5); 
    square.velocity.y = -10; 
    touchingGround = false; 
  }else{
    square.velocity.x = 0;
    square.changeAnimation("resting"); 
  }
}