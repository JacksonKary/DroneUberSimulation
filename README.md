# Drone Uber Simulation

#### This project is a drone Uber simulation, which simulates drones providing an Uber-like service for robots. 

Trips can be scheduled using different routing algorithms, including AStar, Depth First Search, and Dijkstra. Scheduling a trip involves choosing a name for the robot, a routing algorithm, and a specific start and end point. 
Once a trip is scheduled, the drone, from whatever position it is currently in, will pick the robot up from the starting point and drop it off at the endpoint. However, the drones also have a limited amount of battery, which means that if the drone cannot complete a trip without charging, it finds a charging station first to recharge its battery. Pay attention when they reach the destination, there's a little surprise when they arrive! Also be sure to observe the environment, there are additional entities sharing this world.

*This project was developed by myself and two others. Our development process was a modified version of Scrum.*


## Here are some video demonstrations of the final build:

#### The first video shows a full trip. (The video was sped up significantly in post to meet the 10Mb file limit for imbedded videos)

https://user-images.githubusercontent.com/117691954/208202504-aba3f2a9-beb6-4d4d-8e3f-401013b5b221.mp4


#### The following video shows an instance where the drone's battery was too low to handle the next trip, so it stopped off at a charging station first.


https://user-images.githubusercontent.com/117691954/208200732-93d0637a-1df3-4126-b7e2-78cf8206a57a.mp4



## Instructions for running the simulation:

#### A full containerized version is available on my Dockerhub: https://hub.docker.com/repository/docker/jacksonkary917/drone_final

#### Alternatively, you can build and run it yourself:

First, pull this repository and open a terminal in the main directory.

To build the project, run the command
```bash
make -j
```
Any warnings can be ignored.

Then, to run the project, use the command
```bash
./build/bin/transit_service 8081 apps/transit_service/web/
```

Upon running:

Navigate to http://127.0.0.1:8081 and you should see a visualization.

Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.


## What is in this directory?
<ul>
  <li>  <code>app</code> folder, which contains:
    <ul>
      <li>  <code>graph_viewer</code> : producing graph visualization
      <li>  <code>transit_service</code> : visualization
    </ul>
  <li>  <code>libs</code> folder, which contains:
    <ul>
      <li>  <code>routing</code> : finding the paths
      <li>  <code>transit</code> : entities properties
    </ul>
  <li>  <code>dependencies</code>
  <li>  <code>docs</code> : Doxygen documentation
  <li>  <code>pics</code> : a few UML diagrams for the two decorator patterns *note: there are many other design patterns in this project*
  
</ul>


## Documentation
To view the detailed Doxygen documentation, navigate to: <code>docs/html/index.html</code>
