#ifndef SPRITE_H
#define SPRITE_H

// Sprite component

#include <SFML/Graphics.hpp>
#include <string>
#include <gl/gl.h>

class Sprite
{
private:
	int c_frame;
	int n_frame;
	int hframes;
	int vframes;
	float frame;
	
	sf::Texture* tex;
	int framewidth;
	int frameheight;
public:
	float 					speed;
	
							Sprite();
							~Sprite();
	
	void					setGraphic(sf::Texture* graphic, int width = 0, int height = 0);
	void					setImage(int index);
	int						getImage();
	int						getMaxImage();
	void					bind();
	void					texCoord(int n);
	void					render(int x, int y);
};

#endif // SPRITE_H
