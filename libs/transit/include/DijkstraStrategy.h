#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 */
class DijkstraStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor for the DijkstraStrategy class.
   *
   * @param position A Vector3 object holding the position coords of the drone.
   * @param destination A Vector3 object holding the destination coords of the
   * drone.
   * @param graph An IGraph object pointer for the graph.
   **/
  DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Deconstructor for the DijkstraStrategy class.
   **/
  ~DijkstraStrategy();
  /**
   * @brief Move function for the DijkstraStrategy class, moves the drone.
   *
   * @param entity An IEntity object pointer to the drone.
   * @param dt A double holding the delta time (time passed).
   **/
  void Move(IEntity* entity, double dt);
  /**
   * @brief IsCompleted function for the DijkstraStrategy class determines
   * whether the drone has arrived at its destination.
   *
   * @return bool true if the drone has arrived at destination, false if not.
   **/
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // Dijkstra_STRATEGY_H_
