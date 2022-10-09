/**
 * @file car.cc
 * @author xu qiao (george.x.qiao@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <omnetpp.h>
#include "messages/TaskFrame_m.h"
#include "src/test.h"
#include "src/base/connectionManager/ChannelAccess.h"

using namespace omnetpp;

namespace Test {

class ChannelAccess;

class Car : public cSimpleModule {

private:
    cMessage* sendMessageEvent = nullptr;

protected:
    virtual void uploadFrame();
    void initialize(int stage) override;
    void handleMessage(cMessage* msg) override;
};
} // namespace Test
