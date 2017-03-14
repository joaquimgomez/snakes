#include "Snake.h"

Snake::Snake(Punt p) {
	// Pre: cert
	// Post: el resultat es un objecte snake al punt p

	pMax = p;
	nSnakes = 0;

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
	if (p.coordenadax() < pMax.coordenadax() and p.coordenadax() > 0 and p.coordenaday() < pMax.coordenaday() and p.coordenaday() > 0)	interior = true;

	//cout << "interior: " << interior << endl;

	return interior;

}

bool Snake::pointBusy(Punt p) const {
	// Pre: cert
	// Post: Donara true si el punt donat ja estÃ  ocupat per una serp al taulell

	bool ocupat = false;
	unsigned int i = 0;
	while (not ocupat and i < nSnakes){
		if (snakes[i].conte_punt(p))	ocupat = true;
		else	++i;

	}

	//cout << "ocupat: " << ocupat << endl;

	return ocupat;

}

Punt Snake::lastPoint(int actualSnake) const {
	// Pre: cert
	// Post: el darrer punt d'una serp en concret

	return snakes[actualSnake].consultar_punt(snakes[actualSnake].longitud());

}

ostream& operator<<(ostream &os, const Snake &s){

	for (unsigned int j = 0; j <= s.pMax.coordenaday(); ++j){
		for (unsigned int i = 0; i <= s.pMax.coordenadax(); ++i){

			if (j == 0 or j == s.pMax.coordenaday() or i == 0 or i == s.pMax.coordenadax())		os << "#";
			else {

				if (s.pointBusy(Punt(i, j)))	os << "*";
				else		os << " ";

			}

		}

		os << endl;

	}

	return os;

}
