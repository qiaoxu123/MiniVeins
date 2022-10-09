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
#include "messages/QueueStatusFrame_m.h"
#include "messages/CloudFeedbackFrame_m.h"
#include "messages/CarPosUpdateFrame_m.h"
#include "messages/TaskFrame_m.h"
#include "messages/RSUTaskSignalFrame_m.h"

using namespace omnetpp;

namespace Test {

class RSU : public cSimpleModule {
private:
    cMessage* sendMessageEvent = nullptr;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;
};

Define_Module(RSU);

void RSU::initialize()
{
    sendMessageEvent = new cMessage("Send the message periodly");
    scheduleAt(0.1, sendMessageEvent);
}

void RSU::handleMessage(cMessage* msg)
{
    if (dynamic_cast<TaskFrame* >(msg)) {
        EV << "Have received the CarTaskFrame" << endl;

        char framename[20];
        sprintf(framename, "rsu%d-to-cloud", getIndex());

        // Create message object and set source and destination field.
        RSUTaskSignalFrame* frame = new RSUTaskSignalFrame(framename);
        frame->setTaskSize(10);
        send(frame, "upper$o");
    }
    else if (dynamic_cast<CarPosUpdateFrame* >(msg)) {
        EV << "Have received the RSUTaskSignalFrame" << endl;
    }
    else if (dynamic_cast<CloudFeedbackFrame*>(msg)) {
        EV << "Have received the CloudFeedbackFrame" << endl;
    }
    else {
//        EV << "Have received the cMessage" << endl;

        char framename[20];
        sprintf(framename, "rsu%d-to-cloud", getIndex());

        // Create message object and set source and destination field.
        QueueStatusFrame* frame = new QueueStatusFrame(framename);
        frame->setRsuID(getIndex());
        frame->setNumOfCPUs(5);
        frame->setQueueMaxLength(100);
        frame->setQueueCurrentLength(10);
        send(frame, "upper$o");

        scheduleAt(simTime() + 0.1, sendMessageEvent);
    }
}

} // namespace Test
