#include "DroneFactory.h"
#include "BatteryDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("drone") == 0) {
    std::cout << "Drone Created" << std::endl;
    // Drone* droney = new Drone(entity);
    return new Drone(entity);
  }
  return nullptr;
}
