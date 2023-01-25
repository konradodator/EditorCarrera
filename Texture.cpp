#include "Texture.h"
#include <GL/glew.h>
#include "stb_image/stb_image.h"

Texture::Texture(const std::string& path)
	:RenderID(0), Pfad1(path), Buffer1(nullptr), Width1(0), Height1(0), BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	Buffer1 = stbi_load(path.c_str(), &Width1, &Height1, &BPP, 4);

	glGenTextures(1, &RenderID);
	glBindTexture(GL_TEXTURE_2D, RenderID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, Width1, Height1, 0, GL_RGBA, GL_UNSIGNED_BYTE, Buffer1);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (Buffer1)
		stbi_image_free(Buffer1);
}

Texture::~Texture()
{
	glDeleteTextures(1, &RenderID);
}

void Texture::Bind(unsigned int slot) const 
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, RenderID);

}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);

}