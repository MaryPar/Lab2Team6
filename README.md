# Lab2Team6
Texas Tech University ECE 3332 - Project Lab II, Team 6 - Project Source Code

# Software Overview 

## CV System
The CV System will provide the analyzed image data in JSON format when a GET request is submitted to the provided web server.

## Command Center (Laptop)
The Command Center (CC) will be the central hub of data processing and logic. This will be housed on a laptop, and will use Java as the backend.
The CC will house a Communication (Comms) Center and a Logic center. They are explained below. 

## Comms Center
The Comms Center will be the CC component that communicates between the different areas of our project.
It will perform the following communications:
1. GET request to Swarm server
2. Socket server to talk to ESP32s on robots 
3. Possible web server component for real-time metrics

## Logic Center
The Logic Center will perform all the necessary computation to decide the actions for the robots based on the CV data. 
It will recieve the CV data from the Comms Center, and send it through a data pipeline to decide what to do. 

## Robots
The robots will have ESP32s housed on their bodies to talk with the Comms Center. 
They will recieve certain states (such as Attacking, Defending, Looking for Ball, etc.) from the Comms Center, and will have
predefined HW commands (for the motors) onboard to perform based on the state given to them. 
