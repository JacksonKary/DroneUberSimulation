#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief Drone factory class
 */
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Default deconstructor.
   */
  virtual ~DroneFactory() {}
  /**
   * @brief Create entity function to create the corresponding entity
   * @param[in] entity JsonObject reference containing details for the entity
   * @return Returns the created IEntity pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // DRONE_FACTORY_H_
