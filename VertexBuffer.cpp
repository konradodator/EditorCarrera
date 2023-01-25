#include "VertexBuffer.h"
#include <GL/glew.h>


VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &RenderID);
    glBindBuffer(GL_ARRAY_BUFFER, RenderID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);     //Anzahl vertecies
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &RenderID);
}

void VertexBuffer::Bind() const 
{
    glBindBuffer(GL_ARRAY_BUFFER, RenderID);
}

void VertexBuffer::Unbind() const 
{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
