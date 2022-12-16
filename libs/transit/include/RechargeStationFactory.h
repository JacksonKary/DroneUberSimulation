#ifndef RECHARGE_STATION_FACTORY_H_
#define RECHARGE_STATION_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RechargeStation.h"

/**
 * @brief RechargeStationFactory class to make recharge stations
 */
class RechargeStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Default deconstructor.
   */
  virtual ~RechargeStationFactory() {}
  /**
   * @brief Create entity function to create the corresponding entity
   * @param[in] entity JsonObject reference containing details for the entity
   * @return Returns the created IEntity pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // RECHARGE_STATION_FACTORY_H_
