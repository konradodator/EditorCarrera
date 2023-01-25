#pragma once
#include <GL/glew.h>
#include <iostream>

class Texture
{
private:
	unsigned int RenderID;
	std::string Pfad1;
	unsigned char* Buffer1;
		int Width1, Height1, BPP;
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot =0) const;
	void Unbind() const;

	inline int GetWidth() const { return Width1; } //Zu welchem Slot welche Textur
	inline int GetHeight() const { return Height1; }


};
