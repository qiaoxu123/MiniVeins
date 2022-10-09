/**
 * @file cloud.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>
#include <omnetpp.h>
#include "messages/QueueStatusFrame_m.h"
#include "messages/RSUTaskSignalFrame_m.h"
#include "messages/CloudFeedbackFrame_m.h"

using namespace omnetpp;

namespace Test {

class Cloud : public cSimpleModule {
private:
    std::vector<int> queuesStatus;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;
};

Define_Module(Cloud);

void Cloud::initialize()
{
    queuesStatus.resize(par("numOfRSUs"));
    EV << "Test" << endl;
}

void Cloud::handleMessage(cMessage* frame)
{
    if (dynamic_cast<QueueStatusFrame* >(frame)) {
        EV << "Have received the QueueStatusFrame" << endl;
    }
    else if (dynamic_cast<RSUTaskSignalFrame* >(frame)) {
        EV << "Have received the RSUTaskSignalFrame" << endl;
    }
    else {
        EV << "Have received the cMessage" << endl;
    }
}

} // namespace Test
