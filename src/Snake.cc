#include "Snake.h"

Snake::Snake() {
	// Pre: cert
	// Post: el resultat es un objecte snake al punt 0, 0
		
	crash = false;
	nSnake++;
	
	// snakes[nSnake].punts[nSnake].px
	// snakes[nSnake].punts[nSnake].py
}

Snake::Snake(Punt p) {
	// Pre: cert
	// Post: el resultat es un objecte snake al punt p
		
	crash = false;
	nSnake++;
	
	// snakes[nSnake].punts[nPunts].px = p.x
	// snakes[nSnake].punts[nPunts].py = p.y
}

Snake::~Snake(){
	// Accions del destructor
}

void Snake::addSnake(Punt p) {
	// Pre: cert
	// Post: Afegim nova serp que comenÃ§a en el punt p
	
	Snake s = Snake(p);
}

void Snake::longSnake(Punt s) {
	// Pre: cert
	// Post: Allarguem una serp ja existent amb un punt
	
	snakes[nSnake].punts[npunts] = s; 
	snakes[nSnake].npunts++;
}

float Snake::boardWidth() const {
	// Pre: cert
	// Post: El resultat de l'amplada del taulell
	
	return snakes[nSnake].punts[0,0].x;
}

float Snake::boardHeight() const {
	// Pre: cert
	// Post: El resultat de l'altura del taulell
	
	return snakes[nSnake].punts[0,0].y;
}

int Snake::totalSnakes() const {
	// Pre: cert
	// Post: El resultat de les serps totals al taulell
	
	return nSnake;
}

bool Snake::searchPoint(Punt p) const {
	// Pre: cert
	// Post: DonarÃ  true si el punt donat estÃ  a l'interior de la frontera del rectangle
	
	// CODIFICAR!
}

bool Snake::pointBusy(Punt p) const {
	// Pre: cert
	// Post: DonarÃ  true si el punt donat ja estÃ  ocupat per una serp al taulell
	
	// CODIFICAR!
}

Punt Snake::lastPoint(Snake s) const {
	// Pre: cert
	// Post: el darrer punt d'una serp en concret
	
	return s.snakes[nSnake].punts[s.snakes[nSnake].nPunts];
}




