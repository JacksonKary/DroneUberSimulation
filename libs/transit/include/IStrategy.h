#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

using namespace routing;
/**
 * @brief Strategy (routing) class
 */
class IStrategy {
 public:
  /**
   * @brief Moves the entity
   * @param[in] entity An IEntity to move
   * @param[in] dt The delta time that has passed
   */
  virtual void Move(IEntity* entity, double dt) = 0;

  /**
   * @brief Checks whether the strategy is completed
   * @return Boolean representing if it is completed
   */
  virtual bool IsCompleted() = 0;

 protected:
  // IGraph object to be used in the simulation.
  const IGraph* graph;
};  // close class

#endif  // ISTRATEGY_H_
