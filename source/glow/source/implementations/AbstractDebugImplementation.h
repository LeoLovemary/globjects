#pragma once

#include <glbinding/types.h>

#include "../DebugMessageCallback.h"

namespace glow {

class DebugMessage;

class AbstractDebugImplementation
{
public:
    AbstractDebugImplementation();
    virtual ~AbstractDebugImplementation();

    static AbstractDebugImplementation * create();

    void setCallback(DebugMessageCallback::Callback callback);
    void addCallback(DebugMessageCallback::Callback callback);

    virtual bool isFallback();

    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual void setSynchronous(bool synchronous) = 0;

    virtual void insertMessage(const DebugMessage & message) = 0;

    virtual void controlMessages(gl::GLenum source, gl::GLenum type, gl::GLenum severity, gl::GLsizei count, const gl::GLuint * ids, gl::GLboolean enabled) = 0;
protected:
    DebugMessageCallback m_messageCallback;
};

} // namespace glow