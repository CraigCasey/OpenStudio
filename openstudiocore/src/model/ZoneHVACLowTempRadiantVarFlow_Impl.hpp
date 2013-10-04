/**********************************************************************
 *  Copyright (c) 2008-2013, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef MODEL_ZONEHVACLOWTEMPRADIANTVARFLOW_IMPL_HPP
#define MODEL_ZONEHVACLOWTEMPRADIANTVARFLOW_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/Surface.hpp>
#include <model/Surface_Impl.hpp>
#include <model/ZoneHVACComponent_Impl.hpp>

namespace openstudio {
namespace model {

class Schedule;
class HVACComponent;

namespace detail {

  /** ZoneHVACLowTempRadiantVarFlow_Impl is a ZoneHVACComponent_Impl that is the implementation class for ZoneHVACLowTempRadiantVarFlow.*/
  class MODEL_API ZoneHVACLowTempRadiantVarFlow_Impl : public ZoneHVACComponent_Impl {

  Q_OBJECT

  public:
    /** @name Constructors and Destructors */
    //@{

    ZoneHVACLowTempRadiantVarFlow_Impl(const IdfObject& idfObject,
                                       Model_Impl* model,
                                       bool keepHandle);

    ZoneHVACLowTempRadiantVarFlow_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                       Model_Impl* model,
                                       bool keepHandle);

    ZoneHVACLowTempRadiantVarFlow_Impl(const ZoneHVACLowTempRadiantVarFlow_Impl& other,
                                       Model_Impl* model,
                                       bool keepHandle);

    virtual ~ZoneHVACLowTempRadiantVarFlow_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual ModelObject clone(Model model) const;
    
    virtual std::vector<IdfObject> remove();
    
    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const;
    
    virtual std::vector<ModelObject> children() const;

    virtual unsigned inletPort();

    virtual unsigned outletPort();

    //@}
    /** @name Getters */
    //@{

    Schedule availabilitySchedule() const;
    
    HVACComponent heatingCoil() const;

    HVACComponent coolingCoil() const;

    boost::optional<std::string> radiantSurfaceType() const;

    std::vector<Surface> surfaces() const;

    double hydronicTubingInsideDiameter() const;

    bool isHydronicTubingInsideDiameterDefaulted() const;

    boost::optional<double> hydronicTubingLength() const;

    bool isHydronicTubingLengthDefaulted() const;

    bool isHydronicTubingLengthAutosized() const;

    std::string temperatureControlType() const;

    bool isTemperatureControlTypeDefaulted() const;

    std::string numberofCircuits() const;

    double circuitLength() const;

    //@}
    /** @name Setters */
    //@{

    bool setAvailabilitySchedule(Schedule& schedule);
    
    bool setHeatingCoil(HVACComponent& heatingCoil);

    bool setCoolingCoil(HVACComponent& coolingCoil);

    bool setRadiantSurfaceType(boost::optional<std::string> radiantSurfaceType);

    void resetRadiantSurfaceType();

    bool setHydronicTubingInsideDiameter(double hydronicTubingInsideDiameter);

    void resetHydronicTubingInsideDiameter();

    bool setHydronicTubingLength(boost::optional<double> hydronicTubingLength);

    void resetHydronicTubingLength();

    void autosizeHydronicTubingLength();

    bool setTemperatureControlType(std::string temperatureControlType);

    void resetTemperatureControlType();

    bool setNumberofCircuits(std::string numberofCircuits);

    void setCircuitLength(double circuitLength);
    
    boost::optional<ThermalZone> thermalZone() const;

    bool addToThermalZone(ThermalZone & thermalZone);

    void removeFromThermalZone();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.ZoneHVACLowTempRadiantVarFlow");

    boost::optional<Schedule> optionalAvailabilitySchedule() const;
    boost::optional<HVACComponent> optionalHeatingCoil() const;
    boost::optional<HVACComponent> optionalCoolingCoil() const;
    
    std::vector<std::string> radiantSurfaceTypeValues() const;
    std::vector<std::string> temperatureControlTypeValues() const;

  };

} // detail

} // model
} // openstudio

#endif // MODEL_ZONEHVACLOWTEMPRADIANTVARFLOW_IMPL_HPP

