//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
package src.nodes;

import src.base.modules.*;
import src.base.communicationUnit.CarCommunicationUnit;

module Car
{
    parameters:
        @display("i=node/car");
        string veinsmobilityType = default("src.modules.mobility.traci.TraCIMobility"); //type of the mobility module
    submodules:        
        veinsmobility: <veinsmobilityType> like src.base.modules.IMobility {
            parameters:
                @display("p=130,172;i=node/car");
        }
    connections:
}