#ifndef PONTO
#define PONTO

class Ponto {
public:
	int x;
	int y;

	void setarXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void setarXY(int xy) {
		this->x = xy;
		this->y = xy;
	}
};

#endif