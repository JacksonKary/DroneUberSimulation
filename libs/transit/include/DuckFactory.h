#ifndef LIBS_TRANSIT_INCLUDE_DUCKFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DUCKFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include <vector>
#include "Duck.h"
/**
 * @brief this class inhertis from the IEntityFactory class and makes the Duck entity.
 */
class DuckFactory : public IEntityFactory {
 public:
    /**
     * @brief This function creates the Duck entity
     * @param[in] entity JsonObject that represents info on the entity
     * @return An IEntity object that is a Duck 
     */
    IEntity* CreateEntity(JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_DUCKFACTORY_H_
