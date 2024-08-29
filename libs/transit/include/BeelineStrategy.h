#ifndef BEELINE_H_
#define BEELINE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor
   * @param[in] position A Vector3 representing the initial position
   * @param[in] destination A Vector3 representing the final position
   */
  BeelineStrategy(Vector3 position, Vector3 destination);
  /**
   * @brief Destructor
   */
  ~BeelineStrategy();
  /**
   * @brief Moves the entity to the destination using the beeline strategy
   * @param[in] entity An IEntity object that is the entity being moved
   * @param[in] dt The delta time that has passed since last update
   */
  void Move(IEntity* entity, double dt);
  /**
   * @brief Checks whether the entity has reached the destination
   * @return A boolean that represents whether the entity reached its
   * destination
   */
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};      // end class
#endif  // BEELINE_H_
