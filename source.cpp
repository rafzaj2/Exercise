#include<iostream>
using namespace std;



int main()
{
	void transform(char in[], const char p1[], const char p2[]);
	char in[50] = "BD{D1}BCAADEFAAGHI";
	char p1[] = "AA";
	char p2[] = "ABC";
	int i = 1;
	cout << "tablica P1: " << p1 << endl;
	cout << "tablica P2: " << p2 << endl;
	cout << "tablica glowna przed modyfikacja:	" << in << endl;
	transform(in, p1, p2);
	cout << "tablica glowna po modyfikacji:		" << in << endl << endl << endl;
	system("pause");
}





void transform(char in[], const char p1[], const char p2[])
{
	int k = 0;	  //sprawdzimy sobie gdzie się kończy string zawarty w in. Będzie się kończył w in[k]
	char *start_sekwencji;	 //to wskaźnik w którym będziemy przechowywali adres rozpoczęcia sekwencji
	int i = 0;	 	//główna zmienna potrzebna do badania zawartości stringa
	int s_1 = 0;	  //sprawdzimy sobie gdzie się kończy string zawarty w p1. Będzie się kończył w p1[s_1]
	int s_2 = 0;	  //sprawdzimy sobie gdzie się kończy string zawarty w p2. Będzie się kończył w p2[s_2]
	if (!s_1)  //**ten warunek sprawdzi gdzie kończy się string zawarty w p1
	{
		while (p1[s_1])
		{
			s_1++;
		}
	}
	if (!s_2) //**ten warunek sprawdzi gdzie kończy się string zawarty w p2
	{
		while (p2[s_2])
		{
			s_2++;
		}
	}





//**************************************************************************************************************************************************
//**Poniżej rozpoczynamy przeglądanie stringu w poszukiwaniu sekwencji określonych w zadaniu
	while (in[i])
	{
		//poczatek:
		if (!k) //**ten warunek sprawdzi sobie gdzie obecnie kończy się string, czyli gdzie jest wartość Null
		{
			while (in[k]) // poprawić wydajność
			{
				k++;
			}
		}
		start_sekwencji = &in[i];
		if (in[i] != '{') { i++; }
		else
		{
//******* Instrukcja do sekwencji typu P **********************************************************************************************************
			if (in[++i] == 'P')
			{
	//******* Instrukcja do sekwencji typu P1 ********
				if (in[++i] == '1')
				{
					if ((int)(in[++i]) < 58 && (int)(in[i]) > 47 && (int)(in[++i]) < 58 && (int)(in[i]) > 47 && in[++i] == '}')
					{
						int do_konca = (&in[k] - &in[i]);
						int dlugosc_tekstu = ((int)in[i - 1] - 48); // zmienna będzie miała wartość liczbową odpowiadającą "m" w sekwencji
						if (dlugosc_tekstu > s_1) { dlugosc_tekstu = s_1; } // tutaj się zabezpieczamy na wypadek gdy podamy "m" większe od dlugosci stringa p1
						int en_rozpoczecia = ((int)in[i - 2] - 48); // zmienna będzie miała wartość liczbową odpowiadającą "n" w sekwencji
						if (dlugosc_tekstu < 7)
						{
							for (int l = 0; l < dlugosc_tekstu; l++, start_sekwencji++)
							{
								*start_sekwencji = p1[en_rozpoczecia + l];
							}
							for (int l = 0; l < do_konca; l++, start_sekwencji++)
							{
								*start_sekwencji = in[i + l + 1];
							}

						}
						else
						{
							for (int l = 0; l < (dlugosc_tekstu - 6); l++)
							{
								in[k + dlugosc_tekstu - 6] = in[k - l];
							}
							for (int l = 0; l < dlugosc_tekstu; l++, start_sekwencji++)
							{
								*start_sekwencji = p1[en_rozpoczecia + l];
							}


						}

						k = 0; //**zerujemy adres zakońćzenia stringu, gdyż został zmodyfikowany i trzeba ustalić jego miejsce ponownie na początku głownej pętli while
						i = 0; // analogicznie, mamy nowy napis więc pracujemy ponownie od początku tego stringa
						//goto poczatek;
					}



				}
	//******* Instrukcja do sekwencji typu P2 ********
				else if (in[i] == '2')
				{
					if ((int)(in[++i]) < 58 && (int)(in[i]) > 47 && (int)(in[++i]) < 58 && (int)(in[i]) > 47 && in[++i] == '}')
					{
						int do_konca = (&in[k] - &in[i]);
						int dlugosc_tekstu = ((int)in[i - 1] - 48); // zmienna będzie miała wartość liczbową odpowiadającą "m" w sekwencji
						if (dlugosc_tekstu > s_2) { dlugosc_tekstu = s_2; } // tutaj się zabezpieczamy na wypadek gdy podamy "m" większe od dlugosci stringa p2
						int en_rozpoczecia = ((int)in[i - 2] - 48); // zmienna będzie miała wartość liczbową odpowiadającą "n" w sekwencji
						if (dlugosc_tekstu < 7)
						{
							for (int l = 0; l < dlugosc_tekstu; l++, start_sekwencji++)
							{
								*start_sekwencji = p2[en_rozpoczecia + l];
							}
							for (int l = 0; l < do_konca; l++, start_sekwencji++)
							{
								*start_sekwencji = in[i + l + 1];
							}

						}
						else
						{
							for (int l = 0; l < (dlugosc_tekstu - 6); l++)
							{
								in[k + dlugosc_tekstu - 6] = in[k - l];
							}
							for (int l = 0; l < dlugosc_tekstu; l++, start_sekwencji++)
							{
								*start_sekwencji = p2[en_rozpoczecia + l];
							}


						}

						k = 0; //**zerujemy adres zakońćzenia stringu, gdyż został zmodyfikowany i trzeba ustalić jego miejsce ponownie na początku głownej pętli while
						i = 0; // analogicznie, mamy nowy napis więc pracujemy ponownie od początku tego stringa
						//goto poczatek;
					}



				}
			}
//******* Instrukcja do sekwencji typu D **********************************************************************************************************
			else if (in[i] == 'D')
			{

				if (in[++i] == '-')
				{
					if ((int)(in[++i]) < 58 && (int)(in[i]) > 48 && in[++i] == '}')
					{
						int do_konca = (&in[k] - &in[i + 1]);
						int do_poczatku = (&in[i] - &in[0]) - 4;
						int przesuniecie = ((int)in[i - 1] - 48);
		//*************** Pętla for przepisuje string usuwając sekwencję oraz daną ilość znaków
						if (do_poczatku < przesuniecie) { przesuniecie = do_poczatku; }
						for (int l = 0; l < (przesuniecie + do_konca + 4); l++, start_sekwencji++)
						{
							*(start_sekwencji - przesuniecie) = in[i + l + 1];
						}
						k = 0;
						i = 0;
						//goto poczatek;
					}
				}


//************************** Sprawdzam czy kolena wartość tablicy jest liczbą porównując wartość rzutowania znaku z ASCII ****************
				else if ((int)(in[i]) < 58 && (int)(in[i]) > 48 && in[++i] == '}')
					{
						int do_konca = (&in[k] - &in[i + 1]);
						int przesuniecie = ((int)in[i - 1] - 48);
		//*************** Pętla for przepisuje string usuwając sekwencję oraz daną ilość znaków
						if (do_konca < przesuniecie) { przesuniecie = do_konca; }
						for (int l = 0; l < (do_konca + 3); l++, start_sekwencji++)
						{
							*start_sekwencji = in[i + l + 1 + przesuniecie];
						}
						k = 0; //**zerujemy adres zakońćzenia stringu, gdyż został zmodyfikowany i trzeba ustalić jego miejsce ponownie na początku głownej pętli while
						i = 0; // analogicznie, mamy nowy napis więc pracujemy ponownie od początku tego stringa
						//goto poczatek;
					}
			}
//******* Instrukcja do sekwencji typu R *********************************************************************************************************
			else if (in[i] == 'R')
			{
	//******* Instrukcja do sekwencji typu R1 ********
				if (in[++i] == '1')
				{
					if ((int)(in[++i]) < 58 && (int)(in[i]) > 48 && in[++i] == '}')
					{
						int do_konca = (&in[k] - &in[i + 1]);
						int zegar_poboczny = 0;//pomocniczy do zegara głównego
						int zegar_glowny = 0; //służy do liczenia ilości wystąpień napisów stringów z p1 w tablicy in
						int en_te = ((int)in[i - 1] - 48); // zmienna ma wartość parametru "n" z sekwencji
						for (int l = 0; l < do_konca ; l++)
						{
							if ((in[i + 1+ l]) == p1[zegar_poboczny])
							{
								zegar_poboczny++;
								if ((zegar_poboczny % (s_1)) == 0)
								{
									zegar_glowny++;
									zegar_poboczny = 0;
									l = (l - s_1 + 1);
									if (zegar_glowny == en_te)
					//********* A teraz usuwamy string P1 oraz wykonaną sekwencję
									{
										for (int w = 0; w < (&in[k] - &in[i + l]); w++)
										{
											in[i + l + s_1 - 1 + w ] = in[i + l + (2 * s_1) - 1 + w];
										}
										for (int w = 0; w < ((&in[k] - &in[i]) - s_1); w++, start_sekwencji++)
										{
											*start_sekwencji = in[i + 1 + w];

										}
										break;
									}

								}
							}
							else
							{
								zegar_poboczny = 0;
							}
						}
						k = 0;
						i = 0;
						//goto poczatek;
					}

				}
	//******* Instrukcja do sekwencji typu R2 ********
				else if (in[i] == '2')
				{
					if ((int)(in[++i]) < 58 && (int)(in[i]) > 48 && in[++i] == '}')
					{
						int do_konca = (&in[k] - &in[i + 1]);
						int zegar_poboczny = 0;//pomocniczy do zegara głównego
						int zegar_glowny = 0; //służy do liczenia ilości wystąpień napisów stringów z p2 w tablicy in
						int en_te = ((int)in[i - 1] - 48); // zmienna ma wartość parametru "n" z sekwencji
						for (int l = 0; l < do_konca; l++)
						{
							if ((in[i + 1 + l]) == p2[zegar_poboczny])
							{
								zegar_poboczny++;
								if ((zegar_poboczny % (s_2)) == 0)
								{
									zegar_glowny++;
									zegar_poboczny = 0;
									l = (l - s_2 + 1);
									if (zegar_glowny == en_te)
										//********* A teraz usuwamy string P2 oraz wykonaną sekwencję
									{
										for (int w = 0; w < (&in[k] - &in[i + l]); w++)
										{
											in[i + l + s_2 - 1 + w] = in[i + l + (2 * s_2) - 1 + w];
										}
										for (int w = 0; w < ((&in[k] - &in[i]) - s_2); w++, start_sekwencji++)
										{
											*start_sekwencji = in[i + 1 + w];

										}
										break;
									}

								}
							}
							else
							{
								zegar_poboczny = 0;
							}
						}
						k = 0;
						i = 0;
						//goto poczatek;
					}
				}
			}
//******* Instrukcja do sekwencji typu I *********************************************************************************************************
			else if (in[i] == 'I')
			{
	//******* Instrukcja do sekwencji typu I1 ********
				if (in[++i] == '1')
				{
				}
	//******* Instrukcja do sekwencji typu I2 ********
				else if (in[i] == '2')
				{
				}
			}
		}
	}
}
