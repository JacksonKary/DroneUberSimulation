# Drone Uber Simulation

#### This project is a drone Uber simulation, which simulates drones providing an Uber-like service for robots. 

Trips can be scheduled using different routing algorithms, including AStar, Depth First Search, and Dijkstra. Scheduling a trip involves choosing a name for the robot, a routing algorithm, and a specific start and end point. 
Once a trip is scheduled, the drone, from whatever position it is currently in, will pick the robot up from the starting point and drop it off at the endpoint. However, the drones also have a limited amount of battery, which means that if the drone cannot complete a trip without charging, it finds a charging station first to recharge its battery. Pay attention when they reach the destination, there's a little surprise when they arrive! Also be sure to observe the environment, there are additional entities sharing this world.

*This project was developed by myself and two others. Our development process was a modified version of Scrum.*


## Here are some video demonstrations of the final build:

This first video shows a full trip with the camera focused on the drone. (The video was sped up significantly in post)

https://user-images.githubusercontent.com/117691954/208202504-aba3f2a9-beb6-4d4d-8e3f-401013b5b221.mp4

This second video shows a real-time scheduling of a trip, as well as the <i>add helicopter</i> feature.

https://user-images.githubusercontent.com/117691954/205541866-39ae0da9-16ed-4abb-bf8c-fb118ff52c3d.mp4

The following video shows an instance where the drone's battery was too low to handle the next trip, so it stopped off at a charging station first.


https://user-images.githubusercontent.com/117691954/208200732-93d0637a-1df3-4126-b7e2-78cf8206a57a.mp4



## Instructions for running the simulation:
**Try it out for yourself!**

### A full containerized version with instructions is available on my Docker Hub: https://hub.docker.com/repository/docker/jacksonkary917/drone_final

#### Alternatively, you can build and run it yourself:

1. **Clone the Repository**: First, clone this git repository into your directory of choice:
    ```bash
    git clone git@github.com:JacksonKary/DroneUberSimulation.git
    ```

2. **Change Directory**: Next, change your working directory to the newly created `DroneUberSimulation` folder:
    ```bash
    cd DroneUberSimulation
    ```

3. **Build the Program**: To build the program so it's ready to run, use the following command:
    ```bash
    make -j
    ```
   > **Note**: If your environment can't execute the `make` command, you may need to install it first. On most Unix-based systems, you can install it using:
   > - **Debian/Ubuntu**: `sudo apt-get install build-essential`
   > - **Fedora**: `sudo dnf groupinstall "Development Tools"`
   > - **macOS**: `xcode-select --install`

    Any build warnings from the `make -j` command can be ignored.

4. **Run the Program!**: To run the program, use the following command:
    ```bash
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```
    You have the option to change the port (default is 8081).

5. **Upon running**:
  - Navigate to http://127.0.0.1:8081 and you should see a visualization.
  - In another tab, navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.


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
