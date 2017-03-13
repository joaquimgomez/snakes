#include "Snake.h"

Snake::Snake(Punt p) {
	// Pre: cert
	// Post: el resultat es un objecte snake al punt p

	pMax = p;

}

Snake::~Snake(){
	// Accions del destructor
}

void Snake::addSnake(Punt ext) {
	// Pre: cert
	// Post: Afegim nova serp que comença en el punt p

	snakes.push_back(Cami());
	snakes[nSnakes].allargar(ext);
	++nSnakes;

}

void Snake::longSnake(Punt ext, int actualSnake) {
	// Pre: cert
	// Post: Allarguem una serp ja existent amb un punt

	snakes[actualSnake].allargar(ext);

}

int Snake::boardWidth() const {
	// Pre: cert
	// Post: El resultat de l'amplada del taulell

	return pMax.coordenadax();

}

int Snake::boardHeight() const {
	// Pre: cert
	// Post: El resultat de l'altura del taulell

	return pMax.coordenaday();

}

int Snake::totalSnakes() const {
	// Pre: cert
	// Post: El resultat de les serps totals al taulell

	return nSnakes;

}

bool Snake::searchPoint(Punt p) const {
	// Pre: cert
	// Post: Donara true si el punt donat esta a l'interior de la frontera del rectangle

	bool interior = false;
	if (p.coordenadax() > 0 and p.coordenaday() > 0 and
			p.coordenadax() < pMax.coordenadax() and p.coordenaday() < pMax.coordenaday())	interior = true;

	cout << "interior: " << interior << endl;

	return interior;

}

bool Snake::pointBusy(Punt p) const {
	// Pre: cert
	// Post: DonarÃ  true si el punt donat ja estÃ  ocupat per una serp al taulell

	bool ocupat = false;
	unsigned int i = 0;
	while (not ocupat and i < snakes.size()){
		unsigned int j = 0;
		while (not ocupat and j < snakes[i].longitud()){
			if (p == snakes[i].consultar_punt(j))	ocupat = true;
		}
	}

	return ocupat;

}

Punt Snake::lastPoint(int actualSnake) const {
	// Pre: cert
	// Post: el darrer punt d'una serp en concret

	return snakes[actualSnake].consultar_punt(snakes[actualSnake].longitud() - 1);

}

ostream& operator<<(ostream &os, const Snake &s){

	for (unsigned int i = s.pMax.coordenadax(); i > 0; --i){
		for (unsigned int j = s.pMax.coordenaday(); j > 0; --j){

			bool punt = false;
			if (i == 1 or j == 1 or i == s.pMax.coordenadax() or j == s.pMax.coordenaday()){
				os << "#";
			} else {
				unsigned int k = 0;
				while(not punt and k < s.snakes.size()){
					unsigned int z = 0;
					while(not punt and z < s.snakes[k].longitud()){
						if (s.snakes[k].consultar_punt(z) == Punt(i, j))		punt = true;
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
