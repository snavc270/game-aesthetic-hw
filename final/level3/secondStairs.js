var secondStairs; 
var clickNum2= 0; 

function secondStairsSetup(){
  secondStairs = createSprite(1300, 200); 
  secondStairs.addAnimation("first", "assets/secondStairs1.png"); 
  secondStairs.addAnimation("second", "assets/secondStairs2.png"); 
  secondStairs.addAnimation("third", "assets/secondStairs3.png"); 
}

function secondStairsClick(){
  if(secondStairs.overlap(mouseSprite)){
      if(mouseWentDown(LEFT)){
        clickNum2 += 1;
        click.play(); 
        click.setVolume(4); 
       }
      }
 
  if(clickNum2=== 1 ){
    secondStairs.changeAnimation("second"); 
  }
  if(clickNum2 === 2){
    secondStairs.changeAnimation("third");  
  }
  if(clickNum2 >=2){
    secondStairs.setCollider("rectangle", 0, 0, 200, 50); 
    // secondStairs.debug = true; 
    if(blob.collide(secondStairs)){
      blob.velocity.y = 0; 
  }
    if(square.collide(secondStairs)){
      square.velocity.y = 0; 
    }
  }
  
}