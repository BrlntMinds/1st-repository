# Brilliant Minds´ Read Me 

 

Overall description of our robotic solution

 

First things first. The main component we need is the brain, which is fed with all the code we built. We utilized the programming language C++. The brain, a Me Auriga main control board, is the one that sends, receives and analyzes information. With the help of the code, it will compare and analyze the data provided and obtained from the track.

<P ALIGN=center><img src="https://m.media-amazon.com/images/I/7167MjYhLvL.jpg" width="25%"/>

Our robot does 3 important steps: collects information, processes it, and acts upon it.

First, **Information gathering**: Through the sensors we use, the Ultrasonic sensors and the Camera, we collect information about the robot´s surrounding at any given time. If the robot is close or far from an object or the barriers, it will make use of its sensors to determine its position and act accordingly. While the ultrasonic sensors confirm where more space is and where to turn, the camera easily detects the distance and color to identify and dodge obstacles.

<P ALIGN=center><img src="https://robu.in/wp-content/uploads/2018/04/Pixy-2.1-Smart-Vision-Sensor-Object-Tracking-Camera.png" width="25%"/> <img src="https://www.makeblock.com/cdn/shop/products/612x9HPbzsL._SL1000_f0013e19-fd69-4e7c-a143-5a8a600769fa_1000x.jpg?v=1642055448" width="25%"/>

After many tryouts we discovered that, in some cases, the ultrasonic sensors were not able to detect the distance correctly, whereas the camera, apart from detecting the distance, can also detect the colors of obstacles present in the second challenge of the race, but it is a bit problematic when it comes to coding since it is not compatible with the first language of coding that we were using at the beginning, Makeblock´s blocks-base coding language, so we had to make an extra effort to translate it to C++.

Second, **Information processing**: The element of hardware which processes the information in our robot is the brain. In the code, we inserted multiple instructions which adapt to both challenges of the race. The brain receives the first part of the information, then it goes through the procedure written in the code and finally sends the information into the energy system, thus sending energy to the servo which then turns in the direction that the brain instructs it to turn.

Lastly, **Acting by the code autonomously**: After sending the information through the energy system to turn on the propulsion motors and the servo motor, also known as the direction motor, the robot starts to run and avoid obstacles.

The propulsion motor is the one that makes it possible for our robot to move forward and backward while the servo, or direction motor, is the one that makes it possible for our robot to turn left and right with the desired angle stated in the coding based on the scenario interpreted by the information previously gathered.

<P ALIGN=center><img src="https://education.makeblock.com/wp-content/uploads/2021/01/word-image-463.png" width="30%"/> <img src="https://core-electronics.com.au/media/catalog/product/cache/d5cf359726a1656c2b36f3682d3bbc67/8/0/80087-3-800x800.jpg" width="25%"/>

 # Coding

Now, it is the time to narrate the most difficult part of this process, coding.

Code: The hardest part of our robot is the coding, the **first challenge**, the easiest one, is that the robot needs to turn and follow the course without crashing against either the internal or external walls. To complete this challenge we needed to use 2 of the 3 ultrasonic sensors, the ones on the sides of the robot to detect if there is or not an obstacle on its sides. If there was an obstacle, then it would try to dodge it; on the other hand, when it doesn’t detect an obstacle,  it will steer into the area where there aren’t any obstacles.

In addition to this difficulty, keeping the bot in the same lane where it was initially placed just added an extra spice to the contest. In order to be up to the challenge, we created the variable “Lane”. This variable maintains the robot in the same lane where it was originally placed when starting the track. This variable works by, at the beginning of the track, measuring the distance between the internal and external wall, then that distance is stored into the variable "Lane", and the robot stays in that range, getting this value: if it’s in the internal lane, the variable is 1; in the middle, it’s 2, and in the external lane, it’s 3. These are the ones that tell the robot on which side there is more room to turn. In the programming, we added the variable lane. Depending on how much space the robot has on each side it will determine which lane is. After this, the vehicle moves forward and in the turn depending on how much space it has on each side it identifies if the track is clockwise or counterclockwise. If the robot is on lane 2 (center lane) or lane 3 (outer lane), the vehicle will make an adjustment so in both cases it could move to lane 1 (inner lane). This was made so our robot could complete the challenge faster.

<P ALIGN=center><img src="https://www.zone01.ca/images/2022/01/15/future-engineers.jpg" width="30%"/> 
	
For the **second challenge**, which has a greater difficulty, the robot has not only to evade the walls like in the first challenge, but also it has to turn in a direction indicated in the code depending on the color of the obstacle, which in this case will be either red or green. For this task, it will not use the ultrasonic sensors, as they can’t detect color, so the robot will use the camera which is able to detect the color of the obstacle and steer in the desired path according to the coding. The camera has a special function to let us visualize what the camera is watching live. This function lets us choose what objects to identify. Once picked out, these are saved into the camera’s memory including their size and color, which we can select and code for further instructions. When the camera detects an obstacle, a white-translucent square appears over the object to show that it is detecting something, this appears in the live feed during testing. With all this information, it is just a matter of analyzing the situation and creating a program that can act upon the task to be completed, although its clearly easier said than done. We decided to save the colors red and green since they are the ones needed in the second challenge.
<P ALIGN=center><img src="https://images.squarespace-cdn.com/content/v1/5c075fd2372b96bbf7590d6e/1612142923857-D8TLHORWQIR1F2KYOBDC/__wro2020-fe.png" width="50%"/>
	
We only use the variable "Lane" in the first challenge, while in the second challenge we set as default the second lane. 

Once started, the robot doesn’t stop because of that we added the variable *count*, this one helps the vehicle to count how many times it turns and the define when it has to stop. Because our robot has to complete 3 laps and on each laps it turns 4 times then we put or robot to count 12 times it turns to then stop.


The robot uses a battery pack of 3 18650 AA batteries, which are connected in series to the brain which distributes the energy into the camera, ultra sonic sensors and servo and propulsion motor.

 <P ALIGN=center><img src="https://www.vapesuperstore.co.uk/cdn/shop/collections/18650-batteries.jpg?v=1581440276" width="25%"/>

With these, the robot successfully stays in the desired path and successfully completes the course with maximum efficiency, easily avoiding all the obstacles and walls, and finally keeping itself in the best time and path cited for each challenge’s course.
