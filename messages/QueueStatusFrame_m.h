//
// Generated file, do not edit! Created by opp_msgtool 6.0 from messages/QueueStatusFrame.msg.
//

#ifndef __QUEUESTATUSFRAME_M_H
#define __QUEUESTATUSFRAME_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class QueueStatusFrame;
/**
 * Class generated from <tt>messages/QueueStatusFrame.msg:2</tt> by opp_msgtool.
 * <pre>
 * message QueueStatusFrame
 * {
 *     int rsuID;
 *     int numOfCPUs;
 *     int queueMaxLength;
 *     int queueCurrentLength;
 * }
 * </pre>
 */
class QueueStatusFrame : public ::omnetpp::cMessage
{
  protected:
    int rsuID = 0;
    int numOfCPUs = 0;
    int queueMaxLength = 0;
    int queueCurrentLength = 0;

  private:
    void copy(const QueueStatusFrame& other);

  protected:
    bool operator==(const QueueStatusFrame&) = delete;

  public:
    QueueStatusFrame(const char *name=nullptr, short kind=0);
    QueueStatusFrame(const QueueStatusFrame& other);
    virtual ~QueueStatusFrame();
    QueueStatusFrame& operator=(const QueueStatusFrame& other);
    virtual QueueStatusFrame *dup() const override {return new QueueStatusFrame(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getRsuID() const;
    virtual void setRsuID(int rsuID);

    virtual int getNumOfCPUs() const;
    virtual void setNumOfCPUs(int numOfCPUs);

    virtual int getQueueMaxLength() const;
    virtual void setQueueMaxLength(int queueMaxLength);

    virtual int getQueueCurrentLength() const;
    virtual void setQueueCurrentLength(int queueCurrentLength);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const QueueStatusFrame& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, QueueStatusFrame& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline QueueStatusFrame *fromAnyPtr(any_ptr ptr) { return check_and_cast<QueueStatusFrame*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __QUEUESTATUSFRAME_M_H

