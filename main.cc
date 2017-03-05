#include <iostream>
#include <Snake>
using namespace std;

int main(){
  Punt p;

  cout << "Amplada i altura rectangle: "
  cin << p;

  Snake s(p);


  char opcio;
  int serp_actual = 0;
  bool stop = false;
  while (not stop){
    cout << s << endl;
    cout << "Opció: Allargar (a w d x), Nova (n), Canviar serp (enter): ";
    cin << opcio;


    if (opcio == 'a' or opcio == 'w' or opcio == 'd' or opcio == 'x'){

    } else if (opcio == n){
      Punt p_nou;

      cout << "Punt inicial: ";
      cin << p_nou;

      /* ? */ if(s.searchPoint() and not s.pointBusy())   s.addSnake(p_nou);
      /* Si se introduce en un punto donde ya hay serpiente debe parar,
         si el punto esta fuera de rango (?). */

      serp_actual = s.totalSnakes();


    } else if (opcio >= 49 and opcio <= 57){
      if(int(opcio) <= s.totalSnakes())   serp_actual = int(opcio);

    }

  }


}
