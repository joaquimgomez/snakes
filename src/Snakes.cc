#include "Snakes.h"

Snakes::Snakes(Punt p) {
	/* Pre: cert
		 Post: el resultat es un objecte Snakes que a partir del punt p,
					 crea un conjunt buit de camins dins del rectangle de vèrtexs (0,0) i (p.x, p.y) */

	pMax = p;
	nSnakes = 0;

}

Snakes::~Snakes(){
	/* Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat */

}

void Snakes::addSnake(Punt ext) {
	/* Pre: el punt inicial a afegir ha de esta compres en el rang (0,0) i (xmax, ymax); i no ha de estar
					ocupat per cap serp.
		Post: afegim una nova serp que comença en el punt inicial */

	snakes.push_back(Cami());
	snakes[nSnakes].allargar(ext);
	++nSnakes;

}

void Snakes::longSnake(Punt ext, int actualSnake) {
	/* Pre: el punt ext que exten la serp ha de estar compres en el rang (0, 0) i (xmax, ymax), no ha de estar
					ocupat per cap serp i ha de ser un punt que la serp pugui agafar.
					La serp actual ha de estar compresa en el rang 0 <= actualSnake <= nSkanes.
		Post: allarguem una serp ja existent (actualSnake) amb el punt ext */

	snakes[actualSnake].allargar(ext);

}

int Snakes::boardWidth() const {
	/* Pre: cert
		 Post: retorn l'amplada del taulell */

	return pMax.coordenadax();

}

int Snakes::boardHeight() const {
	/* Pre: cert
		 Post: retorna l'altura del taulell */

	return pMax.coordenaday();

}

int Snakes::totalSnakes() const {
	/* Pre: cert
		 Post: retorna el nombre total de serps del taulell */

	return nSnakes;

}

bool Snakes::searchPoint(Punt p) const {
	/* Pre: cert
		 Post: retornara true si el punt donat esta a l'interior de la frontera del rectangle */

	bool interior = false;
	if (p.coordenadax() < pMax.coordenadax() and p.coordenadax() > 0 and p.coordenaday() < pMax.coordenaday() and p.coordenaday() > 0)	interior = true;

	return interior;

}

bool Snakes::pointBusy(Punt p) const {
	/* Pre: cert
		 Post: retornata true si el punt donat ja esta ocupat per una serp al taulell */

	bool ocupat = false;
	unsigned int i = 0;
	while (not ocupat and i < nSnakes){
		// Inv: s'han analitzat i posicions del vector de snakes i encara no s'ha trobat el punt p

		if (snakes[i].conte_punt(p))	ocupat = true;
		else	++i;

	}

	return ocupat;

}

Punt Snakes::lastPoint(int actualSnake) const {
	/* Pre: actualSnake ha de estar compres entre 0 <= actualSnake <= nSnakes
		 Post: retorna el darrer punt d'una serp en concret */

	return snakes[actualSnake].consultar_punt(snakes[actualSnake].longitud());

}

ostream& operator<<(ostream &os, const Snakes &s){
	/* Pre: cert
		 Post: es mostra l'estat del joc pel canal de sortida estandard */

	for (unsigned int j = 0; j <= s.pMax.coordenaday(); ++j){
		// Inv: s'ha tret pel canal estandard fins al punt y = j-1 per a 0 < j <= ymax

		for (unsigned int i = 0; i <= s.pMax.coordenadax(); ++i){
			// Inv: s'ha tret pel canal estandar fins al punt x = i i y = j-1 per a 0 < i <= xmax i 0 < j <=ymax

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
