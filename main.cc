#include <iostream>
#include "Snake.h"
using namespace std;

int main(){
  Punt p;

  cout << "Amplada i altura rectangle: ";
  cin >> p;

  Snake s(p + Punt(-1,-1));


  char opcio;
  int serp_actual = 0;
  Punt p_nou;
  bool stop = false;

  while (not stop){
    cout << s;
    cout << "Opció: Allargar (a w d s), Nova (n), Canviar serp (enter): ";
    cin >> opcio;


    if ((opcio == 'a' or opcio == 'w' or opcio == 'd' or opcio == 's') and serp_actual >= 1){
      if (opcio == 'a')         p_nou = s.lastPoint(serp_actual-1) + Punt(-1,0);
      else if (opcio == 'w')    p_nou = s.lastPoint(serp_actual-1) + Punt(0,-1);
      else if (opcio == 'd')    p_nou = s.lastPoint(serp_actual-1) + Punt(1,0);
      else                      p_nou = s.lastPoint(serp_actual-1) + Punt(0,1);


      if (s.searchPoint(p_nou) and not s.pointBusy(p_nou))  s.longSnake(p_nou, serp_actual-1);
      else    stop = true;


    } else if (opcio == 'n'){
      cout << "Punt inicial: ";
      cin >> p_nou;


      if (s.searchPoint(p_nou) and not s.pointBusy(p_nou)){
        s.addSnake(p_nou);
        serp_actual = s.totalSnakes();
      } else    stop = true;


    } else if (opcio >= 49 and opcio <= 57 and serp_actual >= 1){
      if(int(opcio) <= s.totalSnakes())   serp_actual = int(opcio) - 1; // REVISAR!


    }

    cout << "Punt introduit: " << p_nou << endl;


  }


  if (stop)   cout << "Col·lisió al punt " << p_nou << endl;


}
