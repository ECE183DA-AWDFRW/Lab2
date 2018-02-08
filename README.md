## EE183DA Lab 2
2/8/2018


By Ryan Wang, Arnold Woo, and Daniel Fong

# Introduction

In this lab, our team created a “music band” consisting of two robots that played sound and interacted with each other to create harmony. A web server created by one of the robots will allow a user to choose the duration of the song, known as "free play" mode. Once a duration is chosen, one robot uses a distance sensor and speaker, which changes the speaker’s pitch based on how far away a human hand was from the distance sensor. The robot that received the signal to start will signal to the second robot via IR sensor to start moving it’s motor in a steady motion, creating a steady drum beat. Once the duration has ended, the first robot will signal to the other robot to stop and the music will end. The user can also press buttons through the web app to play specific tones.


# Methods

The Wiring Schematic
![schematic](https://user-images.githubusercontent.com/36172219/35955709-f19cb0a8-0c45-11e8-80e0-d800c075a4f3.png)


The Web Interface:


![web_interface](https://user-images.githubusercontent.com/36172219/35955859-f0f85e62-0c46-11e8-8117-6e209004e597.png)


Picture of the Complete Setup:
![complete setup](https://user-images.githubusercontent.com/36172219/35955973-ad029960-0c47-11e8-866a-4b2d71944621.jpg)


We first set up the web server using the microcontroller, making sure that the interaction with the server and microcontroller was functioning. We then set up the duration and note buttons on the web server to allow the user to choose how long they want to perform for or which note to play. After confirming that the server worked, we coded the distance sensor to read distances. Human interaction with the distance sensor would generate the duration of the echo. These durations were then transformed using the linear equation below, which were then used as the frequency for the speaker.

**Frequency = (-1.143*Duration)+2114**


![graph](https://user-images.githubusercontent.com/36172219/35957437-69ab7cd2-0c50-11e8-846d-2b71b3223217.png)


Picture of the Distance Sensor MCU:
![distance sensor](https://user-images.githubusercontent.com/36172219/35955974-ad1e2b76-0c47-11e8-9a70-e22d8a0e2edd.jpg)

When a duration on the web server is sent to the microcontroller, the distance sensor and speaker will play for that duration and a servo with a piece of paper will turn from 0 to 90 degrees. After the duration is over, the motor will reset to 0 degrees.


The second robot consists of an IR sensor to sense a signal from the first robot and a motor that turns between 0 to 110 degrees as long as the IR sensor is covered. This motion creates the drum beat. We also created a drum for the robot to beat on.


Picture of the IR Sensor MCU
![drum player](https://user-images.githubusercontent.com/36172219/35955975-ad3a9130-0c47-11e8-9244-651e28aa7c81.jpg)

To interact with each other, when the duration is chosen, the first robot will use the motor with a piece of paper to cover the IR sensor of the second robot to signal the start of the music. Once the duration has ended, the first robot will reset it’s motor, uncovering the IR sensor of the second robot, stopping the performance.

A functionality that can be added is that the single notes sent to the first robot from the web server could also signal to the second robot to start playing. However, the single notes allow solos to be played.


[**Demo Video Link**](https://youtu.be/P9-WKYurkpA)


# Bill of Materials
| Item     | Cost         |
|----------|:------------:|
|HC-SR04 Ultrasonic Sensor|$1.97|
|Speaker - PCB Mount|$1.95|
|ESP-12E WiFi Module (x2)|$6.00/unit|
|ESP-12E Motor Shield (x2)|$6.00/unit|
|FS90 Servo Motor (x2)|$3.80/unit|
|Breadboard (x2/set)|$7.00/set|
|IR Sensor FC-51|$2.00|
|**TOTAL:**|**$40.72**|

# Instructions
Instrument #1:


1. First, the ESP-12E Wifi Module microcontroller was connected to the ESP-12E Motor Shield.
2. The HC-SR04 Ultrasonic Sensor and Speaker - PCB Mount were then placed on the breadboard.
3. Using female/male jumper wires, the ultrasonic sensor and speaker were connected to the motor shield as follows:

4. Ultrasonic Sensor
    * Ground (“Gnd”) was connected to “G” on the motor shield.
    
    * “Echo” was connected to D5 on the motor shield.
   
    * “Trig” was connected to D4 on the motor shield.
    
    * “Vcc” was connected to “VIN” on the motor shield. 
    
5. Speaker
      
    * “–” was connected to G6 on the motor shield.
    * “+” was connected to D6 on the motor shield.
    
6. Then, an FS90 Servo Motor was appropriately connected onto pins D3, V3, and G3 of the motor shield. For this model of motor, the connecting orange wire is for signal input (D3), the red wire is for power supply voltage (V3), and the brown wire is for ground (G3). A simple end effector was made from masking tape to use as a cover of sorts to interact with the IR sensor on Instrument #2. The servo motor was then positioned on the breadboard of Instrument #2 next to the aforementioned IR sensor.


Instrument #2:
1. First, the ESP-12E Wifi Module microcontroller was connected to the ESP-12E Motor Shield.
2. The IR Sensor FC-51 was connected to the breadboard, and then 3 female/male jumper wires were used to connect to the motor shield.
    * “Vcc” on the IR sensor was connected to the V3 pin on the motor shield.
    * “Gnd” on the IR sensor was connected to the G3 pin on the motor shield.
    * “Out” on the IR sensor was connected to the D3 pin on the motor shield.
3. Another FS90 Servo Motor was then connected to the D4, V4, and G4 pins of the motor shield.
    * Again, for this model of motor, the connecting orange wire is for signal input (D4), the red wire is for power supply voltage (V4), and the brown wire is for ground (G4).
    * An end effector was made from masking tape and a loose jumper wire to physically interact with a drum for percussive sound generation.
    * The servo motor was elevated and positioned at sufficient height to maximize volume of percussive beats.


Other:
1. A makeshift drum was constructed from a roll of duct tape and paper.
2. A simple board/platform was constructed from cardboard to implement the entire system modularly.
