#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation.
 *  The model can communicate with the controller.
 */
class SimulationModel {
 public:
  /**
   * @brief SimulationModel Constructor - Simulations are created with a
   * controller.
   * @param[in] controller The IController controller for this SimulationModel.
   */
  SimulationModel(IController& controller);
  /**
   * @brief Sets the graph for this SimulationModel.
   * @param[in] graph The new IGraph* for this entity.
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Creates a simulation entity.
   * @param[in] entity The JsonObject entity for this SimulationModel.
   */
  void CreateEntity(JsonObject& entity);
  /**
   * @brief Schedules a trip for an object in the scene.
   * @param[in] details The JsonObject with the trip details.
   */
  void ScheduleTrip(JsonObject& details);
  /**
   * @brief Updates the simulation.
   * @param[in] dt The new double (distance ?) to update to.
   */
  void Update(double dt);
  /**
   * @brief Adds a factory for a new entity type to the simulation.
   * @param[in] factory The new IEntityFactory to add to the simulation.
   */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif  // SIMULATION_MODEL_H_
