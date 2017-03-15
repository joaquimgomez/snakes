#include <iostream>
#include <vector>
#include "Cami.h"
using namespace std;

class Snakes{
	// Tipus de modul: dades
	// Descripcio del tipus: Conte les variables i els metodes de la classe Snake

	private:
		int nSnakes;	// Guarda el numero de serps
		vector<Cami> snakes;
		Punt pMax;

	public:
		// Constructors
		Snakes(Punt p);
			/* Pre: cert
				 Post: el resultat es un objecte Snake que a partir del punt p,
				 			 crea un conjunt buit de camins dins del rectangle de vèrtexs (0,0) i (p.x, p.y) */

		// Destructors
		~Snakes();
			/* Post: esborra automàticament els objectes locals en sortir d'un àmbit de visibilitat */

		// Modificadors
		void addSnake(Punt inicial);
			/* Pre: el punt inicial a afegir ha de esta compres en el rang (0,0) i (xmax, ymax); i no ha de estar
							ocupat per cap serp.
			 	Post: afegim una nova serp que comença en el punt inicial */

		void longSnake(Punt ext, int actualSnake);
			/* Pre: el punt ext que exten la serp ha de estar compres en el rang (0, 0) i (xmax, ymax); no ha de estar
							ocupat per cap serp i ha de ser un punt que la serp pugui agafar.
							La serp actual ha de estar compresa en el rang 0 <= actualSnake <= nSkanes.
				Post: allarguem una serp ja existent (actualSnake) amb el punt ext */

		// Consultors
		int boardWidth() const;
			/* Pre: cert
				 Post: retorn l'amplada del taulell */

		int boardHeight() const;
			/* Pre: cert
		 		 Post: retorna l'altura del taulell */

		int totalSnakes() const;
			/* Pre: cert
				 Post: retorna el nombre total de serps del taulell */

		bool searchPoint(Punt p) const;
			/* Pre: cert
				 Post: retornara true si el punt donat esta a l'interior de la frontera del rectangle */

		bool pointBusy(Punt p) const;
			/* Pre: cert
		 		 Post: retornata true si el punt donat ja està ocupat per una serp al taulell */

		Punt lastPoint(int actualSnake) const;
			/* Pre: actualSnake ha de estar compres entre 0 <= actualSnake <= nSnakes
			 	 Post: retorna el darrer punt d'una serp en concret */

		// Escriptura
		friend ostream& operator<<(ostream &os, const Snakes &s);
		/* Pre: cert
		 	 Post: es mostra l'estat del joc pel canal de sortida estandard */

};
