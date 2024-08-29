#include "BatteryDecorator.h"
#include "math/vector3.h"
#include "BeelineStrategy.h"
#include "routing/depth_first_search.h"
#include "routing/astar.h"
#include "routing/dijkstra.h"
#include "routing_api.h"

#include <cmath>
#include <limits>

BatteryDecorator::BatteryDecorator(IEntity* drone_) {
    droney = drone_;
    time = 0;
    batteryLevel = 100;
}

float BatteryDecorator::nearestStation(Vector3 point) {
    // find nearest station from a given point
    float minDis = std::numeric_limits<float>::max();
    for (Vector3 s : stations) {
        float distToStation = point.Distance(s);
        if (distToStation <= minDis) {
            minDis = distToStation;

            closestStation = s;  // Sets the closest station member variable
        }
    }
    return minDis;  // returns the distance to the closest station
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    if (droney->ReturnNearestEntity()) {
        distToStationFromDest = nearestStation(
            droney->ReturnNearestEntity()->GetDestination());
        if (!isPathCalculated) {
            distToDest = CalculatePathLength();
        }
    } else {
         distToStationFromDest = nearestStation(droney->GetDestination());
        // distToDest = droney->GetPosition().Distance(
            // droney->GetDestination());
        // isPathCalculated = false;
        // distToDest = 0;
        isPathCalculated = false;
    }
    /* distCanTravel = 100 * timeToDecr * droney->GetSpeed(); */

    if (bee) {
        if (!(bee->IsCompleted())) {
            bee->Move(droney, dt);
            distCanTravel -= droney->GetSpeed() * dt;
            // std::cout << "move to charge" << std::endl;
        } else {
            Recharge();
            delete bee;
            bee = NULL;
        }
    } else if ((distCanTravel - distToDest) < distToStationFromDest) {
        // can't get to station after reaching dest
        // go to station and refill

        // Get closest station to current position
        distToStation = nearestStation(droney->GetPosition());

        // Set new destination for drone (goes to station)
        droney->SetDestination(closestStation);
        droney->SetAvailability(false);
        SetBeeline();
    } else if (distToDest > distCanTravel) {  // can't make trip
        // go to station and refill

        // Get closest station to current position
        distToStation = nearestStation(droney->GetPosition());
        // Set new destination for drone (goes to station)
        droney->SetDestination(closestStation);
        droney->SetAvailability(false);
        SetBeeline();
    }

    if (!(droney->GetAvailability())) {
        // dontDec = false;
        time++;
        // distCanTravel -= droney->GetSpeed() * dt;
        // enough time has passed to decrement bat lvl
        if ((time % timeToDecr) == 0) {
            batteryLevel--;
            // std::cout << batteryLevel << std::endl;
        }
        dontDec = false;
    } else {
        dontDec = true;
    }
    if (dontDec) {
        distCanTravel = distCanTravel - distToDest;
        distToDest = 0;
        dontDec = false;
    }

    if (batteryLevel <= 25) {
        droney->SetColor("#ff0000");  // red
    } else if (batteryLevel <= 50) {
        droney->SetColor("#ff5733");  // orange
    } else if (batteryLevel <= 75) {
        droney->SetColor("#ffff00");  // yellow
    } else {
        droney->SetColor("#00ff00");
    }  // green default

    if (!bee) {
        droney->Update(dt, scheduler);
        // distCanTravel -= droney->GetSpeed() * dt;
    }
}

void BatteryDecorator::SetBeeline() {
    bee = new BeelineStrategy(droney->GetPosition(), droney->GetDestination());
}

void BatteryDecorator::Recharge() {
    distCanTravel = timeToDecr * droney->GetSpeed();
    batteryLevel = 100;
    time = 0;
    droney->SetColor("#00ff00");  // green

    droney->SetAvailability(true);
}

float BatteryDecorator::CalculatePathLength() {
    Vector3 destination = droney->ReturnNearestEntity()->GetDestination();
    Vector3 position = droney->ReturnNearestEntity()->GetPosition();
    std::string targetStrategyName =
        droney->ReturnNearestEntity()->GetStrategyName();
    // std::cout << targetStrategyName << std::endl;
    std::vector<std::vector<float>> path;

    std::vector<float> positionV;
    positionV.push_back(position.x);
    positionV.push_back(position.y);
    positionV.push_back(position.z);

    std::vector<float> destinationV;
    destinationV.push_back(destination.x);
    destinationV.push_back(destination.y);
    destinationV.push_back(destination.z);

    std::vector<float> start = graph->NearestNode(positionV,
                    EuclideanDistance())->GetPosition();
    std::vector<float> end = graph->NearestNode(destinationV,
                    EuclideanDistance())->GetPosition();

    if (targetStrategyName.compare("astar") == 0) {
        path = graph->GetPath(start, end, AStar::Default());
    } else if (targetStrategyName.compare("dfs") == 0) {
        path = graph->GetPath(start, end, DepthFirstSearch::Default());
    } else if (targetStrategyName.compare("dijkstra") == 0) {
        path = graph->GetPath(start, end, Dijkstra::Default());
    }

    // path is defined
    // now calculate length of path
    int currentIndex = 0;
    int maxIndex = path.size()-1;
    float sum = 0;
    for (currentIndex; currentIndex < (maxIndex - 1); currentIndex++) {
        float x = path[currentIndex].at(0);
        float y = path[currentIndex].at(1);
        float z = path[currentIndex].at(2);
        Vector3 prev(x, y, z);
        x = path[currentIndex + 1].at(0);
        y = path[currentIndex + 1].at(1);
        z = path[currentIndex + 1].at(2);
        Vector3 curr(x, y, z);
        sum += prev.Distance(curr);
    }

    float beeLength = droney->GetPosition().Distance(
        droney->ReturnNearestEntity()->GetDestination());
    isPathCalculated = true;

    return (beeLength + sum);
}
