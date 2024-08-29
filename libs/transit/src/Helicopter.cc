#include "Helicopter.h"

#include "BeelineStrategy.h"

Helicopter::Helicopter(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  SetNewDestination();
}

void Helicopter::SetNewDestination() {
  destination = {Random(-1400, 1500), position.y, Random(-800, 800)};
}

float Helicopter::Random(float Min, float Max) {
  return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

JsonObject Helicopter::GetDetails() const { return details; }

void Helicopter::Rotate(double angle) {
  direction.x = direction.x * std::cos(angle) - direction.z * std::sin(angle);
  direction.z = direction.x * std::sin(angle) + direction.z * std::cos(angle);
}

void Helicopter::Update(double dt, std::vector<IEntity *> scheduler) {
  if (strategy) {
    if (strategy->IsCompleted()) {
      SetNewDestination();
      strategy = new BeelineStrategy(position, destination);
    } else {
      strategy->Move(this, dt);
    }
  } else {
    strategy = new BeelineStrategy(position, destination);
  }
}
