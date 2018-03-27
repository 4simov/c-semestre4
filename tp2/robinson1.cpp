#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Clause
{
	private:
		int capa;  //taille du tableau tab
		int n;     //nombre de litt�raux
		int* tab;  //tableau contenant les litt�raux

		/*!
		* V�rifie si un litt�ral est dans la clause courante.
		* \param lit : litt�ral � rechercher
		* \return 1 si lit est dans la clause courante, -1 si -lit est dans la
		* clause courante, 0 sinon.
		*/
		int isin(int lit);

		/*!
		* Agrandit si n�cessaire le tableau de stockage de la clause courante.
		* \param newcapa : nouvelle capacit�. Si la nouvelle capacit� est inf�rieure
		* � l'ancienne, l'ancienne capacit� est conserv�e et aucune action n'est
		* r�alis�e.
		* \param dup : si VRAI alors le contenu de l'ancien tableau de stockage est
		* dupliqu� dans le nouveau (si applicable), sinon, l'ancien contenu est perdu.
		*/
		void agrandir(int newcapa, bool dup);

	public:

		/*!
		* Constructeur pa d�faut : cr�e une clause vide da capacit� 2.
		*/
		Clause();

		/*!
		* Constructeurs pour cas particuliers (clauses unaires, binaire, ternaire)
		* \param w1 : premier litt�ral
		* \param w2 : second litt�ral
		* \param w3 : troisi�me litt�ral
		*/
		Clause(int w1); Clause(int w1, int w2); Clause(int w1, int w2, int w3);

		/*!
		* Destruction compl�te d'une instance de Clause
		*/
		~Clause();

		/*!
		* Constructeur en copie. Cr�e une nouvelle clause identique � l'instance de
		* r�f�rence.
		* \param model : instance de r�f�rence
		*/
		Clause(const Clause& model);

		/*!
		* Surcharge de l'op�rateur d'affectation. Apr�s ex�cution, L'instance de
		* destination contient les m�me litt�raux que l'instance source, mais peut avoir
		* une plus grande capacit�.
		* \param model : instance source
		* \return une r�f�rence � l'instance de destination
		*/
		Clause& operator=(const Clause& model);

		/*!
		* Si le litt�ral lit est d�j� dans la clause courante, cette m�thode est sans effet.
		* Si la n�gation de ce litt�ral est dans la clause courante, un message d'erreur est
		* affich�.
		* Sinon lit est ajout� � la clause courante.
		*\param lit : litt�ral � ajouter
		*/
		void add(int lit);

		/*!
		* Affiche la clause courante sur la sortie standard.
		*/
		void affiche();

		int resolve( this, Clause * c );
};//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Clause::Clause()
{
    /*01*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=2;
	n=0;
	tab = new int[capa];
	/*02*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
}

Clause::Clause(int w)
{
    /*03*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=1;
	n=1;
	tab = new int[capa];
	/*04*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
	tab[0]=w;
}

Clause::Clause(int w1, int w2)
{
    /*05*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=2;
	n=2;
	tab = new int[capa];
	/*06*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
	tab[0]=w1; tab[1]=w2;
}

Clause::Clause(int w1, int w2, int w3)
{
    /*07*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=3;
	n=3;
	tab = new int[capa];
	/*08*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
	tab[0]=w1; tab[1]=w2; tab[2]=w3;
}

Clause::~Clause()
{
    /*09*/printf("-tableau<%p>\n",tab);
    delete[] tab;
    /*10*/printf("-Clause<%p>\n",this);
}

Clause::Clause(const Clause& model)
{
	/*11*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
    capa=model.capa;
    n=model.n;
    tab = new int[capa];
	/*12*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
    for(int i=0; i<n; i++)
        tab[i]=model.tab[i];
}

Clause& Clause::operator=(const Clause& model)
{
    n=model.n;
    agrandir(model.capa,false);
    for(int i=0; i<n; i++)
        tab[i]=model.tab[i];
    return *this;
}

void Clause::agrandir(int newcapa, bool dup)
{
    if(newcapa<=capa) return;
    /*13*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
    int* tmp = new int[newcapa];
    if(dup)
    {
        for(int i=0; i<n; i++)
        {
            tmp[i] = tab[i];
        }
    }
    /*14*/printf("-tableau<%p>\n",tab);
    delete[] tab;
    tab = tmp;
}

int Clause::isin(int lit)
{
    /// A compl�ter
	int i;
	int res =0;
	for( i=0; i<n; i++) {
		if( this->tab[i] == lit ) {
			res = 1;
		}
		else if(this->tab[i] == -lit ) {
			res = -1;
		}destructeur c++
	}
	return res;
}

void Clause::affiche()
{
    /// A compl�ter
	int i;
	cout << "[" << this->tab[0] ;
	for( i=1; i<this->n; i++) {
		cout << "," << tab[i];
	}
	cout << "]" << endl;

}

void Clause::add(int lit)
{
    /// A compl�ter
	int litteral = isin(lit);
	if( litteral == -1) {
		cout << "erreur" << endl;	
	}
	else if( litteral == 1) {
	}
	else {
		if( this->n+1 >= this->capa )
			this->agrandir( n+5, true);
		this->tab[(this->n)+1] = lit;
		this->n++;
	}
}

int Clause::resolve( this, Clause * c ) {
	int i;//this
	int j;//c
	int diff=0; //nombre de diff�rence
	int m=0; // stocke le nombre de litt�raux, si !=1 return NULL
	for( i= 0; i< this->n; i++ ) {
		for( j=0; j<c->n; j++) {
			if(this->tab[i] == -c->tab[j])
				m++;
			else if(this->tab[i] != c->tab[j])
				diff++;
		}
	}
	if(m != 1 )
		return NULL;
	else 
		Clause nclause = new Clause();
	
}

int main()
{
    /// A compl�ter (pour tester vos solutions)
	cout << "--> Clause p(-1,2,-3)" << endl;
	Clause p(-1,2,-3);
	p.affiche();
	return 0;
}
