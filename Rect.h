#ifndef RECT_H
#define RECT_H


class Rect {
protected:
	float x;
	float y;

	float red;
	float green;
	float blue;

	float w;
	float h;

public:
	Rect();

	Rect(float, float, float, float);

	Rect(float, float, float, float, float r=0, float g=0, float b=0);

	Rect(const Rect&);

	bool operator== (const Rect&);

	virtual ~Rect(){}

	void draw();

	bool contains(float, float) const;

	void up();
	void left();
	void down();
	void right();


	float getX() const;

	float getY() const;

	float getW() const;

	float getH() const;

	float getR() const;

	float getG() const;

	float getB() const;

	void setX(float x);

	void setY(float y);

	void setW(float w);

	void setH(float h);

};

#endif

