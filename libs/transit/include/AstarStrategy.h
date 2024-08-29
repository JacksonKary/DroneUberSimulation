#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 */
class AstarStrategy : public IStrategy {
 public:
  /** @brief Constructor for the AstarStrategy class
   *  @param[in] position A vector3 object holding
   *                the position coords of the drone
   *  @param[in] destination A vector3 object
   *                holding the destination coords of the drone
   *  @param[in] graph A IGraph object pointer
   *                pointing to the graph
   **/
  AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destructor for the AstarStrategy class
   **/
  ~AstarStrategy();
  /** @brief Move function for the AstarStrategy class
   *  @param[in] entity an IEntity object
   *               pointer to the drone
   *  @param[in] dt delta time, or time
   *         since the last update() was called
   **/
  void Move(IEntity* entity, double dt);
  /** @brief function returns whether the move
   *         was completed or not
   * @return bool true if completed move,
   *         otherwise false
   **/
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // ASTAR_STRATEGY_H_
