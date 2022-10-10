/**
 * @file RSUCommunicationUnit.h
 * @author xu qiao (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/test.h"
#include "BaseCommunicationUnit.h"

#include "src/messages/TaskFrame_m.h"
#include "src/messages/RSUTaskSignalFrame_m.h"
#include "src/messages/CarPosUpdateFrame_m.h"
#include "src/messages/CloudFeedbackFrame_m.h"
#include "src/messages/QueueStatusFrame_m.h"

namespace test {

class RSUCommunicationUnit : public BaseCommunicationUnit {
private:
    cMessage* sendMessageEvent = nullptr;
protected:
    /**
     * Initialize members and associated objects according to parameterization.
     */
    void initialize(int stage) override;

    /**
     * Process received messages and pass to specific handlers.
     *
     * @see handleSelfMessage
     */
    void handleMessage(cMessage* msg) override;

    /**
     * Handle self scheduled messages.
     */
    virtual void handleSelfMessage(cMessage* msg);
};
} // namespace test
