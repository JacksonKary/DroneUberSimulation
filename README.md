# CSCI 3081 Project - Drone Simulation System

A full containerized version is available on my Dockerhub: https://hub.docker.com/repository/docker/jacksonkary917/drone_simulation

Here is a video demonstration of the current build: 

https://user-images.githubusercontent.com/117691954/205541866-39ae0da9-16ed-4abb-bf8c-fb118ff52c3d.mp4

This program simulates a drone delivery system that helps get robots to their destination. You can set the pickup location and the final destination of the robot, and afterward the drone will come and pick up the robot toward their destination. Pay attention when they reach the destination, there's a little surprise when they arrive! Also pay attention to the environment, there are additional entities sharing this world.

Upon running:

Navigate to http://127.0.0.1:8081 and you should see a visualization.

Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

The current state of this project was developed by a team of myself and three others. We're currently in a sprint to add a few hugely impactful features to the core of the simulation by the end of the semester. I'd be more than happy to explain our process and show the final result!

#### What is in this directory?
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
</ul>
