#ifndef PONTO
#define PONTO

class Ponto {
public:
	int x;
	int y;
	
	Ponto() : Ponto(-1, -1) {}
	
	Ponto(int xy) : Ponto(xy, xy) {}
	
	Ponto(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

#endif