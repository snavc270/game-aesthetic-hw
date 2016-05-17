var firstStairs; 
var clickNum = 0; 
 

function stairs(){
  firstStairs = createSprite(300, 400); 
  firstStairs.addAnimation("first", "assets/lev2stairs.png"); 
  firstStairs.addAnimation("second", "assets/lev2stairs2.png"); 
  firstStairs.addAnimation("third", "assets/lev2stairs3.png"); 
  firstStairs.addAnimation("fourth", "assets/lev2stair4.png");
  firstStairs.addAnimation("fifth", "assets/lev2stairs5.png");
  firstStairs.addAnimation("sixth", "assets/lev2stairs6.png");
}

function clickStairs(){
  if(firstStairs.overlap(mouseSprite)){
      if(mouseWentDown(LEFT)){
        clickNum += 1;
        click.play(); 
        click.setVolume(4); 
       }
      }
 
  if(clickNum ==1 ){
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
  if(clickNum >= 5){
    whenBlobsCollide = 0; 
    if(blob.collide(firstStairs)){
      blob.velocity.y = 0; 
      
    }
  }
  
}