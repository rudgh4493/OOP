#include "Rect.h"

Rect::Rect(int width, int height)
{
	this->width = width;
	this->height = height;
}
bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height)
		return true;
	else
		return false;
}