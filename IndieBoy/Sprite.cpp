#include "Sprite.h"

Sprite::Sprite()
{
	c_frame = 0;
	n_frame = 0;
	framewidth = 0;
	frameheight = 0;
	speed = 1.0F;
	frame = 0.0F;
}

Sprite::~Sprite()
{
}

void Sprite::bind()
{
	if(tex) { sf::Texture::bind(tex); }
}

void Sprite::render(int x, int y)
{
	if(!tex) { return; }
	
	bind();
	glBegin(GL_QUADS);
		texCoord(0);
		glVertex2i(x,y);
		texCoord(1);
		glVertex2i(x+framewidth,y);
		texCoord(2);
		glVertex2i(x+framewidth,y+frameheight);
		texCoord(3);
		glVertex2i(x,y+frameheight);
	glEnd();
	
	frame += speed;
	if(frame >= 1.0F)
	{
		frame -= 1.0F;
		c_frame += 1;
		if(c_frame > n_frame-1) { c_frame = 0; }
	}
	else if(frame <= -1.0F)
	{
		frame += 1.0F;
		c_frame -= 1;
		if(c_frame < 0) { c_frame = n_frame-1; }
	}
}

void Sprite::setGraphic(sf::Texture* graphic, int width, int height)
{
	tex = graphic;
	if(tex == nullptr) { return; }
	
	framewidth = width > 0 ? width : tex->getSize().x;
	frameheight = height > 0 ? height : tex->getSize().y;
	
	hframes = tex->getSize().x / framewidth;
	vframes = tex->getSize().y / frameheight;
	n_frame = hframes*vframes;
	c_frame = 0;
}

void Sprite::texCoord(int n)
{
	int frame_x = c_frame % hframes;
	int frame_y = c_frame / hframes;
	float hdelta = 1.0F/hframes;
	float vdelta = 1.0F/vframes;
	if(n == 0) 
	{
		glTexCoord2f(hdelta*frame_x, vdelta*frame_y);
	}
	else if(n == 1) 
	{
		glTexCoord2f((hdelta*frame_x) + hdelta, vdelta*frame_y);
	}
	else if(n == 2) 
	{
		glTexCoord2f((hdelta*frame_x) + hdelta, (vdelta*frame_y) + vdelta);
	}
	else if(n == 3) 
	{
		glTexCoord2f(hdelta*frame_x, (vdelta*frame_y) + vdelta);
	}
}

int Sprite::getImage()
{
	return c_frame;
}

int Sprite::getMaxImage()
{
	return n_frame;
}

void Sprite::setImage(int index)
{
	c_frame = index;
	frame = 0.0F;
}
