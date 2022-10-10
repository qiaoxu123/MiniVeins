//
// Copyright (C) 2006-2016 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include "src/test.h"

#include "src/modules/mobility/traci/TraCIScenarioManager.h"
#include "src/modules/mobility/traci/TraCILauncher.h"

namespace test {

/**
 * @brief
 *
 * Extends the TraCIScenarioManager to automatically fork an instance of SUMO when needed.
 *
 * All other functionality is provided by the TraCIScenarioManager.
 *
 * See the Veins website <a href="http://veins.car2x.org/"> for a tutorial, documentation, and publications </a>.
 *
 * @author Christoph Sommer, Florian Hagenauer
 *
 * @see TraCIMobility
 * @see TraCIScenarioManager
 *
 */
class TraCIScenarioManagerForker : virtual public TraCIScenarioManager {
public:
    TraCIScenarioManagerForker();
    ~TraCIScenarioManagerForker() override;
    void initialize(int stage) override;
    void finish() override;

protected:
    std::string commandLine; /**< command line for running TraCI server (substituting $configFile, $seed, $port) */
    std::string command; /**< substitution for $command parameter */
    std::string configFile; /**< substitution for $configFile parameter */
    int seed; /**< substitution for $seed parameter (-1: current run number) */

    TraCILauncher* server;

    virtual void startServer();
    virtual void killServer();
    int getPortNumber() const override;
};

class TraCIScenarioManagerForkerAccess {
public:
    TraCIScenarioManagerForker* get()
    {
        return FindModule<TraCIScenarioManagerForker*>::findGlobalModule();
    };
};
} // namespace test
