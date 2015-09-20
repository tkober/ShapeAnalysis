#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/*
 *			***CENDRILLON***CINDERELLA***ASCHENPUTTEL***
 *	
 *		Abschlussprojekt in Shape Analysis im Sommersemester 2013 & 2015
 *
 *
 *	Aufgabenstellung (kurz):
 *
 *	Implementieren Sie eine Shape Analyse mittels TVLA, die die im Quelltext vorgegebenen
 *  Verifikationsziele erfuellt.
 *  Die Verfifikationsziele sind als Milestone A bis Milestone C gekennzeichnet und sollten
 *  in dieser Reihenfolge bearbeitet werden.
 *  
 */



typedef struct verkettbare_Linse {
	int		ID;						// die Analyse kann dieses Datenfeld ignorieren
	
	bool	istGut, istSchlecht;	
	struct verkettbare_Linse *	next;
} Linse;


// DEBUG REMOVE
void topfAusgeben( Linse * topf ) {
	while(topf) {
		printf("Linse: ID = %d, istGut = %d, istSchlecht = %d\n", topf->ID, topf->istGut, topf->istSchlecht);
		topf = topf->next;
	}
}
// END OF DEBUG

int main(int argc, char *argv[]) {
	int n = 100;
	
	Linse * LinsenTopf	= NULL;				// Der unsortierte Topf, der anfangs alle Linsen enthaelt
	Linse * guteLinsen = NULL;
	Linse * schlechteLinsen = NULL;	// Je ein Topf fuer die guten und die schlechten Linsen
	
	// Der folgende Code-Block kann von der Analyse ignoriert werden.
	if (argc < 2) {
		printf("Kein Wert fuer die Anzahl der zu sortierenden Linsen angegeben. Benutze n = 100.\n");
	}
	else {
		n = atoi(argv[1]);
		if( n < 1 )
			n = 1;
		printf("Anzahl der zu sortierenden Linsen auf n = %d gesetzt.\n", n);

	}
	srand(time(NULL));	// Zufallszahlengenerator initialisieren
	// Ende des zu ignorierenden Blocks.
	
	// Einen "Topf" mit n "zufaelligen Linsen" anlegen:
	Linse * linse;
	Linse * topf;
	
	// Erste Linse in den Topf legen...
	linse				= malloc(sizeof(Linse));
	linse->ID			= 1;
	linse->istGut		= (rand() % 2) ? true : false;
	linse->istSchlecht	= !linse->istGut;	
	
	LinsenTopf			= linse;
	topf				= LinsenTopf;
	// ... jetzt die restlichen dazu legen:
	int i = 2;
	while( i <= n ) {
		linse				= malloc(sizeof(Linse));
		linse->ID			= i;
		linse->istGut		= (rand() % 2) ? true : false;
		linse->istSchlecht	= !linse->istGut;
		
		topf->next			= linse;
		topf				= linse;
		i++;
	}
	// MILESTONE C
	/*
	 * Verifikationsziel (1 Bonuspunkt):
	 *	Ein "besserer Programmierer" schlaegt die folgende, kuerzere Implementierung
	 *  fuers Fuellen des Linsentopfes vor.
	 *  Ersetzen Sie obige, bereits verifizierte Implementierung durch die kuerzere
	 *  und zeigen Sie, dass Ihre Analyse weiterhin Milestones A und B erreicht/erfuellt.
	 */
	/*
	 int i = 1;
	 while( i <= n ) {
			linse				= malloc(sizeof(Linse));
			linse->ID			= i;
			linse->istGut		= (rand() % 2) ? true : false;
			linse->istSchlecht	= !linse->istGut;
		
			linse->next			= LinsenTopf;
			LinsenTopf			= linse;
			i++;
	 }
	*/
	//
	
	// DEBUG REMOVE	
	printf("Linsentopf:\n");
	topfAusgeben(LinsenTopf);
	// END OF DEBUG
	
	// MILESTONE A
	/*
	 * Verifikationsziele (je 4 Punkte):
	 * (1) Alle Linsen befinden sich im Topf. D.h. alle Linsenobjekte sind vom Programmzeiger LinsenTopf aus erreichbar.
	 * (2) Alle Linsen haben die Eigenschaft, dass sie entweder gut oder schlecht sind. D.h. für alle Linsenobjekte gilt,
	 *     ist istGut wahr, dann ist istSchlecht falsch und umgekehrt.
	 */
	
	
	// Linsen sortieren.
	topf = LinsenTopf;
	while(topf) {
		linse	= topf;
		topf	= topf->next;
		
		if(linse->istGut) {
			linse->next = guteLinsen;
			guteLinsen  = linse;
		}
		else {
			linse->next		 = schlechteLinsen;
			schlechteLinsen  = linse;	
		}
	}
	// Ende Linsen sortieren.
	
	
	// MILESTONE B
	/*
	 * Verifikationsziele (je 4 Punkte):
	 * (1) Alle Linsen befinden sich nun in einem der beiden Toepfe fuer gute bzw. schlechte Linsen.
	 *     D.h. jedes Linsenobjekt ist entweder von Programmzeiger guteLinsen oder schlechteLinsen aus erreichbar.
	 * (2) Alle Linsen, die von guteLinsen aus erreichbar sind, haben definitive Werte für istGut und istSchlecht:
	 *	   istGut ist wahr und istSchlecht falsch fuer alle diese Linsenobjekte.
	 * (3) Alle Linsen, die von schlechteLinsen aus erreichbar sind, haben definitive Werte für istGut und istSchlecht:
	 *	   istGut ist falsch und istSchlecht wahr fuer alle diese Linsenobjekte.
	 */
	
	
	// DEBUG REMOVE	
	printf("Guter Topf:\n");
	topfAusgeben(guteLinsen);
	printf("Schlechter Topf:\n");
	topfAusgeben(schlechteLinsen);	
	// END OF DEBUG
	
	
	return 0;
}
