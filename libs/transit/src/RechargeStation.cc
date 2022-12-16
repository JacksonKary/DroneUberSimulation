#define _USE_MATH_DEFINES
#include "RechargeStation.h"
// #include "BeelineStrategy.h"
// #include "DfsStrategy.h"
// #include "AstarStrategy.h"
// #include "DijkstraStrategy.h"
// #include "SpinDecorator.h"
// #include "JumpDecorator.h"

#include <cmath>
#include <limits>

RechargeStation::RechargeStation(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  available = true;
}

RechargeStation::~RechargeStation() {
  // Delete dynamically allocated variables
}



