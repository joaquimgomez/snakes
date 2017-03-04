#include "Snake.h"

Snake::Snake() {
	// Pre: cert
	// Post: el resultat es un objecte snake al punt 0, 0
		
	c = Cami();
	crash = false;
	nSnake++;
}

Snake::Snake(Punt p) {
	// Pre: cert
	// Post: el resultat es un objecte snake al punt p
		
	c = Cami();
	crash = false;
	nSnake++;
}

Snake::~Snake(){
	// Accions del destructor
}

void Snake::addSnake(Punt p) {
	// Pre: cert
	// Post: Afegim nova serp que comença en el punt p
	
	Snake s = Snake(p);
}

void Snake::longSnake(Punt s) {
	// Pre: cert
	// Post: Allarguem una serp ja existent amb un punt
	
	c.punts[npunts] = s; 
	c.npunts++:
}

float Snake::boardWidth() const {
	// Pre: cert
	// Post: El resultat de l'amplada del taulell
	
	return c.punts[0,0].x;
}

float Snake::boardHeight() const {
	// Pre: cert
	// Post: El resultat de l'altura del taulell
	
	return c.punts[0,0].y;
}

int Snake::totalSnakes() const {
	// Pre: cert
	// Post: El resultat de les serps totals al taulell
	
	return nSnake;
}

bool Snake::searchPoint(Punt p) const {
	// Pre: cert
	// Post: Donarà true si el punt donat està a l'interior de la frontera del rectangle
	
	// CODIFICAR!
}

bool Snake::pointBusy(Punt p) const {
	// Pre: cert
	// Post: Donarà true si el punt donat ja està ocupat per una serp al taulell
	
	// CODIFICAR!
}

Punt Snake::lastPoint(Snake s) const {
	// Pre: cert
	// Post: el darrer punt d'una serp en concret
	
	return s.c.punts[s.c.npunts];
}




