//
// Generated file, do not edit! Created by opp_msgtool 6.0 from messages/QueueStatusFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "QueueStatusFrame_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(QueueStatusFrame)

QueueStatusFrame::QueueStatusFrame(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

QueueStatusFrame::QueueStatusFrame(const QueueStatusFrame& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

QueueStatusFrame::~QueueStatusFrame()
{
}

QueueStatusFrame& QueueStatusFrame::operator=(const QueueStatusFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void QueueStatusFrame::copy(const QueueStatusFrame& other)
{
    this->rsuID = other.rsuID;
    this->numOfCPUs = other.numOfCPUs;
    this->queueMaxLength = other.queueMaxLength;
    this->queueCurrentLength = other.queueCurrentLength;
}

void QueueStatusFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->rsuID);
    doParsimPacking(b,this->numOfCPUs);
    doParsimPacking(b,this->queueMaxLength);
    doParsimPacking(b,this->queueCurrentLength);
}

void QueueStatusFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->rsuID);
    doParsimUnpacking(b,this->numOfCPUs);
    doParsimUnpacking(b,this->queueMaxLength);
    doParsimUnpacking(b,this->queueCurrentLength);
}

int QueueStatusFrame::getRsuID() const
{
    return this->rsuID;
}

void QueueStatusFrame::setRsuID(int rsuID)
{
    this->rsuID = rsuID;
}

int QueueStatusFrame::getNumOfCPUs() const
{
    return this->numOfCPUs;
}

void QueueStatusFrame::setNumOfCPUs(int numOfCPUs)
{
    this->numOfCPUs = numOfCPUs;
}

int QueueStatusFrame::getQueueMaxLength() const
{
    return this->queueMaxLength;
}

void QueueStatusFrame::setQueueMaxLength(int queueMaxLength)
{
    this->queueMaxLength = queueMaxLength;
}

int QueueStatusFrame::getQueueCurrentLength() const
{
    return this->queueCurrentLength;
}

void QueueStatusFrame::setQueueCurrentLength(int queueCurrentLength)
{
    this->queueCurrentLength = queueCurrentLength;
}

class QueueStatusFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_rsuID,
        FIELD_numOfCPUs,
        FIELD_queueMaxLength,
        FIELD_queueCurrentLength,
    };
  public:
    QueueStatusFrameDescriptor();
    virtual ~QueueStatusFrameDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(QueueStatusFrameDescriptor)

QueueStatusFrameDescriptor::QueueStatusFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(QueueStatusFrame)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

QueueStatusFrameDescriptor::~QueueStatusFrameDescriptor()
{
    delete[] propertyNames;
}

bool QueueStatusFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<QueueStatusFrame *>(obj)!=nullptr;
}

const char **QueueStatusFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *QueueStatusFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int QueueStatusFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int QueueStatusFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_rsuID
        FD_ISEDITABLE,    // FIELD_numOfCPUs
        FD_ISEDITABLE,    // FIELD_queueMaxLength
        FD_ISEDITABLE,    // FIELD_queueCurrentLength
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *QueueStatusFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "rsuID",
        "numOfCPUs",
        "queueMaxLength",
        "queueCurrentLength",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int QueueStatusFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "rsuID") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numOfCPUs") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "queueMaxLength") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "queueCurrentLength") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *QueueStatusFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_rsuID
        "int",    // FIELD_numOfCPUs
        "int",    // FIELD_queueMaxLength
        "int",    // FIELD_queueCurrentLength
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **QueueStatusFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *QueueStatusFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int QueueStatusFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void QueueStatusFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'QueueStatusFrame'", field);
    }
}

const char *QueueStatusFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string QueueStatusFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        case FIELD_rsuID: return long2string(pp->getRsuID());
        case FIELD_numOfCPUs: return long2string(pp->getNumOfCPUs());
        case FIELD_queueMaxLength: return long2string(pp->getQueueMaxLength());
        case FIELD_queueCurrentLength: return long2string(pp->getQueueCurrentLength());
        default: return "";
    }
}

void QueueStatusFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        case FIELD_rsuID: pp->setRsuID(string2long(value)); break;
        case FIELD_numOfCPUs: pp->setNumOfCPUs(string2long(value)); break;
        case FIELD_queueMaxLength: pp->setQueueMaxLength(string2long(value)); break;
        case FIELD_queueCurrentLength: pp->setQueueCurrentLength(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueueStatusFrame'", field);
    }
}

omnetpp::cValue QueueStatusFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        case FIELD_rsuID: return pp->getRsuID();
        case FIELD_numOfCPUs: return pp->getNumOfCPUs();
        case FIELD_queueMaxLength: return pp->getQueueMaxLength();
        case FIELD_queueCurrentLength: return pp->getQueueCurrentLength();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'QueueStatusFrame' as cValue -- field index out of range?", field);
    }
}

void QueueStatusFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        case FIELD_rsuID: pp->setRsuID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numOfCPUs: pp->setNumOfCPUs(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_queueMaxLength: pp->setQueueMaxLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_queueCurrentLength: pp->setQueueCurrentLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueueStatusFrame'", field);
    }
}

const char *QueueStatusFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr QueueStatusFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void QueueStatusFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    QueueStatusFrame *pp = omnetpp::fromAnyPtr<QueueStatusFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueueStatusFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

