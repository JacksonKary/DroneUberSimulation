#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"
/**
 * @brief A class for factory classes to inherit from
 */
class IEntityFactory {
 public:
  /**
   * @brief Default deconstructor.
   */
  virtual ~IEntityFactory() {}
  /**
   * @brief Create entity function to create the corresponding entity
   * @param[in] entity JsonObject reference containing details for the entity
   * @return Returns the created IEntity pointer
   */
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif  // I_ENTITY_FACTORY_H_
