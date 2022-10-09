//
// Copyright (C) 2006-2018 Christoph Sommer <sommer@ccs-labs.org>
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

/**
 * @mainpage %Veins - The open source vehicular network simulation framework.
 *
 * See the %Veins website <a href="http://veins.car2x.org/"> for a tutorial, documentation, and publications </a>.
 */

#pragma once

#include <memory>
#include <utility>

#include <omnetpp.h>

// Explicitly check OMNeT++ version number
#if OMNETPP_VERSION < 0x500
#error At least OMNeT++/OMNEST version 5.0.0 required
#endif

// Import whole omnetpp namespace
namespace omnetpp {
}
using namespace omnetpp;

// Convenience macros
#define RNGCONTEXT (cSimulation::getActiveSimulation()->getContext())->

/**
 * %Veins - The open source vehicular network simulation framework.
 */
namespace test {
#if (__cplusplus >= 201402L) || (defined __cpp_lib_make_unique)
using std::make_unique;
#else
/**
 * User-defined implementation of std::make_unique.
 *
 * Until Veins builds on C++14, this provides equivalent functionality.
 */
template <typename T, typename ... Args>
std::unique_ptr<T> make_unique(Args&& ... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif

template <typename T>
cModule* findModuleByPath(T modulePath)
{
#if OMNETPP_BUILDNUM < 1506
    try {
        return cSimulation::getActiveSimulation()->getModuleByPath(modulePath);
    }
    catch (cRuntimeError) {
        return nullptr;
    }
#else
    return cSimulation::getActiveSimulation()->findModuleByPath(modulePath);
#endif
}

#if OMNETPP_VERSION < 0x600
typedef long intval_t;
typedef unsigned long uintval_t;
#endif

} // namespace test
