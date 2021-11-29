#include <iostream>
#include <vector>

using namespace std;

double nettoRechner(double gewinn, vector<double> steuersaetze, vector<double> bereichsgrenzen) {

    static double summeSteuer{0};
    double steuer{0};
    double freibetrag{11000};
    int sizeSteuersaetze = steuersaetze.size() - 1;
    int sizeBereichsgrenzen = bereichsgrenzen.size() - 1;


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
    const vector<double> vectBereichsgrenze{0, 11000, 18000, 31000, 60000, 90000, 1000000};

    cout << "Bitte geben Sie den zu versteuernden Gewinn ein:" << endl;
    cin >> bruttoGewinn;

    while (cin.fail() || bruttoGewinn <= 0) {
        cout << "Leider ist das keine gültige Zahl. Probieren Sie es nochmal:\n";

        cin.clear();

        cin.ignore(500, '\n');

        cin >> bruttoGewinn;
    }

    cout << "Der zu bezahlende Steuerbetrag auf Ihren Gewinn beträgt: "
         << nettoRechner(bruttoGewinn, vectSteuersaetzte, vectBereichsgrenze) << "€" << endl;
}
