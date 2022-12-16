#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief Jump decorator class
 */
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor for JumpDecorator
   * @param[in] strategy An IStrategy to be wrapped in a jump decorator
   */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

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

#endif  // JUMP_DECORATOR_H_
