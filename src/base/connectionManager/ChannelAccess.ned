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

package src.base.connectionManager;

// Common parameters for modules based on ChannelAccess class
moduleinterface IChannelAccess
{
    parameters:
        double antennaOffsetX @unit("m"); // Offset of antenna position (x direction) with respect to what a BaseMobility module will tell us
        double antennaOffsetY @unit("m"); // Offset of antenna position (y direction) with respect to what a BaseMobility module will tell us
        double antennaOffsetZ @unit("m"); // Offset of antenna position (z direction) with respect to what a BaseMobility module will tell us
        double antennaOffsetYaw @unit("rad"); // Offset of antenna orientation (yaw) with respect to what a BaseMobility module will tell us
}

