var secondStairs; 
var clickNum2 =0; 

function secondStairs(){
  secondStairs = createSprite(1000, 400); 
  secondStairs.setCollider("rectangle", 0, 0, 75); 
  secondStairs.addAnimation("first", "assets/secStairs.png"); 
  secondStairs.addAnimation("second", "assets/secStairs1.png"); 
  secondStairs.addAnimation("third", "assets/secStairs2.png"); 
  secondStairs.addAnimation("fourth", "assets/secStairs3.png"); 
  secondStairs.addAnimation("fifth", "assets/secStairs4.png"); 
  secondStairs.addAnimation("sixth", "assets/secStairs5.png"); 
  secondStairs.addAnimation("seventh", "assets/secStairs6.png");
  secondStairs.addAnimation("eighth", "assets/secStairs7.png"); 
  secondStairs.addAnimation("nine", "assets/secStairs8.png"); 
  secondStairs.addAnimation("ten", "assets/secStairs9.png"); 
  secondStairs.addAnimation("eleven", "assets/secStairs10.png"); 
  secondStairs.addAnimation("twelve", "assets/secStairs11.png"); 
  secondStairs.addAnimation("thirteen", "assets/secStairs12.png"); 
  secondStairs.addAnimation("fourteen", "assets/secStairs13.png"); 
}

function clickStairsTwo(){
   if(secondStairs.overlap(mouseSprite)){
      if(mouseWentDown(LEFT)){
        clickNum2 += 1;
        click.play(); 
        click.setVolume(4); 
       }
      }
 
  

  if(clickNum2 ===1){
    secondStairs.changeAnimation("second"); 
  }
  if(clickNum2 ===2){
    secondStairs.changeAnimation("third");  
  }
  
  if(clickNum2 === 3){
    secondStairs.changeAnimation("fourth"); 
  }
  
  if(clickNum2 == 4){
    secondStairs.changeAnimation("fifth"); 
  }
  if(clickNum2 == 5){
    secondStairs.changeAnimation("sixth"); 
  }
  
  if(clickNum2 == 6){
    secondStairs.changeAnimation("seventh"); 
  }
  if(clickNum2 == 7){
    secondStairs.changeAnimation("eighth"); 
  }
  
  if(clickNum2 == 8){
    secondStairs.changeAnimation("nine"); 
  }
  if(clickNum2 == 9){
    secondStairs.changeAnimation("ten"); 
  }
  
  if(clickNum2 == 10){
    secondStairs.changeAnimation("eleven"); 
  }
  if(clickNum2 == 11){
    secondStairs.changeAnimation("twelve"); 
  }
  
  if(clickNum2 == 12){
    secondStairs.changeAnimation("thirteen"); 
  }
  if(clickNum2 == 13){
    secondStairs.changeAnimation("fourteen"); 
  }
  if(clickNum2 >=13){
    // whenBlobsCollide = 0; 
    secondStairs.debug = true; 

    // // var stair2 = createSprite(1000, 200, 100, 40); 
    // stair2.shapeColor = color(255, 0); 
    // stair2.debug = true; 
    
    // secondStairs.setCollider("rectangle", 0, -50, 200, 40); 
    secondStairs.setCollider("rectangle", 55, -63, 200, 100); 
    if(blob.collide(secondStairs)){
      blob.velocity.y = 0; 
      println(blob.position.y); 
     }
  }
  
}