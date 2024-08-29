#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"
/**
 * @brief Composite factory class, holds different factories to call from
 */
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Create entity function to create the corresponding entity
   * @param[in] entity JsonObject reference containing details for the entity
   * @return Returns the created IEntity pointer
   */
  IEntity* CreateEntity(JsonObject& entity);
  /**
   * @brief Adds a factory to the vector of all factories - componentFactories
   * @param[in] factoryEntity Pointer to the factory object
   */
  void AddFactory(IEntityFactory* factoryEntity);
  /**
   * @brief Default deconstructor.
   */
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif  // COMPOSITE_FACTORY_H_
