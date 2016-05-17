var sound1; 
var groundImg; 
var gravity = .98; 
var state = 0; 
var moveToLev3 = false; 
var blob; 
var tileDist; 
var tileHeight;
var tileSize= 50; 
var openBlob = false;
var square; 
var squareDoor; 
var squareDoorImg; 
var squareDoor2; 
var squareDoor2Img; 

var blobDoor; 
var blobDoorImg; 
var blobDoor2; 
var blobDoor2Img; 

var whenBlobsCollide; 

var blobStartX = 150; 
var blobStartY = 150; 
var squareStartX = 100; 
var squareStartY = 400; 

var blobby_spriteSheet; 
var square_spriteSheet; 
var walk2_animation; 
var walk_animation; 

var ground;
var blueTile; 
var blueTileImg; 

var backgr; 
var bg; 
var shelf; 
var myFont; 
var mouseClicks= 0; 
var eyesRefocus = false; 
var mouseSprite; 
var xOffset; 

var effect1, effect2, effect3, effect4, click; 

function preload(){
      sound1 = loadSound("assets/music3.wav"); 
     myFont = loadFont("assets/Typo GeoSlab Thin Demo.otf"); 
  
  effect1 = loadSound("assets/soundeffect1.wav");
  effect2 = loadSound("assets/soundeffect2.wav");
  effect3 = loadSound("assets/soundeffect3.wav");
  effect4 = loadSound("assets/soundeffect4.mp3");
  click = loadSound("assets/click.wav");
}

function setup() {
  
  sound1.setVolume(1); 
  sound1.play(); 
  sound1.loop(); 
   textFont(myFont); 
  textSize(28); 
  createCanvas(1000, 600); 
  tileDist = 200; 
  tileHeight = 300;
  whenBlobsCollide = 50; 
  
  groundImg = loadImage("assets/ground2.png", 2000, 110); 
  bg = loadImage("assets/background2.png", 2000, height); 
  
  backgr = createSprite(500, 250); 
  backgr.addImage(bg); 
  
  ground = createSprite(600, 545); 
  ground.addImage(groundImg); 
  
  squareDoorImg = loadImage("assets/squareDoor.png"); 
  
  squareDoor = createSprite(100, 445); 
  squareDoor.addImage(squareDoorImg); 
  squareDoor.setCollider("circle", 0, 0, 50);
  
  blobDoorImg = loadImage("assets/blobDoor.png"); 
  blobDoor = createSprite(150, 150); 
  blobDoor.addImage(blobDoorImg); 
  
  blobDoor2Img = loadImage("assets/blobDoor2.png")
  blobDoor2 = createSprite(600, 425); 
  blobDoor2.addAnimation("closed", blobDoor2Img); 
  blobDoor2.addAnimation("open", blobDoorImg); 
  blobDoor2.setCollider("circle", 0, 0, 50); 
  
  squareDoor2Img = loadImage("assets/squareDoor2.png")
  squareDoor2 = createSprite(1400, 425); 
  squareDoor2.addAnimation("closed", squareDoor2Img); 
  squareDoor2.addAnimation("open", squareDoorImg); 
  squareDoor2.setCollider("circle", 0, 0, 50); 
  
  shelf = createSprite(150, 250); 
  shelfImg = loadImage("assets/shelf.png"); 
  shelf.addImage(shelfImg); 
  shelf.setCollider("rectangle", 0, 0, 50); 
  stairs(); 
  secondStairs(); 
      
  mouseSprite = createSprite(0,0, 50, 50); 
  
  eyes(); 
  pupils();
  

  playerSetup();   
  // blueTileImg = loadAnimation("regular", "assets/blueSquare.png"); 
  // blueTileTopImg = loadAnimation("folded", "assets/topBlueSquare.png");
  
}

function draw() {
 
  xOffset = camera.position.x - 500; 
  mouseSprite.position.x = mouseX + xOffset; 
  mouseSprite.position.y = mouseY; 
  mouseSprite.shapeColor = color(255, 255);  
  
  if(state==0 ){
    openingScreen(); 
  } 
  
  if(state== 0 && keyWentDown("ENTER")){
    state = 1; 
 }
 
  if(state===1){
  clickStairsTwo(); 
  
  clickStairs();
  moveCamera();
  clear(); 
  drawSprites(); 

  blobMovement(); 
  squareMovement(); 
  
 
  pupilsMovement(); 
  blobFall(); 
  squareExit();
  blobExit(); 
  blobDoor.depth = 1; 
  blobDoor2.depth = 2; 
  }
  if(moveToLev3 === true){
    window.location = 'http://localhost:3003/' ; 
  }
}

function blobFall(){
  if((blob.position.y - blob.previousPosition.y) > 20){
    blob.position.x = blobStartX; 
    blob.position.y = blobStartY; 
  }
}

function squareExit(){
  var open = false; 
  if(square.position.x >=1280){
    squareDoor2.changeAnimation("open"); 
    open = true; 
  }
  if(open ==true){
    if(keyWentDown("UP_ARROW")){
      square.remove(); 
      eyesRefocus= true; 
    }
    
    if(eyesRefocus ===true){
      pupils.position.x = 1000; 
    }
  }
}

function blobExit(){
  if(eyesRefocus === true && blob.position.y ===237){
    blobDoor2.changeAnimation("open"); 
    openBlob = true; 
    
  }

  if(keyWentDown("w")){
    if(openBlob === true){
    blob.collide(blobDoor2, blobExit1); 
 
 
  }
  }
  // if(blob.collide(blobDoor2)){
  // if(openBlob == true){
  //   if(keyWentDown("w")){
  //     blob.remove(); 
  //   }
  // }
  // }
}


function blobExit1(){
   moveToLev3 = true; 
   blob.visible = false; 
}



function moveCamera(){
  if(blob.position.x > window.innerWidth*.5){
    if(camera.position.x < 1000){
      camera.position.x += ((abs(blob.position.x - camera.position.x)+ abs(square.position.x - camera.position.x))*.5)*0.01; 
    }
    }else if(blob.position.x < camera.position.x- 200){
      if(camera.position.x >500){
      camera.position.x -= ((abs(blob.position.x - camera.position.x)+ abs(square.position.x - camera.position.x))*.5)*0.01; 
    }
    }else{
      camera.position.x += 0; 
    }
  
  // if(square.position.x > window.innerWidth*.5){
  //   if(camera.position.x < 1000){
  //     camera.position.x += ((abs(blob.position.x - camera.position.x)+ abs(square.position.x - camera.position.x))*.5)*0.1; 
  //   }
  //   }else if(square.position.x < camera.position.x- 200){
  //     if(camera.position.x >500){
  //     camera.position.x -= ((abs(blob.position.x - camera.position.x)+ abs(square.position.x - camera.position.x))*.5)*0.1; 
  //   }
  //   }else{
  //     camera.position.x += 0; 
  //   }
}

function openingScreen(){
  background(0); 
  fill(255); 
  text("'I was addressing my questions to the square'", width*.2, height*.5); 
  // image(opener, -50, 0); 
  // animation(opener, width*.5, height*.5); 

}