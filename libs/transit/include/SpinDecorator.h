#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief Spin decorator class
 */
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor for SpinDecorator
   * @param[in] strategy An IStrategy to be wrapped in a spin decorator
   */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Checks whether the strategies are completed
   * @return Boolean representing if it is completed
   */
  bool IsCompleted();
  /**
   * @brief Moves the entity and/or celebrates
   * @param[in] entity An IEntity to move and/or celebrate
   * @param[in] dt The delta time that has passed
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // SPIN_DECORATOR_H_
