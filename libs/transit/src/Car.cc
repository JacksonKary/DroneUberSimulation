#include "Car.h"

#include "AstarStrategy.h"

Car::Car(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  SetNewDestination();
}

void Car::SetNewDestination() {
  destination = {Random(-1400, 1500), position.y, Random(-800, 800)};
}

float Car::Random(float Min, float Max) {
  return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

JsonObject Car::GetDetails() const { return details; }

void Car::Rotate(double angle) {
  direction.x = direction.x * std::cos(angle) - direction.z * std::sin(angle);
  direction.z = direction.x * std::sin(angle) + direction.z * std::cos(angle);
}

void Car::Update(double dt, std::vector<IEntity *> scheduler) {
  if (strategy) {
    if (strategy->IsCompleted()) {
      SetNewDestination();
      strategy = new AstarStrategy(position, destination, graph);
    } else {
      strategy->Move(this, dt);
    }
  } else {
    strategy = new AstarStrategy(position, destination, graph);
  }
}
