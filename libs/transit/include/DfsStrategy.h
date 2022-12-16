#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief this class inhertis from the IStrategy class and is responsible
 * for generating the beeline that the drone will take.
 */
class DfsStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor
   * @param[in] position A Vector3 representing the initial position
   * @param[in] destination A Vector3 representing the final position
   * @param[in] graph An IGraph pointer that holds the graph
   */
  DfsStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Default destructor.
   */
  ~DfsStrategy();
  /**
   * @brief Moves the entity to the destination using the dfs strategy
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
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // DFS_STRATEGY_H_
