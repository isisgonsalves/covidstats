/*My name is Isis Gonsalves and my student ID number is 816026980. 

ASSIGNMENT 2 for COMP 1601

This program will calculate make a comparison between the reference country and other countries.

Inputs: -Population, Cases, Deaths, Tests for the reference country
		-Number of countries to be compared
		-Population, Cases, Deaths, Tests for the comparing country
		
		
Outputs: -Population, Cases per million , Deaths per million, Tests per million for the reference country
		 -Population, Cases per million , Deaths per million, Tests per million for the comparing country
		 -Death percentages for all countries
		 -A graphical representation of the Deaths in each country (using a function)
		 -The country with the most cases and least deaths 

*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


void printStars (int n) //This is a Print Stars function. 
//It will output n amount of stars when the function is called.
{

	int i;
	
	for (i=1; i<=n; i=i+1) 
		cout << "*";

}


int main () {
	
	int min = INT_MAX; //to hold the minimum cases //Set to the highest possible value.
	int mindeath= INT_MAX; //to hold the minimum deaths //Set to the highest possible value.
	
	string least_count; //to hold the name of country with the least amount cases.
	string least_deathcount;//to hold the name of country with the least amount deaths.
	
	int max = INT_MIN;//to hold the maximum cases //Set to the lowest possible value.
	int maxdeath= INT_MIN;//to hold the maximum deaths //Set to the lowest possible value.
	
	string most_count; //to hold the name of country with the most amount cases.
	string most_deathcount;//to hold the name of country with the most amount deaths.
	
	
	string ref_country; //Name of the reference country
	int ref_pop; //Population of the reference country
	int ref_cases; //Amount of cases in reference country
	int ref_deaths; //Amount of deaths in reference country
	int ref_tests; //Amount of tests done in reference country
	
	
	int refcase_mil; //Cases per million in reference country 
	int refdeaths_mil;//Deaths per million in reference country 
	int refdeaths_stars;//Amount of stars to print for reference country 
	int reftests_mil;//Tests per million in reference country 
	float refdeaths_percent;//Death percentage in reference country 
	
	
	
	int numcomp; //Number of comparisons to be made
	int count;// counter for the for loop to keep track of comparisons
	
	
	
	string comp_country;//Name of country entered to be compared
	int comp_pop;//Population of country entered to be compared
	int comp_cases;//Amount of cases in the country entered to be compared
	int comp_deaths;//Amount of deaths in the country entered to be compared
	int comp_tests;//Amount of tests in the country entered to be compared
	 
	 
	
	int case_mil;//Cases per million in the country entered to be compared
	int deaths_mil;//Deaths per million in the country entered to be compared
	int comp_deaths_stars; //Amount of stars to print for the country entered 
	int tests_mil;//Tests per million in the country entered to be compared
	float deaths_percent; //Death percentage in the country entered to be compared
	
	
	
	int million ;//for calculation purposes, to avoid usuing figures and just variables
	int percent;//for calculation purposes, to avoid usuing figures and just variables
	int stars;//for calculation purposes, to avoid usuing figures and just variables
	million = 1000000;//assigned 1,000,000 
	percent = 100;//assigned 100
	stars= 50;//assigned 50
	
	
    int case_dif; //Difference in cases between comparing countries
    case_dif=0;// set to zero
 	string case_dif_words; // equal, more or less is stored here depending on difference
 	
 	int deaths_dif;//Difference in deaths between comparing countries
	deaths_dif=0; // set to zero
 	string deaths_dif_words;// equal, more or less is stored here depending on difference
 	
 	int tests_dif; //Difference in tests between comparing countries
 	tests_dif=0;// set to zero
 	string tests_dif_words;// equal, more or less is stored here depending on difference

	
	cout<< "\t\t COVID-19 STATISTICS ANALYSIS\n\n "; //Header
	cout<< "\nPlease enter the name of country that you want to be the reference: ";
	cin >> ref_country;
	cout<< "\nEnter the population of "<<ref_country<< ": ";
	cin >> ref_pop; 
	cout<< "\nEnter the total Covid-19 cases in "<<ref_country<< ": ";
	cin >> ref_cases; 
	cout<< "\nEnter the total Covid-19 deaths in "<<ref_country<< ": ";
	cin >> ref_deaths;
	cout<< "\nEnter the total Covid-19 samples tested in "<<ref_country<< ": ";
	cin >> ref_tests;  
	
	//Floor function to return the largest integer that is smaller than or equal.
	refcase_mil = (ref_cases*1.0/ref_pop)*million;//Calculating Cases per million for the reference country
	refdeaths_mil = (ref_deaths*1.0/ref_pop)* million; //Calculating Deaths per million for the reference country
	refdeaths_stars= (refdeaths_mil*1.0/stars);//Calculating Stars to output for every 50 deaths in the reference country
	reftests_mil = (ref_tests*1.0/ref_pop)* million;//Calculating Tests per million for the reference country
	refdeaths_percent = (ref_deaths*1.0/ref_pop)* percent; //Calculating Death Percent in the reference country
	
	if (refcase_mil < min)
	{
		min=refcase_mil;//to keep track of the least cases
		least_count= ref_country; //to keep track of the country with the least cases
	}
	
	if (refcase_mil > max)
	{
		max=refcase_mil;//to keep track of the most cases
		most_count= ref_country; //to keep track of the country with the most cases
	}
	
	if (refdeaths_mil < mindeath)
	{
			mindeath=refdeaths_mil;//to keep track of the least deaths
			least_deathcount= ref_country; //to keep track of the country with the least deaths 
	}
		
	if (refdeaths_mil > maxdeath)
	{
			maxdeath=refdeaths_mil;//to keep track of the most deaths
			most_deathcount= ref_country; //to keep track of the country with the most deaths
	}
	

	//Promting user for amount of comparisons to be made
	cout<<"\n\nHow many countries would you like to compare to " << ref_country<<"? :";
	cin >> numcomp; 
	
	for (count=1; count <= numcomp; count=count+1)//for loop to repeat until loop is becomes false.
	{
		cout<< "\n\n\nPlease enter the name of country that you want to compare to " <<ref_country<< ": ";
		cin >> comp_country;
		cout<< "\nEnter the population of "<<comp_country<< ": ";
		cin >> comp_pop; 
		cout<< "\nEnter the total Covid-19 cases in "<<comp_country<< ": ";
		cin >> comp_cases; 
		cout<< "\nEnter the total Covid-19 deaths in "<<comp_country<< ": ";
		cin >> comp_deaths;
		cout<< "\nEnter the total Covid-19 samples tested in "<<comp_country<< ": ";
		cin >> comp_tests; 
		
		case_mil = (comp_cases*1.0/comp_pop)* million; //Calculating Cases per million for the comparing country
		deaths_mil = (comp_deaths*1.0/comp_pop)* million; //Calculating Deaths per million for the comparing country
		comp_deaths_stars= (deaths_mil*1.0/stars);//Calculating stars per 50 deaths in the comparing country
		tests_mil = (comp_tests*1.0/comp_pop)* million; //Calculating tests per million for the comparing country
		deaths_percent = (comp_deaths*1.0/comp_pop)* percent;//Calculating Death percent in the comparing country
		
		if (case_mil > refcase_mil)//To calculate how much more cases the comparing country have
		{
			case_dif= case_mil - refcase_mil;
			case_dif_words= "more";
		}
		else
			if (case_mil < refcase_mil)//To calculate how much less cases the comparing country have
			{
				case_dif= refcase_mil - case_mil;
				case_dif_words= "less";
			}
			else//To check if the cases in both countries are equal
				{
					case_dif_words = "Equal Cases";
				}	
				
		
		if (deaths_mil > refdeaths_mil)//To calculate how much more deaths the comparing country have
		{
			deaths_dif= deaths_mil - refdeaths_mil;
			deaths_dif_words= "more";
		}
		else
			if (deaths_mil < refdeaths_mil)//To calculate how much less deaths the comparing country have
			{
				deaths_dif= refdeaths_mil - deaths_mil;
				deaths_dif_words= "less";
			}
			else//To output if there are equal deaths in both countries
				{	
					deaths_dif_words="Equal Deaths";
				}
			
			
	
		if (tests_mil > reftests_mil)//To calculate how much more tests the comparing country did
		{
			tests_dif= tests_mil - reftests_mil;
			tests_dif_words= "more";
		}
		else
			if (tests_mil < reftests_mil)//To calculate how much less tests the comparing country did
			{
				tests_dif= reftests_mil - tests_mil;
				tests_dif_words= "less";
			}
			else //To output if there are equal tests in both countries
				{
					tests_dif_words = "Equal Tests";
				}	
	

		if (case_mil < min)
		{
			min=case_mil; //to keep track of the least cases
			least_count= comp_country;  //to keep track of the country with the least cases
		}
		
		if (case_mil > max)
		{
			max=case_mil;//to keep track of the most cases
			most_count= comp_country; //to keep track of the country with the most cases
		}
		
		if (deaths_mil < mindeath)
		{
			mindeath=deaths_mil;//to keep track of the least deaths
			least_deathcount= comp_country; //to keep track of the country with the least deaths
		}
		
		if (deaths_mil > maxdeath)
		{
			maxdeath=deaths_mil;//to keep track of the most deaths
			most_deathcount= comp_country; //to keep track of the country with the most deaths
		}

	//Wordy display of comparisons 
	cout<<"\n\n\t_________________________WRITTEN  COVID-19  ANALYSIS________________________";
	cout<<"\n\t_____________________________________________________________________________";
	
	cout<< "\n\n\n\tCovid-19 Comparison between " <<comp_country<< " and " << ref_country;
	cout<<"\n\n\tPopulation of Countries: " <<comp_pop << " vs " << ref_pop;
	cout<<"\n\n\tCases per Million: "<<case_mil << " vs " << refcase_mil << " (difference: " << case_dif <<" "<< case_dif_words<<")";
	cout<<"\n\n\tDeaths per Million: "<<deaths_mil<< " vs " << refdeaths_mil<< " (difference: " << deaths_dif <<" "<< deaths_dif_words<<")";
	cout<<"\n\n\tGraphical Rep. of Deaths: ";
	printStars(comp_deaths_stars); 
	cout<< " : " ;
	printStars(refdeaths_stars);
	cout<<"\n\n\tDeath Percentages: "<<deaths_percent<< " vs " << refdeaths_percent;
	cout<<"\n\n\tTests per Million: "<<tests_mil<< " vs " << reftests_mil<< " (difference: " << tests_dif <<" "<< tests_dif_words<<")\n\n\n";
	
	
	//Tabular display of comparisons
	cout<<"\n\n\t____________________________TABULAR  COVID-19  ANALYSIS____________________________";
	cout<<"\n\t___________________________________________________________________________________\n";
	cout<<"\tCountry\t\t\t\tComparing Country\t\tReference Country\n\n";
	cout<<"\t\t\t\t\t"<<comp_country<<"\t\t\t  " <<ref_country<<"\n";
	cout<<"\t____________________________________________________________________________________\n";
	cout<<"\tPopulation\t\t\t" <<comp_pop<<"\t\t\t\t"<<ref_pop<<" \n\n";
	cout<<"\t____________________________________________________________________________________\n";
	cout<<"\tCases Per Million\t\t" <<case_mil<<"\t\t\t\t"<<refcase_mil<< "  (" << case_dif <<" "<< case_dif_words<<")"" \n\n";
	cout<<"\t____________________________________________________________________________________\n";
	cout<<"\tDeaths Per Million\t\t" <<deaths_mil<<"\t\t\t\t"<<refdeaths_mil<< "   ("<<deaths_dif <<" "<< deaths_dif_words<<")"" \n\n";
	cout<<"\t____________________________________________________________________________________\n";
	cout<<"\tGraph of Deaths\t\t\t";
	printStars(comp_deaths_stars); 
	cout<< "\t\t:\t\t " ;
	printStars(refdeaths_stars);
	cout<<"\n\n\t____________________________________________________________________________________\n";
	cout<<"\tDeath Percentage\t\t" <<deaths_percent<<"\t\t\t"<<refdeaths_percent<<" \n\n";
	cout<<"\t_____________________________________________________________________________________\n";
	cout<<"\tTests per Million\t\t" <<tests_mil<<"\t\t\t\t"<<reftests_mil<<"  (" << tests_dif <<" "<< tests_dif_words<<") \n\n";
	cout<<"\t_____________________________________________________________________________________\n";
	cout<<"\t_____________________________________________________________________________________\n\n\n";
		
	}
	
	//Display of countries with the most and least cases and the most and least Deaths.
	cout<<"\t_________________________CASES__________________________\n";
	cout<<"\n\n\tCountry with Most cases: " <<most_count<< " with "<< max <<" per million cases";
	cout<<"\n\n\tCountry with Least cases: " <<least_count<< " with "<< min <<" per million cases";
	cout<<"\n\n\t_________________________DEATHS__________________________\n";
	cout<<"\n\n\tCountry with Most deaths: " <<most_deathcount<< " with "<< maxdeath <<" per million deaths";
	cout<<"\n\n\tCountry with Least deaths: " <<least_deathcount<< " with "<< mindeath <<" per million deaths";

	cout<<"\n\n\n\n\n\t_____________________________________________________________________________________\n";
	cout<<"\t\t\t\t\tEND OF COVID ANALYSIS\n";
	cout<<"\t_____________________________________________________________________________________\n\n\n";
	
    return 0;
}
