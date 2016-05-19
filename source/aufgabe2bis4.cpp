# include <cstdlib> //std :: rand ()
# include <vector> //std :: vector < >
# include <list>   //std :: list < >
# include <iostream> //std :: cout
# include <iterator> //std :: ostream_iterator < >
# include <algorithm> //std :: reverse , std :: generate
# include <set>
# include <map>



int main ()
{

std::list<unsigned int> mist(100); //Erstellen von Liste "mist"
for (std::list <unsigned int>::iterator it = mist.begin(); it != mist.end(); ++it){
	*it = std::rand() % 100+1;
}

std::copy(std::begin(mist), std::end(mist), std::ostream_iterator<unsigned int> (std::cout, " \n"));

std::vector<unsigned int> vist(mist.size()); //Erstellen von Vektor vist mit Elementen aus mist
std::copy (std::begin(mist), std::end(mist), std::begin(vist));

std::set <unsigned int> sett(std::begin(mist), std::end(mist));
//std::copy (std::begin(mist), std::end(mist), std::begin(sett));
std::vector<unsigned int> num_not_present;

int diffcount;
for(unsigned int i=0; i<=100; ++i){ //Überprüft wie viele unterschiedluíche Zahlen in der Liste sind
	if(sett.count(i)==1){
		diffcount ++;
	}
}
std::cout << "Es gibt " << diffcount << " verschiedene Zahlen in der Liste" << "\n";
std::cout << "\n";




for(unsigned int i=0; i<=100; ++i){  //Findet Zahlen, die nicht in Liste sind
	if(sett.count(i)==0){
		num_not_present.push_back(i);
	}
}
std::cout << "Folgende Zahlen sind nicht in der Liste: " "\n";
std::copy(std::begin(num_not_present), std::end(num_not_present), std::ostream_iterator<unsigned int> (std::cout, " \n"));



std::map<unsigned int, int> count_number; //Erstellt Map zum Zählen der einzelnen Elemente
for(unsigned int i=0; i<=100; ++i){
	int manycount = 0;
	for(unsigned int k=0; k<=vist.size(); k++){ // Überprüft, ob Zahl vorkommt und setzt Zähler hoch (Prüft Elemente aus Vector)
		if(i == vist[k]){
			manycount ++;
			
		}
	}
	count_number.insert(std::make_pair(i, manycount)); // erstellt Element in Map bestehend aus Zahl i und Vorkommen dieser Zahl
    

}
std::cout << "\n";
std::cout << "Anzahl der einzelnen Elemente: " "\n";

for(auto it = count_number.begin(); it != count_number.end(); ++ it){
		std::cout << it -> first << "=>" << it -> second << "\n";
	}

return 0; // returned 0 !!!!!
}
