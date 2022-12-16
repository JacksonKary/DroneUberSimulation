#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IStrategy.h"

/**
 * @brief Celebration decorator class
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief Constructor for CelebrationDecorator
   * @param[in] strategy An IStrategy to be wrapped in a celebration decorator
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
   * @brief Moves the entity and/or celebrates
   * @param[in] entity An IEntity to move and/or celebrate
   * @param[in] dt The delta time that has passed
   */
  void Move(IEntity *entity, double dt);
  /**
   * @brief Checks whether the strategies are completed
   * @return Boolean representing if it is completed
   */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_
