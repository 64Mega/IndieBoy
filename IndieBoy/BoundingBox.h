#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

enum PresetBoundingBox
{
	BOX_8X8 = 0,
	BOX_16X16,
	BOX_32X32,
	BOX_16X8,
	BOX_32X8,
	BOX_32X16,
	BOX_CHAR_16,
	BOX_CHAR_24,
	BOX_CHAR_32,
	BOX_NUM_MAX
};

class BoundingBox
{
private:
	static int presets[BOX_NUM_MAX*4];
public:

	int left;
	int top;
	int right;
	int bottom;

									BoundingBox();
									~BoundingBox();
	
	void							setup(int aleft, int atop, int aright, int abottom);
	void							setup(PresetBoundingBox bbox_type);
};

#endif // BOUNDINGBOX_H
