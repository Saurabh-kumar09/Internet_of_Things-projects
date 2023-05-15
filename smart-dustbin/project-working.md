## Working Explanation: 
This Smart dusbtin is built using two sensors - Ultrasonic sensor & Servo motor and thingSpeak cloud which displays the status dustbin level.
* I've used two ultrasonic sensor, each performing different function:
1. First one is detecting the object outside in front of dustbin as per the code instructions.
2. Second one is used to measure the level of dustbin filled/empty. 

* The second sensor, Servo motor is used to automatically open the dustbin cover when outer utrasonic sensor senses any object in range of 30cm and 
it closes itself after a delay 0f 20ms-30ms.
* The result of dustbin level is displayed on ThingSpeak cloud.
