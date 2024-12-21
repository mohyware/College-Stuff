// frame 1
basketIMAGE.visible = false
// frame 25
stop();

startGameBtn.addEventListener(MouseEvent.CLICK, handleClick);
var gameStart:Sound = new game_start();

function handleClick(event:MouseEvent):void {
    trace("Button clicked!");
	gameStart.play();
	play();
}

// frame 26
stop();

// Move the basket with the keyboard
var speedBasket:int = 30; // Speed at which the basket moves

// Listen for keyboard inputs to move the basket left or right
stage.addEventListener(KeyboardEvent.KEY_DOWN, moveBasket);
basketIMAGE.visible = true

function moveBasket(event:KeyboardEvent):void {
    if (event.keyCode == Keyboard.LEFT && basketIMAGE.x > -20) {
        basketIMAGE.x -= speedBasket; // Move basket left
    } else if (event.keyCode == Keyboard.RIGHT && basketIMAGE.x < stage.stageWidth - basketIMAGE.width) {
        basketIMAGE.x += speedBasket; // Move basket right
    }
}

import flash.events.*;
import flash.utils.Timer;
import flash.utils.getDefinitionByName;
import flash.utils.setTimeout;

// Timer for controlling object creation
var nextObject:Timer;
var objects:Array = [];
var speed:Number = 7.0; // Initial speed of objects falling
var score:int = 0; // Starting score
var level:int = 1; // Starting level
var scoreThreshold:int = 5; // Points required to increase the level

// 1- Create TextField for score
var scoreTextField:TextField = new TextField();
scoreTextField.textColor = 0xFFFFFF;
scoreTextField.x = stage.stageWidth - 150;
scoreTextField.y = 10;
// Set the text format for the score display
var scoreFormat:TextFormat = new TextFormat();
scoreFormat.size = 25;
scoreTextField.defaultTextFormat = scoreFormat;
// Add the score display to the stage
addChild(scoreTextField);

// 2- Create TextField for level
var levelTextField:TextField = new TextField();
levelTextField.textColor = 0xFFFFFF;
levelTextField.x = 10;
levelTextField.y = 10;
// Set the text format for the level display
var levelFormat:TextFormat = new TextFormat();
levelFormat.size = 25;
levelTextField.defaultTextFormat = levelFormat;
// Add the level display to the stage
addChild(levelTextField);

// 3- Create TextField for messages
var messageTextField:TextField = new TextField();
messageTextField.x = (stage.stageWidth - messageTextField.textWidth) / 2;
messageTextField.y = (stage.stageHeight - messageTextField.textHeight) / 2;
// Set the text format for the message display
var msgFormat:TextFormat = new TextFormat();
msgFormat.size = 35;
messageTextField.defaultTextFormat = msgFormat;
// Add the message display to the stage
addChild(messageTextField);

// Initialize the game
initGame();

function initGame():void {
    trace("init game");
    setNextObject();
    addEventListener(Event.ENTER_FRAME, moveObjects);
}

function setNextObject():void {
    if (score >= 0) {
        nextObject = new Timer(1000 + Math.random() * 1000, 1);
        nextObject.addEventListener(TimerEvent.TIMER_COMPLETE, newObject);
        nextObject.start();
    }
}

function newObject(e:TimerEvent):void {
    var goodObjects:Array = ["good1", "good2"];
    var badObjects:Array = ["bad1", "bad2"];
    var newObject:MovieClip;
    var classRef:Class;

    if (Math.random() < 0.5) {
        var r:int = Math.floor(Math.random() * goodObjects.length);
        classRef = getDefinitionByName(goodObjects[r]) as Class;
        newObject = new classRef();
        newObject.typestr = "good";
    } else {
        r = Math.floor(Math.random() * badObjects.length);
        classRef = getDefinitionByName(badObjects[r]) as Class;
        newObject = new classRef();
        newObject.typestr = "bad";
    }

    newObject.x = Math.random() * (stage.stageWidth - 200);
    newObject.y = 0;
    addChild(newObject);
    objects.push(newObject);
    if(score >= 0){
        setNextObject();
    }
}

var fruitFail:Sound = new fruit_fail();

function moveObjects(e:Event):void {
    for (var i:int = objects.length - 1; i >= 0; i--) {
        var obj:MovieClip = objects[i];
        obj.y += speed;

        // Check if object collides with basket
        if (obj.hitTestObject(basketIMAGE)) {
            updateScore(obj.typestr);
            removeChild(obj);
            objects.splice(i, 1);
        }

        // Remove object if it goes off the screen
        if (obj.y > stage.stageHeight - 140) {
            if(obj.typestr == 'good'){
                fruitFail.play();
            }
            removeChild(obj);
            objects.splice(i, 1);
        }
    }
}

// Create sounds for catching fruits and bad objects
var goodSound:Sound = new catch_fruit();
var badSound:Sound = new catch_bad(); 

