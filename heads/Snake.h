#include <iostream>
#include <vector>
#include "Cami.h"
using namespace std;

class Snake{
	// Tipus de modul: dades
	// Descripcio del tipus: Conte les variables i els metodes de la classe Snake

	private:
		// A la fase d'implementació i aniran els atributs privats
		vector<Cami> snakes;
		Bool crash;
		int nSnake = 0;

	public:
		// Constructors
		Snake();
			// Pre: cert
			// Post: el resultat es un objecte Snake amb els valors per defecte

		Snake(Punt p);
			// Pre: cert
			/* Post: el resultat es un objecte Snake que a partir del punt p, crea un conjunt buit
			 * de camins dins del rectangle de vèrtexs (0,0) i (p.x, p.y)
			*/

		// Destructors
		~Snake();
			// Post: esborra automàticament els objectes locals en sortir d'un àmbit de visibilitat

		// Modificadors
		void addSnake(Punt p);
			// Pre: cert
			// Post: Afegim una nova serp que comença en el punt p

		void longSnake(Punt s);
			// Pre: cert
			// Post: Allarguem una serp ja existent amb un punt

		// Consultors
		float boardWidth() const;
			// Pre: cert
			// Post: El resultat de l'amplada del taulell

		float boardHeight() const;
			// Pre: cert
			// Post: El resultat de l'altura del taulell

		int totalSnakes() const;
			// Pre: cert
			// Post: El resultat de les serps totals al taulell

		bool searchPoint(Punt p) const;
			// Pre: cert
			// Post: Donarà true si el punt donat està a l'interior de la frontera del rectangle

		bool pointBusy(Punt p) const;
			// Pre: cert
			// Post: Donarà true si el punt donat ja està ocupat per una serp al taulell

		Punt lastPoint(Snake s) const;
			// Pre: cert
			// Post: El darrer punt d'una serp en concret

		// Escriptura
		friend ostream& operator<<(ostream &os, const Snake &s);
		/* Pre: cert */
		/* Post: s'ha mostrat l'estat del joc pel canal de sortida estandard */
};
