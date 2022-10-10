/**
 * @file CloudCommunicationUnit.h
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

#include "src/messages/QueueStatusFrame_m.h"
#include "src/messages/RSUTaskSignalFrame_m.h"
#include "src/messages/CloudFeedbackFrame_m.h"

namespace test {

class CloudCommunicationUnit : public cSimpleModule{
private:
    std::vector<int> queuesStatus;
protected:
    /**
     * Initialize members and associated objects according to parameterization.
     */
    void initialize() override;

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
