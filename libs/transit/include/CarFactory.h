#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include <vector>

#include "Car.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief Creates cars
 */
class CarFactory : public IEntityFactory {
 public:
  /**
   * @brief Car deconstructor
   */
  virtual ~CarFactory() {}
  /**
   * @brief CreateEntity function to make cars
   * @param[in] entity JsonObject refernce to create cars from
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // CAR_FACTORY_H_
