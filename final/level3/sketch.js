var groundImg;
var gravity = .98;

var sound1;
var blob;

var isJumping = false;

var square;
var squareDoor;
var squareDoorImg;
var squareDoor2;
var squareDoor2Img;

var blobDoor;
var blobDoorImg;

var blobExit = false;
var squareExit = false;

var whenBlobsCollide;

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

var state = 0;

var click;
var mouseSprite;
var xOffset;

function preload() {
  sound1 = loadSound("assets/music.wav");
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
  whenBlobsCollide = 50;

  groundImg = loadImage("assets/lev3ground.png", 2000, 110);
  bg = loadImage("assets/lev3Background.png", 2000, height);

  backgr = createSprite(500, 250);
  backgr.addImage(bg);

  ground = createSprite(600, 545);
  ground.addImage(groundImg);



  squareDoorImg = loadImage("assets/squareDoor.png");

  squareDoor = createSprite(200, 445);
  squareDoor.addImage(squareDoorImg);
  squareDoor.setCollider("circle", 0, 0, 50);

  blobDoorImg = loadImage("assets/blobDoor.png");
  blobDoor = createSprite(100, 445);
  blobDoor.addImage(blobDoorImg);

  squareDoor2Img = loadImage("assets/squareDoor2.png")
  squareDoor2 = createSprite(1350, 100);
  squareDoor2.addAnimation("open", squareDoorImg);
  squareDoor2.setCollider("circle", 0, 0, 50);

  stairsSetup();
  secondStairsSetup();
  pieceSetup();
  craneSetup();
  mouseSprite = createSprite(0, 0, 50, 50);
  playerSetup();
}

function draw() {
  xOffset = camera.position.x - 500;
  mouseSprite.position.x = mouseX + xOffset;
  mouseSprite.position.y = mouseY;
  mouseSprite.shapeColor = color(255, 0);


  if (state === 0) {
    openingScreen();
  }
  if (state === 0 && keyWentDown("ENTER")) {
    state = 1;
  }

  if (state === 1) {
    moveCamera();
    clear();
    drawSprites();

    blobMovement();
    squareMovement();
    clickStairs();
    secondStairsClick();
    collectingPieces();
    craneUpdate();

    blobFall();
    // squareExit();
    blobDoor.depth = 1;

    if (keyWentDown("UP_ARROW")) {
      if(square.collide(squareDoor2)){
        squareExit1();  
      }
    }
    if (keyWentDown("w")) {
      if (immaSquare === true) {
        if(blob.collide(squareDoor2)){
          blobExit1(); 
        }
    
      }
    }
  }

  if (blobExit === true) {
    if(squareExit ===true){
    state = 2;
  }
  }
  if (state === 2) {
    endScreen();
  }

  println(state);
  println(blobExit); 
  println(squareExit); 
}

function blobFall() {
  if ((blob.position.y - blob.previousPosition.y) > 30 && onACrane === false) {
    blob.position.x = blobStartX;
    blob.position.y = blobStartY;

    firstCollision = false;
  }
}

// function squareExit(){
//   var open = false; 
//   if(square.position.x >=1280){
//     squareDoor2.changeAnimation("open"); 
//     open = true; 
//   }
//   if(open ==true){
//     if(keyWentDown("UP_ARROW")){
//       square.remove(); 
//     }
//   }
// }




function moveCamera() {
  if (blob.position.x > window.innerWidth * .7) {
    if (camera.position.x < 1000) {
      camera.position.x += ((abs(blob.position.x - camera.position.x) + abs(square.position.x - camera.position.x)) * .5) * 0.01;
    }
  } else if (blob.position.x < camera.position.x - 200) {
    if (camera.position.x > 500) {
      camera.position.x -= ((abs(blob.position.x - camera.position.x) + abs(square.position.x - camera.position.x)) * .5) * 0.01;
    }
  } else {
    camera.position.x += 0;
  }
}

function squareExit1() {
  square.visible = false;
  squareExit = true; 
  released = false;
  // spriteA.remove(); 
}

function blobExit1() {

  blob.visible = false;
  blobExit = true;
  released = false;
}

function openingScreen() {
  background(0);
  fill(255);
  text("'Don't be so emotional'", width * .35, height * .5);
}

function endScreen() {
  background(0);
  fill(255); 
  camera.position.x = 500; 
  text("'I didn't think Drops were capable of that'", width * .23, height * .5); 
}