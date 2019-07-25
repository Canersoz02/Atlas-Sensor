# Atlas-Ultrasonic-Sensor
Here is the code I developed while interning at Atlas Robotics, a robotic forklift startup, for integrating a new set of sensors to their production robot. This repository includes an arduino library to make initializing sensors easier, example arduino code for initalizing two sensors and publishing them into different topics using rosserial, a ROS node for reading and optimising sensor data, and a launch file for launching rosserial and the optimisation node at the same time. 

# Prerequisites 
ROS: [http://wiki.ros.org/ROS/Installation](http://wiki.ros.org/ROS/Installation)

Rosserial:[http://wiki.ros.org/rosserial](http://wiki.ros.org/rosserial)

MegaunıLink Arduino Library for exponantial filtering: [https://www.megunolink.com/documentation/arduino-library/](https://www.megunolink.com/documentation/arduino-library/)

# Sensor schematics
In this project two Maxsonar EZ1 ultrasonic distance sensors were used however you can easily add more sensors or switch to another distance sensor with a few alterations in the arduino code. 

# Arduino Sensor Library
This library makes it easier to initialize and 
