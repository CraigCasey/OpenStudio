/**********************************************************************
*  Copyright (c) 2008-2010, Alliance for Sustainable Energy.
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

#include <gtest/gtest.h>
#include <model/test/ModelFixture.hpp>
#include <model/CoolingTowerSingleSpeed.hpp>
#include <model/CoolingTowerSingleSpeed_Impl.hpp>
#include <model/AirLoopHVAC.hpp>
#include <model/PlantLoop.hpp>
#include <model/Node.hpp>
#include <model/Node_Impl.hpp>
#include <model/AirLoopHVACZoneSplitter.hpp>

using namespace openstudio::model;

//Test construction of the coil

TEST_F(ModelFixture,CoolingTowerSingleSpeed_CoolingTowerSingleSpeed)
{
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";

  ASSERT_EXIT ( 
  {  
    //create a model to use in testing this code.
    Model m;
    CoolingTowerSingleSpeed coolingTowerSingleSpeed(m);

    exit(0); 
  } ,
  ::testing::ExitedWithCode(0), "" );
}

TEST_F(ModelFixture,CoolingTowerSingleSpeed_addToNode) {
  Model m;
  CoolingTowerSingleSpeed testObject(m);

  AirLoopHVAC airLoop(m);

  Node supplyOutletNode = airLoop.supplyOutletNode();

  EXPECT_FALSE(testObject.addToNode(supplyOutletNode));
  EXPECT_EQ( (unsigned)2, airLoop.supplyComponents().size() );

  Node inletNode = airLoop.zoneSplitter().lastOutletModelObject()->cast<Node>();

  EXPECT_FALSE(testObject.addToNode(inletNode));
  EXPECT_EQ((unsigned)5, airLoop.demandComponents().size());

  PlantLoop plantLoop(m);
  supplyOutletNode = plantLoop.supplyOutletNode();
  EXPECT_TRUE(testObject.addToNode(supplyOutletNode));
  EXPECT_EQ( (unsigned)7, plantLoop.supplyComponents().size() );

  Node demandOutletNode = plantLoop.demandOutletNode();
  EXPECT_FALSE(testObject.addToNode(demandOutletNode));
  EXPECT_EQ( (unsigned)5, plantLoop.demandComponents().size() );

  CoolingTowerSingleSpeed testObjectClone = testObject.clone(m).cast<CoolingTowerSingleSpeed>();
  supplyOutletNode = plantLoop.supplyOutletNode();

  EXPECT_TRUE(testObjectClone.addToNode(supplyOutletNode));
  EXPECT_EQ( (unsigned)9, plantLoop.supplyComponents().size() );
}
