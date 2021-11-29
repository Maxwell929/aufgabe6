#include <iostream>
#include <vector>

using namespace std;

double nettoRechner(double gewinn, vector<double> steuersaetze, vector<double> bereichsgrenzen) {

    static double summeSteuer{0.00};
    double steuer{0.00};
    double freibetrag{11000.00};
    int sizeSteuersaetze = size(steuersaetze) - 1;
    int sizeBereichsgrenzen = size(bereichsgrenzen) - 1;


    if (gewinn <= freibetrag) {
        return summeSteuer;
    } else if (gewinn > freibetrag) {
        if (gewinn > bereichsgrenzen[sizeBereichsgrenzen]) {
            steuer = (gewinn - bereichsgrenzen[sizeBereichsgrenzen]) * steuersaetze[sizeSteuersaetze];
            gewinn = gewinn - (gewinn - bereichsgrenzen[sizeBereichsgrenzen]);
            summeSteuer += steuer;
        }
    }


    steuersaetze.pop_back();
    bereichsgrenzen.pop_back();

    return nettoRechner(gewinn, steuersaetze, bereichsgrenzen);


}


int main() {
    double bruttoGewinn{0};
    const vector<double> vectSteuersaetzte{0.00, 0.25, 0.35, 0.42, 0.48, 0.50, 0.55};
    const vector<double> vectBereichsgrenze{0.00, 11000.00, 18000.00, 31000.00, 60000.00, 90000.00, 1000000.00};


    cout << nettoRechner(bruttoGewinn, vectSteuersaetzte, vectBereichsgrenze) << endl;

}
