#include "Duck.h"
#include "routing/astar.h"
#include "routing_api.h"
#include "AstarStrategy.h"
#include "graph.h"
#include <cstdlib>
using namespace routing;

Duck::Duck(JsonObject& obj) : details(obj) {
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};

    JsonArray dir(obj["direction"]);
    direction = {dir[0], dir[1], dir[2]};

    destination = {492, 255, 444};  // This is a point on the river

    speed = obj["speed"];
}

void Duck::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Duck::Complete() {
    this->completed = true;
}

void Duck::Update(double dt, std::vector<IEntity*> scheduler) {
    if (astar) {
        if (astar->IsCompleted()) {
            delete astar;
            astar = NULL;
            Complete();
        } else {
            astar->Move(this, dt);
        }
    } else {
        if (!this->completed) {
           astar = new AstarStrategy(this->position, this->destination, graph); 
        }
    }
}