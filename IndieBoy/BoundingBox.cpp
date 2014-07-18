#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
	this->left = 0;
	this->right = 0;
	this->top = 0;
	this->bottom = 0;
}

BoundingBox::~BoundingBox()
{
}

void BoundingBox::setup(PresetBoundingBox bbox_type)
{
	if(bbox_type >= BOX_NUM_MAX) 
	{
		// Set default type
		left   = presets[0];
		top    = presets[1];
		right  = presets[2];
		bottom = presets[3];
		return;
	}
	
	int offset = bbox_type * 4;
	left   = presets[offset];
	top    = presets[offset+1];
	right  = presets[offset+2];
	bottom = presets[offset+3];
}

void BoundingBox::setup(int aleft, int atop, int aright, int abottom)
{
	this->left = aleft;
	this->top = atop;
	this->right = aright;
	this->bottom = abottom;
}

// Preset bounding boxes
int BoundingBox::presets[BOX_NUM_MAX*4] = {
	0, 0, 7, 7, 				// Solid 8x8 box
	0, 0, 15, 15, 				// Solid 16x16 box
	0, 0, 31, 31, 				// Solid 32x32 box
	0, 0, 15, 7,				// 16x8 box
	0, 0, 31, 7,				// 32x8 box
	0, 0, 31, 15,				// 32x16 box
	2, 4, 13, 15,				// Char 16
	4, 6, 20, 23,				// Char 24
	6, 8, 25, 31				// Char 31
};
