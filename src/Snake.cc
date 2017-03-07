#include "Snake.h"

Snake::Snake(Punt p) {
	// Pre: cert
	// Post: el resultat es un objecte snake al punt p

	pMax = p;

}

Snake::~Snake(){
	// Accions del destructor
}

void Snake::addSnake(Punt p) {
	// Pre: cert
	// Post: Afegim nova serp que comença en el punt p

	snakes.push_back(p);
	++nSnakes;

}

void Snake::longSnake(Punt ext, int actualSnake) {
	// Pre: cert
	// Post: Allarguem una serp ja existent amb un punt

	snakes[actualSnake].allargar(ext);

}

float Snake::boardWidth() const {
	// Pre: cert
	// Post: El resultat de l'amplada del taulell

	return pMax.coordenadax();

}

float Snake::boardHeight() const {
	// Pre: cert
	// Post: El resultat de l'altura del taulell

	return pMax.coordenaday();

}

int Snake::totalSnakes() const {
	// Pre: cert
	// Post: El resultat de les serps totals al taulell

	return nSnake;

}

bool Snake::searchPoint(Punt p) const {
	// Pre: cert
	// Post: Donara true si el punt donat esta a l'interior de la frontera del rectangle

	bool interior = true;

	if (p.coordenadax() < 0 or p.coordenadax() > pMax.coordenadax()
			or p.coordenaday() < 0 or p.coordenaday() > pMax.coordenaday())		interior = false;

	return interior;

}

bool Snake::pointBusy(Punt p) const {
	// Pre: cert
	// Post: DonarÃ  true si el punt donat ja estÃ  ocupat per una serp al taulell

	bool ocupat = false;
	unsigned int i = 0;
	while (not ocupat and i < snakes.size()){
		unsigned int j = 0;
		while (not ocupat and j < snakes[i].size()){
			if (p == snakes[i][j])	ocupat = true;
		}
	}

	return ocupat;

}

Punt Snake::lastPoint(Snake s, int actualSnake) const {
	// Pre: cert
	// Post: el darrer punt d'una serp en concret

	return snakes[actualSnake].consultar_punt();

}

ostream& operator<<(ostream &os, const Punt &p){

	for (unsigned int i = p.coordenadax(); i > 0; --i){
		for (unsigned int j = p.coordenaday; j > 0 ; --j){

			if (i == 0 or j = 0 or i == p.coordenadax() or j = p.coordenaday()){
				os << "#";
			} else {
				bool punt = false;
				unsigned int k = 0;
				while(not punt and k < snakes.size()){
					unsigned int z = 0;
					while(not punt and z < snakes[k].size()){
						if (snakes[k][z] == Punt(i, j))		punt = true;
						else	++z;
					}
					++k;
				}

				if (punt){
					os << "*";
				} else {
					os << " ";
				}

			}

		}

		os << endl;

	}

	return os;

}

}
