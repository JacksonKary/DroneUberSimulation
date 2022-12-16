#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

/**
 * @brief robot factory class
 */
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief Create entity function to create the corresponding entity
   * @param[in] entity JsonObject reference containing details for the entity
   * @return Returns the created IEntity pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // ROBOT_FACTORY_H_
