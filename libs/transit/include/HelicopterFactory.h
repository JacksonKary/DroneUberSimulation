#ifndef HELICOPTER_FACTORY_H_
#define HELICOPTER_FACTORY_H_

#include <vector>

#include "Helicopter.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief HelicopterFactory class to make helicopters
 */
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief Default deconstructor.
   */
  virtual ~HelicopterFactory() {}

  /**
   * @brief Create entity function to create the corresponding entity
   * @param[in] entity JsonObject reference containing details for the entity
   * @return Returns the created IEntity pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
