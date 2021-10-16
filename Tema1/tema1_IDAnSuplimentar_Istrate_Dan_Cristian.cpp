#include <iostream>
#include <string>
using namespace std;

class Inel {
private:
	int codProdus;
	float gramaj;
	string tipMetal;
	bool deLogodna;
	char calitate;
public: 
	void setcodProdus(int codProdus){
		this->codProdus = codProdus;
	}
	int getcodProdus() {
		return this->codProdus;
	}
	void setgramaj (float gramaj){
		this->gramaj = gramaj;
	}
	float getgramaj() {
		return this->gramaj;
	}
	void settipMetal(string tipMetal) {
		this->tipMetal = tipMetal;
	}
	string gettipMetal() {
		return this->tipMetal;
	}
	void setdeLogodna(bool deLogodna) {
		this->deLogodna = deLogodna;
	}
	bool getdelogodna() {
		return this->deLogodna;
	}
	void setcalitate(char calitate) {
		this->calitate = calitate;
	}
	char getcalitate() {
		return this->calitate;
	}
	Inel() {
		this->codProdus = 0;
		this->gramaj = 0;
		this->tipMetal = "";
		this->deLogodna = 0;
		this->calitate = 'A';
	}
	Inel(int codProdus, float gramaj, string tipMetal, bool deLogodna, char calitate) {
		this->codProdus = codProdus;
		this->gramaj = gramaj;
		this->tipMetal = tipMetal;
		this->deLogodna = deLogodna;
		this->calitate = calitate;
	}
	//constructor pentru inele cu 15 gr de aur cu diamanant de calitate A
	Inel(int codProdus, bool deLogodna) {
		this->codProdus = codProdus;
		this->gramaj = 15;
		this->tipMetal = "aur";
		this->deLogodna = deLogodna;
		this->calitate = 'A';
	}
	void tiparesteInel() {
		if (this->deLogodna)
			cout << " Inelul de logodna cu codul " << this->codProdus<< " contine " << this->gramaj << " grame de " << this->tipMetal << " si are diamant de calitate " << this->calitate;
		else
			cout << " Inelul cu codul " << this->codProdus << " contine " << this->gramaj << " grame de " << this->tipMetal << " si are diamant de calitate " << this->calitate;
	}
};



class CutieInel {
private:
	int codProdus;
public:
	string culoare;
	string* material;
	bool inStoc;
	float pret;
	Inel ring;
	void setcodProdus(int codProdus) {
		this->codProdus = codProdus;
	}
	int getcodProdus() {
		return this->codProdus;
	}
	string getculoare() {
		return this->culoare;
	}
	int getinStoc() {
		return this->inStoc;
	}
	 Inel getRing() {
		return(this->ring);
	}

	CutieInel() {
		this->codProdus = 0;
		this->culoare = "";
		this->inStoc = 0;
		this->material = nullptr;
		this->pret = 0;
		this->ring = Inel();
	}
	CutieInel(int codProdus, string culoare, string material, bool inStoc, float pret, Inel ring) {
		this->codProdus = codProdus;
		this->culoare = culoare;
		this->inStoc = inStoc;
		this->material = &material;
		this->pret = pret;
		this->ring = ring;
	}
	//constructor cutie inel ce nu e pe stoc
	CutieInel(int codProdus, string culoare, string material) {
		this->codProdus = codProdus;
		this->culoare = culoare;
		this->inStoc = 0;
		this->material = &material;
		this->pret = 0;
		this->ring = Inel();
	}
	//constructor cutie standard pentru orice inel
	CutieInel(Inel i1) {
		this->codProdus = 999;
		this->culoare = "Burgund";
		this->inStoc = 1;
		this->material = nullptr;
		this->pret = 100;
		this->ring = i1;
	}
};



void tiparesteCutie(CutieInel c1, Inel i1){
	if (c1.getinStoc()) {
		cout << "\n Cutia cu codul " << c1.getcodProdus() << " e in stoc si contine "; 
		i1.tiparesteInel();
	}
	else
		cout << "\n Cutia cu codul " << c1.getcodProdus() << " nu e in stoc";
}
void main(){
	Inel i1 = Inel();
	Inel i2 = Inel(101, 9, "argint", 0, 'A');
	Inel i3 = Inel(102, 1);
	i1.setcodProdus(100);
	i1.setgramaj(10.5);
	i1.settipMetal("platina");
	i1.setcalitate('B');
	i1.setdeLogodna(1);
	i3.tiparesteInel();
	//CutieInel c1;
	//i1.tiparesteInel();
	CutieInel c1 = CutieInel(1010, "Albastru", "Catifea",1,112, i1);
	tiparesteCutie(c1, c1.ring);
	CutieInel c2 = CutieInel(1020, "Verde", "Catifea");
	tiparesteCutie(c2, c2.ring);
	CutieInel c3; 
	string material = "Panza Cuba";
	c3.setcodProdus(1030);
	c3.culoare = "Bleuciel";
	c3.inStoc = 0;
	c3.material = &material;
	c3.pret = 251;
	tiparesteCutie(c3, c3.ring);
	CutieInel c4 = CutieInel(i3);
	tiparesteCutie(c4, c4.ring);
	   	
}