/**
 * @file CommunicationUnit.cc
 * @author xu qiao (george.x.qiao@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "BaseCommunicationUnit.h"

using namespace test;

void BaseCommunicationUnit::initialize(int stage)
{
    ChannelAccess::initialize(stage);

    if (stage == 0) {
        recordStats = par("recordStats").boolValue();

        world = FindModule<BaseWorldUtility*>::findGlobalModule();
        if (world == nullptr) {
            throw cRuntimeError("Could not find BaseWorldUtility module");
        }
    }
}
