#pragma once
class Rect;

class RectManager {
public: 
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height);

	friend bool equals(Rect r, Rect s);
	friend RectManager;
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height)
		return true;
	else
		return false;
}