function updateScore(type:String):void {
    if (type == "good") {
        score++;
        messageTextField.text = "Good!";
        messageTextField.textColor = 0x00FF00;
        goodSound.play();
        
    } else if (type == "bad") {
        score--;
        messageTextField.text = "Bad!";
        messageTextField.textColor = 0xFF0000;
        badSound.play();
    }

    // Update score and level display
    scoreTextField.text = "Score: " + score;
    levelTextField.text = "Level: " + level;

    // Check if the player has reached the score threshold to increase the level
    if (score >= level * scoreThreshold) {  // Level increases every 5 points
        level++;
        speed += 3; // Increase speed by 3 with each level
    }

    setTimeout(function():void {
        messageTextField.text = "";
    }, 1000);

    if (score < 0) {
        // Remove all objects and stop gameplay
        removeAllObjects();
        removeEventListener(Event.ENTER_FRAME, moveObjects);
        // Display "Game Over" screen
        setTimeout(displayGameOverScreen, 2000);
    }
}

// Function to remove all objects from the stage
function removeAllObjects():void {
    for (var i:int = objects.length - 1; i >= 0; i--) {
        if (contains(objects[i])) {
            removeChild(objects[i]); // Remove the object from the stage
        }
        objects.splice(i, 1); // Remove the object from the array
    }
}

var gameOver:Sound = new game_over();

    var gameOverText:TextField = new TextField();
    var overlay:Sprite = new Sprite();

function displayGameOverScreen():void {
    gameOverText.text = "GAME OVER!";
    gameOverText.textColor = 0xFF0000;
    gameOverText.width = stage.stageWidth;
    gameOverText.height = 200;
    gameOverText.x = 0; // Align horizontally centered
    gameOverText.y = (stage.stageHeight - 100) / 2; // Align vertically centered

    var gameOverFormat:TextFormat = new TextFormat();
    gameOverFormat.size = 50;
    gameOverFormat.align = TextFormatAlign.CENTER;
    gameOverText.setTextFormat(gameOverFormat);

    // Create a background for "Game Over" screen
    overlay.graphics.beginFill(0x000000, 1); // Black with 100% opacity
    overlay.graphics.drawRect(0, 0, stage.stageWidth, stage.stageHeight);
    overlay.graphics.endFill();

    // Add background to stage
    addChild(overlay);

    // Add "Game Over" text on top of the overlay
    addChild(gameOverText);
    gameOver.play();
	
// Create the "Try Again" button
var tryAgainButton:SimpleButton = new SimpleButton();

// Create a container for the button graphics and label
var buttonContainer:Sprite = new Sprite();

// Create the button's upState, overState, and downState as before
var upState:Sprite = new Sprite();
upState.graphics.beginFill(0x00FF00); // Green color
upState.graphics.drawRect(0, 0, 200, 50);
upState.graphics.endFill();

// Create a TextField for the label
var buttonLabel:TextField = new TextField();
buttonLabel.text = "Try Again";
buttonLabel.textColor = 0xFFFFFF; // White text
buttonLabel.selectable = false; // Make the text unselectable

// Set the label's font size and alignment
var labelFormat:TextFormat = new TextFormat();
labelFormat.size = 18;
labelFormat.align = TextFormatAlign.CENTER;
buttonLabel.setTextFormat(labelFormat);

// Center the label inside the button
buttonLabel.width = 200; // Match button width
buttonLabel.height = 50; // Match button height
buttonLabel.x = 0; // Horizontally center
buttonLabel.y = (upState.height - buttonLabel.textHeight) / 2; // Vertically center

// Add the label to the button container
buttonContainer.addChild(upState);
buttonContainer.addChild(buttonLabel); // Add the label on top of the button

// Add the container to the button's states
tryAgainButton.upState = buttonContainer;
tryAgainButton.overState = buttonContainer;
tryAgainButton.downState = buttonContainer;
tryAgainButton.hitTestState = buttonContainer;

// Position the button on the stage
tryAgainButton.x = (stage.stageWidth - tryAgainButton.width) / 2;
tryAgainButton.y = (stage.stageHeight - tryAgainButton.height) / 2 + 100; // Position below the "Game Over" text

// Add the click event listener
tryAgainButton.addEventListener(MouseEvent.CLICK, restartGame);

// Add the button to the stage
addChild(tryAgainButton);


}

// Function to restart the game
function restartGame(event:MouseEvent):void {
    // Reset score, level, and speed
    score = 0;
    level = 1;
    speed = 7.0;
    
    // Clear existing objects
    removeAllObjects();
    
    // Reset score and level displays
    scoreTextField.text = "";
    levelTextField.text = "" ;
    // remove game over things
    if (overlay && contains(overlay)) removeChild(overlay);
    if (gameOverText && contains(gameOverText)) removeChild(gameOverText);

	
    // Restart the game
    removeChild(event.target as SimpleButton); // Remove the "Try Again" button
    play();
}
