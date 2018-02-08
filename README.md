## EE183DA Lab 2
2/8/2018


By Ryan Wang, Arnold Woo, and Daniel Fong

# Introduction


In this lab, our team created a “music band” consisting of two robots that played sound and interacted with each other to create harmony. A web server created by one of the robots will allow a user to choose the duration of the song. Once a duration is chosen, one robot uses a distance sensor and speaker, which changes the speaker’s pitch based on how far away a human hand was from the distance sensor. The robot that received the signal to start will signal to the second robot via IR sensor to start moving it’s motor in a steady motion, creating a steady drum beat. Once the duration has ended, the first robot will signal to the other robot to stop and the music will end.


# Methods

The Wiring Schematic
![schematic](https://user-images.githubusercontent.com/36172219/35955709-f19cb0a8-0c45-11e8-80e0-d800c075a4f3.png)


The Web Interface:
![web_interface](https://user-images.githubusercontent.com/36172219/35955859-f0f85e62-0c46-11e8-8117-6e209004e597.png)


Picture of the Complete Setup:
![complete setup](https://user-images.githubusercontent.com/36172219/35955973-ad029960-0c47-11e8-866a-4b2d71944621.jpg)


We first set up the web server using the microcontroller, making sure that the interaction with the server and microcontroller was functioning. We then set up the duration and note buttons on the web server to allow the user to choose how long they want to perform for or if a certain note is to be played. After confirming that the server worked, we coded the distance sensor to read distances. Human interaction with the distance sensor would generate the distances which were then used as the frequency for the speaker. When a duration on the web server is sent to the microcontroller, the distance sensor and speaker will play for that duration and a servo with a piece of paper will turn from 0 to 90 degrees. After the duration is over, the motor will reset to 0 degrees.


Picture of the Distance Sensor MCU:
![distance sensor](https://user-images.githubusercontent.com/36172219/35955974-ad1e2b76-0c47-11e8-9a70-e22d8a0e2edd.jpg)


The second robot consists of an IR sensor to sense a signal from the first robot and a motor that turns between 0 to 110 degrees as long as the IR sensor is covered. This motion creates the drum beat. We also created a drum for the robot to beat on.


Picture of the IR Sensor MCU
![drum player](https://user-images.githubusercontent.com/36172219/35955975-ad3a9130-0c47-11e8-9244-651e28aa7c81.jpg)


To interact with each other, when the duration is chosen, the first robot will use the motor with a piece of paper to cover the IR sensor of the second robot to signal the start of the music. Once the duration has ended, the first robot will reset it’s motor, uncovering the IR sensor of the second robot, stopping the performance.
A functionality that can be added is that the single notes sent to the first robot from the web server could also signal to the second robot to start playing. However, the single notes allow a solo to be played.


[Demo Video Link](https://youtu.be/P9-WKYurkpA)


