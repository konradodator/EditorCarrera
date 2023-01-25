#include "IndexBuffer.h"
#include <GL/glew.h>
#define ASSERT(x) if (!(x)) __debugbreak();

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : Counts(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    glGenBuffers(1, &RenderID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RenderID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);     //Anzahl vertecies
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &RenderID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RenderID);
}

void IndexBuffer::Unbind() const 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
