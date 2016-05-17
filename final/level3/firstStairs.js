var firstStairs; 
var piece1; 
var piece2; 
var piece3; 
var piece4; 
var firstCollision = false; 
var secondCollision = false; 
var thirdCollision = false; 
var fourthCollision = false; 
var immaSquare= false; 
var built = false; 
var clickNum= 0; 

function stairsSetup(){
  firstStairs = createSprite(500, 300); 
  
  firstStairs.addAnimation("first", "assets/lev3stairs1.png"); 
  firstStairs.addAnimation("second", "assets/lev3stairs2.png"); 
  firstStairs.addAnimation("third", "assets/lev3stairs3.png"); 
  firstStairs.addAnimation("fourth", "assets/lev3stairs4.png");
  firstStairs.addAnimation("fifth", "assets/lev3stairs5.png");
  firstStairs.addAnimation("sixth", "assets/lev3stairs6.png");
  firstStairs.addAnimation("seventh", "assets/lev3stairs7.png");
  firstStairs.addAnimation("eighth", "assets/lev3stairs8.png");
  firstStairs.addAnimation("ninth", "assets/lev3stairs9.png");
}

function pieceSetup(){
  piece1= createSprite(500, 400); 
  piece2 = createSprite(400, 200); 
  piece3= createSprite(400, 300); 
  piece4= createSprite(600, 175); 
  
  piece1.addAnimation("one", "assets/piece1.png"); 
  piece2.addAnimation("two", "assets/piece2.png"); 
  piece3.addAnimation("three","assets/piece3.png"); 
  piece4.addAnimation("four", "assets/piece4.png"); 
  
  // piece1.setCollider("circle", 0, 0, 5); 
  // piece2.setCollider("circle", 0, 0, 5); 
  // piece3.setCollider("circle", 0, 0, 5); 
  // piece4.setCollider("circle", 0, 0, 5); 
}

function collectingPieces(){
   if(blob.overlap(piece1)){
      firstCollision= true; 
      piece1.visible = false; 
     }
     
  if(firstCollision=== true){
      blob.changeAnimation("firstPiece");
    }
    
  if(built === true){
    if(blob.overlap(piece2)){
      secondCollision = true; 
      piece2.visible = false; 
    }
    
    if(secondCollision=== true && firstCollision===true){
      blob.changeAnimation("secondPiece");
    }
    
     if(blob.overlap(piece3)){
      thirdCollision = true; 
      piece3.visible = false; 
    }
    
    if(thirdCollision=== true && secondCollision===true && firstCollision===true){
      blob.changeAnimation("thirdPiece");
    }
    if(blob.overlap(piece4)){
      fourthCollision = true; 
      piece4.visible = false; 
    }
    
    if(fourthCollision=== true && thirdCollision=== true && secondCollision===true && firstCollision===true){
      blob.changeAnimation("fourthPiece");
      immaSquare = true; 
      // println("i collided"); 
    }
  }     
}

function clickStairs(){
  if(firstStairs.overlap(mouseSprite)){
      if(mouseWentDown(LEFT)){
        clickNum += 1;
        click.play(); 
        click.setVolume(4); 
       }
      }
  // firstStairs.debug = true; 
  
  if(clickNum ==1){
    firstStairs.changeAnimation("second"); 
  }
  if(clickNum == 2){
    firstStairs.changeAnimation("third");  
  }
  
  if(clickNum == 3){
    firstStairs.changeAnimation("fourth"); 
  }
  
  if(clickNum == 4){
    firstStairs.changeAnimation("fifth"); 
  }
  if(clickNum == 5){
    firstStairs.changeAnimation("sixth"); 
  }
  
  if(clickNum == 6){
    firstStairs.changeAnimation("seventh"); 
  }
  
  if(clickNum == 7){
    firstStairs.changeAnimation("eighth"); 
  }
  
  if(clickNum == 8){
    firstStairs.changeAnimation("ninth"); 
  }
  
  if(clickNum >= 8){
    firstStairs.setCollider("rectangle", -75, 100, 100, 50); 
    firstStairs.setCollider("circle", 0, 0, 100); 
    // var secondCollide = createSprite(555, 275); 
    // secondCollide.setCollider("rectangle",0, 0, 100, 50); 
    // secondCollide.shapeColor = color(255, 255);
    // secondCollide.depth = 8; 
    // secondCollide.debug = true; 
    built = true;
    
    if(blob.collide(firstStairs)){
      if(keyDown("w")){
        blob.velocity.y = 10; 
       }else if(keyWentUp("w")){ 
         blob.velocity.y = 0; 
      }
    }
  
  }
}